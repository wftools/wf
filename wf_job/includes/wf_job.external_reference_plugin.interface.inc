<?php

/**
 * @file
 * WF Job URL External Reference plugin interface.
 */

/**
 * WF Job external reference URL generator interface.
 */
interface WfJobUrlExternalReferencePluginInterface {

  /**
   * Converts the external reference field into links.
   *
   * @param WFJob $job
   *   The job to create the references for.
   *
   * @return array
   *   A render array with the link/s.
   */
  public function generateExternalRef(WfJob $job);
}
