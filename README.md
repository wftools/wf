# WF Tools

WF Tools is a collection of Drupal modules for building a WF management node.  The management node is standalone Drupal site that is responsible for 
coordinating deployments of code, content and config in a coordinated way between multiple environments.

## Modules
WF Tools consists of the following modules:

### WF
The base configuration feature for WF.

### WF Environment
Entity module for managing the individual environments for the site. The wf_environment_generic module is a feature which contains the recommended configuration for WF Environment.

### WF Job
Each change for the site is handled in a job which tracks the content, code and config (in code as features). wf_job_generic is a feature with a working configuration.

### WF Jenkins
Jenkins module for WF that contains many of the jenkins rules pre configured.

### WF Git
Git repository configuration for WF.

### WF Jenkins Config / WF Git Config
A pair of configuration modules, which are likely to be merged into WF Jenkins and Git respectively.

### WF SSH
Configuration of SSH key management to ensure SSH keys are properly synced.

### WF User
Contains the roles and basic permissions required for a functioning WF management node.

## Installation
It is recommended to use the [WF Example installation profile](https://drupal.org/project/wf_example) to install the WF Tools. Additional steps are required to build a complete management node.

## Development

The original development of WF was funded by [Dave Hall Consulting](http://davehall.com.au) and [Technocrat](http://technocrat.com.au).  WF Tools is maintained by Dave Hall Consulting and the community.

