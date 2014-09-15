<?php

/**
 * @file
 * WF Job ACL plugin interface.
 */

/**
 * WF Job ACL interface.
 */
interface WfJobAcl {
  /**
   * Generates a list of users who can be owners of a job.
   *
   * @param WfJob $job
   *  The job to use when looking up lookup potential owners.
   *
   * @return array
   *  The list of potential owners for the job.
   */
  public function getOwners(WfJob $job = NULL);

  /**
   * Generates a list of potential assignees for a job.
   *
   * @param WfJob $job
   *  The job to use for looking up potential reviewers.
   * @param bool $proposed
   *  Is the job being proposed for the another environment?
   *
   * @return array
   *  The list of potential reviewers for the job.
   */
  public function getAssignees(WfJob $job, $proposed = FALSE);

  /**
   * Checks if the user has permission to perform an action.
   *
   * @param string $action
   *  The action to check.
   * @param WfJob $job
   *  The job the action is to be performed on.
   * @param int $user
   *  The id of the user to use for the access check.
   * @param string $bundle
   *  The job type to use for the check - this is only set for create.
   *
   * @return bool
   *  TRUE if the user is allowed to perform the action.
   */
  public function hasAccess($action, WfJob $job = NULL, StdClass $user, $bundle = NULL);
}
