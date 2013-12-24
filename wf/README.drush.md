# WF Drush commands

This module supports the following drush commands:

## wf-sql-db-create
Create a new database and user.  This command requires the root user's (or another user who has CREATE DATABASE and global GRANT privileges) credentials.  Care should be exercised when using such information on the command line.

Alternatively you can store the root user's credentials in ~/.drush/drushrc.php and ensure only you can read the file.  Below is an example code snippet to achieve this:

    <?php
      $options['db-root-user'] = 'root';
      $options['db-root-pass'] = 'changeme';
    ?>

### Security
It is not advisable to put this information in the server's global drushrc.php, as any user who can read the file can extract the mysql root user's credentials.
