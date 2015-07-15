# WF Tools

[WF Tools](http://wftools.org) is a collection of Drupal modules for building a WF management node.  The management node is standalone Drupal site that is responsible for 
coordinating deployments of code, content and config in a coordinated way between multiple environments.

## Modules
WF Tools consists of the following modules:

### WF
Administration forms and utility functions.

### WF Environment
Entity module for managing the individual environments for the site.

### WF Job
Each change for the site is handled in a job which tracks the content, code and config (in code as features).

### WF Log
Records WF events and activities.  This flexible logging framework can be used to track almost any activity against any entity.

### WF Storage
This simple key value store allows any arbitrary data structure to be stored in the database backend.

## Optional Modules
The following modules aren't required for running WF Tools, but they provide additional functionality.

### WF Site
Allows WF to work with multiple websites.

### WF Deploy Services Client
Integrates with the Deploy Services Client module to retrieve entity diffs from a WF managed site.

### WF Jenkins
Jenkins integration with WF.  The currently implements log streaming support.

## Installation
It is recommended to use the [WF Example installation profile](https://drupal.org/project/wf_example) to install the WF Tools. Additional steps are required to build a complete management node.

## Development

WF Tools is maintained by [Dave Hall Consulting](http://davehall.com.au) and the community.
