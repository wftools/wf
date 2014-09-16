<?php

/**
 * @file
 * Example WF Job Link generators.
 *
 * Handles sandbox domains, login and visit links.
 */

/**
 * WF Job Sandbox Domain generator class.
 */
class WfJobLinks implements WfJobDomainSandboxPluginInterface,
  WfJobUrlLoginPluginInterface,
  WfJobUrlVisitPluginInterface {

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
  public function generateFqdn(WfJob $job) {
    $host = wf_job_slug($job->jid);
    $dev_domain = variable_get('wf_dev_domain', 'example.com');
    return "{$host}.dev.{$dev_domain}";
  }

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
  public function generateLoginLink(WfJob $job, $role = 'admin') {
    throw new WfJobUrlException(t('Login link not implemented.'));
  }

  /**
   * Generates a link to view the site as an anonymous user.
   *
   * @param WfJob $job
   *   The job to generate the link for.
   *
   * @return string
   *   The view URL.
   *
   * @throws WfJobUrlException
   */
  public function generateVisitLink(WfJob $job) {
    $proto = variable_get('wf_sandbox_protocol', 'http');
    $fqdn = $this->generateFqdn($job);
    return "{$proto}://{$fqdn}/";
  }
}
