<?php

/**
 * @file
 * Standard WF Job ACL plugin.
 */

/**
 * Standard WF Job ACL class.
 */
class WfJobAclStandard implements WfJobAcl {

  /**
   * {@inheritdoc}
   */
  public function getOwners(WfJob $job = NULL) {
    $any = array_flip($this->getUsers('edit any job job'));
    $own = array_flip($this->getUsers('edit own job job'));
    $users = $any + $own;
    return array_flip($users);
  }

  /**
   * {@inheritdoc}
   */
  public function getAssignees(WfJob $job, $proposed = FALSE) {
    global $user;

    $job_wrapper = entity_metadata_wrapper('wf_job', $job);
    $statuses = wf_job_status_load_all('machine_name');
    $status = $job_wrapper->jsid->value();

    switch ($status) {
      case $statuses['in_review']->jsid:
        $users = $this->getUsers('rewiew job before ' . $job_wrapper->eid->next_env_id->env->value());
        if (user_access('review own jobs')) {
          $users[$user->uid] = $user->name;
        }
        return $users;

      default:
        return $this->getOwners();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function hasAccess($action, WfJob $job = NULL, StdClass $user, $bundle = NULL) {
    if ('create' == $action) {
      return $this->checkAction($action, NULL, $user, $bundle);
    }
    else {
      $bundle = $job->bundle;
    }

    $job_meta = entity_metadata_wrapper('wf_job', $job);
    if (!$this->checkState($action, $job_meta, $user)) {
      return FALSE;
    }

    return $this->checkAction($action, $job_meta, $user, $bundle);
  }

  /**
   * Checks user's access to perform a particular action.
   *
   * @param string $action
   *   The action to be performed.
   *
   * @param EntityDrupalWrapper $job
   *   The job to use for the check.
   *
   * @param int $user
   *   The uid of the user to use for the access check.
   *
   * @param string $bundle
   *   The type of job - used for checking create permissions.
   *
   * @return bool
   *   TRUE if the user is allowed to perform the action.
   */
  protected function checkAction($action, EntityDrupalWrapper $job = NULL, $user, $bundle) {
    // Skip the checks for users who have access.
    if (1 === $user->uid || user_access('manage jobs', $user) || user_access('administer jobs', $user)) {
      return TRUE;
    }

    switch ($action) {
      case 'create':
        $perm = "create {$bundle} job";
        return user_access($perm, $user);

      case 'view':
      case 'visit':
        return $this->userAccess($action, $job, $user, $bundle);

      case 'assign':
      case 'change_environment':
      case 'change_owner':
      case 'change_status':
      case 'login':
      case 'start':
        $action = 'edit';
      case 'edit':
      case 'delete':
        return $this->userAccess($action, $job, $user, $bundle);

      case 'update_code':
        return user_access("update code any job {$bundle}") || (user_access("update code own job {$bundle}") && $job->owner->uid->value() == $user->uid);

      case 'propose':
        $next_env = $job->eid->next_env_id->env->value();
        $perm = "propose job for {$next_env}";
        $owner = $job->owner->value();
        return isset($owner) && $owner->uid == $user->uid && user_access($perm, $user);

      case 'to-dev':
        return user_access('return job to dev', $user);

      case 'reallocate':
        return user_access('reallocate job', $user);

      case 'review':
        $next_env = $job->eid->next_env_id->env->value();
        $perm = "rewiew job before {$next_env}";
        $assigned = $job->assigned->value();
        return isset($assigned) && $assigned->uid == $user->uid && user_access($perm, $user);
    }

    // For security reasons if nothing is mapped, should restrict access.
    return FALSE;
  }

  /**
   * Checks if an action can be performed while job is in current state.
   *
   * @param string $action
   *   The action to be performed.
   *
   * @param EntityDrupalWrapper $job
   *   The job to use for the check.
   *
   * @return bool
   *   TRUE if permitted.
   */
  protected function checkState($action, EntityDrupalWrapper $job) {
    // Allow everything when creating a new job.
    if ('create' == $action || empty($job->raw()->jid)) {
      return TRUE;
    }

    $statuses = wf_job_status_load_all('machine_name');
    $status = $job->jsid->value();
    $default_status = variable_get('wf_job_jsid_new');
    if (!$status) {
      $status = $default_status;
    }

    $env = $job->eid;
    $has_next_env = (bool) $env->next_env_id->id->value();
    $is_default_env = ($env->id->value() == wf_environment_get_default());

    switch ($action) {
      case 'start':
        return $is_default_env && $status == $default_status;

      case 'login':
        return $is_default_env && $status != $default_status;

      case 'update_code':
        $is_default_env = ($env->id->value() == wf_environment_get_default());
        $is_job_started = ($status == $statuses['started']->jsid);

        return $is_default_env && $is_job_started;

      case 'propose':
        return $has_next_env && ($status == $statuses['started']->jsid);

      case 'review':
        return $has_next_env && ($status == $statuses['in_review']->jsid);

      case 'to-dev':
        $is_completed = ($status !== variable_get('wf_job_jsid_completed'));
        return !$is_default_env && $is_completed;

      case 'reallocate':
        return $status != variable_get('wf_job_jsid_completed');

      case 'diff':
        $invalid_states = array($statuses['new']->jsid);

        return !in_array($status, $invalid_states);

      case 'visit':
        return !in_array($status, array($default_status, variable_get('wf_job_jsid_completed'))) && $has_next_env;

      case 'assign':
      case 'change_environment':
      case 'change_status':
      case 'change_owner':
      case 'delete':
      case 'edit':
      case 'view':
        return TRUE;
    }

    // For security reasons if nothing is mapped, should restrict access.
    return FALSE;
  }

  /**
   * Gets a list of users based on a permission.
   *
   * @param string $permission
   *   The permission to use to filter the users.
   *
   * @return array
   *   A list of users with the uid as the key and user as the value.
   */
  protected function getUsers($permission) {
    $query = db_select('realname', 'rn');
    $query->innerJoin('users_roles', 'ur', 'rn.uid = ur.uid');
    $query->innerJoin('role', 'r', 'r.rid = ur.rid');
    $query->innerJoin('role_permission', 'rp', 'rp.rid = r.rid');
    $users = $query->fields('rn', array('uid', 'realname'))
      ->condition('rp.permission', $permission, '=')
      ->execute()
      ->fetchAllKeyed();

    return $users;
  }

  /**
   * Checks user's access to perform an action on a job.
   *
   * @param string $action
   *   The action to be performed.
   *
   * @param EntityDrupalWrapper $job
   *   The job to use for the check.
   *
   * @param int $user
   *   The user to use for the access check.
   *
   * @param string $bundle
   *   The type of job - used for checking create permissions.
   *
   * @return bool
   *   TRUE if the user is allowed to perform the action.
   */
  protected function userAccess($action, EntityDrupalWrapper $job = NULL, $user, $bundle) {
    if ('create' == $action) {
      return user_access("create $bundle job");
    }

    $owner = $job->owner->value();

    if (NULL !== $job && isset($owner) && $owner->uid == $user->uid && user_access("$action own $bundle job", $user)) {
      return TRUE;
    }

    return user_access("$action any $bundle job", $user);
  }
}
