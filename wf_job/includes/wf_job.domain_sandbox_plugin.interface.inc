<?php

/**
 * @file
 * WF Job Domain sandbox plugin interface.
 */

/**
 * WF Job Sandbox Domain generator interface.
 */
interface WfJobDomainSandboxPluginInterface {

  /**
   * Generates the FQDN for a sandbox.
   *
   * @param WfJob $job
   *   The job to generate the link for.
   *
   * @return string
   *   The fully qualified domain name.
   *
   * @throws WfJobDomainException
   */
  public function generateFqdn(WfJob $job);
}
