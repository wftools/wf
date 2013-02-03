<?php
/**
 * @file
 * wf_jenkins_config.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function wf_jenkins_config_default_rules_configuration() {
  $items = array();
  $items['rules_commenced_code_update'] = entity_import('rules_config', '{ "rules_commenced_code_update" : {
      "LABEL" : "Commenced code update",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "wf_jenkins" ],
      "ON" : [ "wf_jenkins_start_update_code" ],
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "owner:mail" ] } } ],
      "DO" : [
        { "mail" : {
            "to" : "[owner:mail], [assigned:mail]",
            "subject" : "Code update commenced for Job [job:jid]: [job:title]",
            "message" : "A code update has commenced for \\u003Ca href=\\u0022[site:url]job\\/[job:jid]\\u0022\\u003E[job:title]\\u003C\\/a\\u003E.\\r\\n\\r\\nYou will receive another email when the code update completes.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_completed_code_update'] = entity_import('rules_config', '{ "rules_completed_code_update" : {
      "LABEL" : "Completed code update",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "wf_jenkins" ],
      "ON" : [ "wf_jenkins_updated_code" ],
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "owner:mail" ] } } ],
      "DO" : [
        { "mail" : {
            "to" : "[owner:mail], [assigned:mail]",
            "subject" : "Code updated for job [job:jid]: [job:title]",
            "message" : "The code for job \\u003Ca href=\\u0022[site:url]job\\/[job:jid]\\u0022\\u003E[job:title]\\u003C\\/a\\u003E has been updated.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_create_sandbox'] = entity_import('rules_config', '{ "rules_create_sandbox" : {
      "LABEL" : "Create sandbox",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "jenkins", "wf_job" ],
      "ON" : [ "wf_job_insert" ],
      "DO" : [
        { "jenkins_request" : {
            "path" : "job\\/create-branch\\/buildWithParameters",
            "query" : "\\u003Cquery\\u003E\\u003CGIT_BRANCH\\u003E\\u003C![CDATA[job[wf-job:jid]]]\\u003E\\u003C\\/GIT_BRANCH\\u003E\\u003C\\/query\\u003E",
            "method" : "GET",
            "data" : "\\u003Cdata\\u003E\\u003C\\/data\\u003E",
            "headers" : "\\u003Cheaders\\u003E\\u003C\\/headers\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_delete_sandbox'] = entity_import('rules_config', '{ "rules_delete_sandbox" : {
      "LABEL" : "Delete Sandbox",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "jenkins", "wf_job" ],
      "ON" : [ "wf_job_delete" ],
      "DO" : [
        { "jenkins_request" : {
            "path" : "job\\/delete-sandbox\\/buildWithParameters",
            "query" : "\\u003Cquery\\u003E\\u003CTARGET_NAME\\u003E\\u003C![CDATA[job[wf-job:jid]]]\\u003E\\u003C\\/TARGET_NAME\\u003E\\u003C\\/query\\u003E",
            "method" : "GET",
            "data" : "\\u003Cdata\\u003E\\u003C\\/data\\u003E",
            "headers" : "\\u003Cheaders\\u003E\\u003C\\/headers\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_job_approved'] = entity_import('rules_config', '{ "rules_job_approved" : {
      "LABEL" : "Job approved",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "wf_job" ],
      "ON" : [ "wf_job_approved" ],
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "owner:mail" ] } } ],
      "DO" : [
        { "mail" : {
            "to" : "[owner:mail]",
            "subject" : "Job approved for [next-environment:env]: [job:title]",
            "message" : "The job \\u003Ca href=\\u0022[site:url]job\\/[job:jid]\\u0022\\u003E[job:title]\\u003C\\/a\\u003E has been approved for [next-environment:env].\\r\\n\\r\\nDeployment to that environment will commence shortly. You will be notified once the deployment has completed.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_job_completed'] = entity_import('rules_config', '{ "rules_job_completed" : {
      "LABEL" : "Job completed",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "jenkins", "wf_job" ],
      "ON" : [ "wf_job_completed" ],
      "DO" : [
        { "jenkins_request" : {
            "path" : "job\\/delete-sandbox\\/buildWithParameters",
            "query" : "\\u003Cquery\\u003E\\u003CTARGET_NAME\\u003E\\u003C![CDATA[job[job:jid]]]\\u003E\\u003C\\/TARGET_NAME\\u003E\\u003C\\/query\\u003E",
            "method" : "GET",
            "data" : "\\u003Cdata\\u003E\\u003C\\/data\\u003E",
            "headers" : "\\u003Cheaders\\u003E\\u003C\\/headers\\u003E"
          }
        },
        { "jenkins_request" : {
            "path" : "job\\/sync-dr\\/build",
            "query" : "\\u003Cquery\\u003E\\u003C\\/query\\u003E",
            "method" : "GET",
            "data" : "\\u003Cdata\\u003E\\u003C\\/data\\u003E",
            "headers" : "\\u003Cheaders\\u003E\\u003C\\/headers\\u003E"
          }
        },
        { "jenkins_request" : {
            "path" : "job\\/prod-snapshot\\/build",
            "query" : "\\u003Cquery\\u003E\\u003C\\/query\\u003E",
            "method" : "GET",
            "data" : "\\u003Cdata\\u003E\\u003C\\/data\\u003E",
            "headers" : "\\u003Cheaders\\u003E\\u003C\\/headers\\u003E"
          }
        },
        { "jenkins_request" : {
            "path" : "job\\/prod-archive\\/buildWithParameters",
            "query" : "\\u003Cquery\\u003E\\u003CREFERENCE\\u003E\\u003C![CDATA[job[job:jid]]]\\u003E\\u003C\\/REFERENCE\\u003E\\u003C\\/query\\u003E",
            "method" : "GET",
            "data" : "\\u003Cdata\\u003E\\u003C\\/data\\u003E",
            "headers" : "\\u003Cheaders\\u003E\\u003C\\/headers\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_job_deployed'] = entity_import('rules_config', '{ "rules_job_deployed" : {
      "LABEL" : "Job deployed",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "wf_job" ],
      "ON" : [ "wf_job_deployed" ],
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "owner:mail" ] } } ],
      "DO" : [
        { "mail" : {
            "to" : "[owner:mail]",
            "subject" : "Job deployed to [environment:env]: [job:title]",
            "message" : "The job \\u003Ca href=\\u0022[site:url]job\\/[job:jid]\\u0022\\u003E[job:title]\\u003C\\/a\\u003E has been deployed to [environment:env].",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_job_proposed'] = entity_import('rules_config', '{ "rules_job_proposed" : {
      "LABEL" : "Job proposed",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "wf_job" ],
      "ON" : [ "wf_job_proposed" ],
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "assigned:mail" ] } } ],
      "DO" : [
        { "mail" : {
            "to" : "[assigned:mail]",
            "subject" : "Job proposed for [next-environment:env]: [job:title]",
            "message" : "The job \\u003Ca href=\\u0022[site:url]job\\/[job:jid]\\u0022\\u003E[job:title]\\u003C\\/a\\u003E has been proposed for [next-environment:env], and has been assigned to you for review.\\r\\n",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : {
            "message" : "[assigned:field-full-name] has been notified.",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  $items['rules_propogate_job'] = entity_import('rules_config', '{ "rules_propogate_job" : {
      "LABEL" : "Propogate Job",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "jenkins", "wf_job" ],
      "ON" : [ "wf_job_approved" ],
      "DO" : [
        { "jenkins_request" : {
            "path" : "job\\/merge-branch\\/buildWithParameters",
            "query" : "\\u003Cquery\\u003E\\u003CJOB\\u003E\\u003C![CDATA[job[job:jid]]]\\u003E\\u003C\\/JOB\\u003E\\u003CSOURCE_ENV\\u003E\\u003C![CDATA[[environment:drush-alias]]]\\u003E\\u003C\\/SOURCE_ENV\\u003E\\u003CTARGET_ENV\\u003E\\u003C![CDATA[[next-environment:drush-alias]]]\\u003E\\u003C\\/TARGET_ENV\\u003E\\u003C\\/query\\u003E",
            "method" : "GET",
            "data" : "\\u003Cdata\\u003E\\u003C\\/data\\u003E",
            "headers" : "\\u003Cheaders\\u003E\\u003C\\/headers\\u003E"
          }
        }
      ]
    }
  }');
  return $items;
}
