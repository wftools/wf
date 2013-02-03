<?php
/**
 * @file
 * wf_git_config.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function wf_git_config_default_rules_configuration() {
  $items = array();
  $items['rules_add_user_to_gitolite_server'] = entity_import('rules_config', '{ "rules_add_user_to_gitolite_server" : {
      "LABEL" : "Add user to gitolite server",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "gitolite", "rules" ],
      "ON" : [ "user_insert" ],
      "DO" : [
        { "gitolite_user_add" : { "account" : [ "account" ], "server" : "1" } }
      ]
    }
  }');
  $items['rules_delete_ssh_key'] = entity_import('rules_config', '{ "rules_delete_ssh_key" : {
      "LABEL" : "Delete SSH Key",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "gitolite" ],
      "ON" : [ "gitolite_user_sshkey_delete" ],
      "DO" : [
        { "gitolite_sshkey_delete" : { "sshkey" : [ "sshkey" ], "server" : "1" } }
      ]
    }
  }');
  $items['rules_delete_user_from_gitolite_server'] = entity_import('rules_config', '{ "rules_delete_user_from_gitolite_server" : {
      "LABEL" : "Delete user from gitolite server",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "gitolite", "rules" ],
      "ON" : [ "user_delete" ],
      "DO" : [
        { "gitolite_delete_user" : { "account" : [ "account" ], "server" : "1" } }
      ]
    }
  }');
  $items['rules_deploy_new_pub_priv_key_pair'] = entity_import('rules_config', '{ "rules_deploy_new_pub_priv_key_pair" : {
      "LABEL" : "Deploy new public \\/ private SSH key pair",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "wf_environment", "sshid" ],
      "ON" : [ "generate_ssh_key_pair" ],
      "DO" : [
        { "wf_environment_add_user_ssh_private_key" : {
            "user" : [ "user" ],
            "environment" : "1",
            "owner" : "apache",
            "keypair" : [ "ssh-key-pair" ]
          }
        },
        { "sshid_add_user_ssh_public_key" : { "user" : [ "user" ], "keypair" : [ "ssh-key-pair" ] } }
      ]
    }
  }');
  $items['rules_sync_ssh_key'] = entity_import('rules_config', '{ "rules_sync_ssh_key" : {
      "LABEL" : "Sync SSH key",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "gitolite" ],
      "ON" : [ "gitolite_user_sshkey_insert", "gitolite_user_sshkey_update" ],
      "DO" : [
        { "gitolite_sshkey_sync" : { "sshkey" : [ "sshkey" ], "server" : "1" } }
      ]
    }
  }');
  $items['rules_update_user_in_gitolite_server'] = entity_import('rules_config', '{ "rules_update_user_in_gitolite_server" : {
      "LABEL" : "Update user in gitolite server",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "gitolite", "rules" ],
      "ON" : [ "user_update" ],
      "DO" : [
        { "gitolite_update_user" : { "account" : [ "account" ], "server" : "1" } }
      ]
    }
  }');
  return $items;
}
