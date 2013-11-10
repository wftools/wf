<?php

/**
 * @file
 * WF Job URL login plugin interface.
 */

/**
 * WF Job Login URL generator interface.
 */
interface WfJobUrlLoginPluginInterface {

  /**
   * Returns a one time login link for the job sandbox.
   *
   * @param WfJob $job
   *   The job to generate the link for.
   * @param string $role
   *   The name of the role to use for the login.
   *
   * @return string
   *   The login URL
   *
   * @throws WfJobUrlException
   */
  public function generateLoginLink(WfJob $job, $role = 'admin');
}
