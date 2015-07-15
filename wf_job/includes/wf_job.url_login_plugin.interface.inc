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
   * @param string $env
   *   The name of the environment. Current environment used if NULL.
   *
   * @return string
   *   The login URL
   *
   * @throws WfJobUrlException
   */
  public function generateLoginLink(WfJob $job, $env = NULL);
}
