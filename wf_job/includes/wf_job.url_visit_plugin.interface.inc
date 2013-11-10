<?php

/**
 * @file
 * WF Job URL visit plugin interface.
 */

/**
 * WF Job Visit URL generator interface.
 */
interface WfJobUrlVisitPluginInterface {

  /**
   * Generates a link to view the site as an anonymous user.
   *
   * @param WfJob $job
   *   The job to generate the link for.
   *
   * @return string
   *   The view URL
   *
   * @throws WfJobUrlException
   */
  public function generateVisitLink(WfJob $job);
}
