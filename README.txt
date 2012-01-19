-------------------------
Overview
-------------------------

This is a Drupal-based web site/app. This codebase requires a database to store
site content and configuration. Use a pre-loaded database we offer, or install
from scratch (not as useful, out of the "box".) 


-------------------------
Installation Instructions
-------------------------

1.  Refer to INSTALL.txt or http://drupal.org/requirements for system
    requirements.

2.  Clone into a web-accessible directory.

3.  Create a new database in MySQL.

4.  Load data from provided DB into the new database.

5.  Copy webapp/sites/default/default.settings.php file as
    webapp/sites/default/settings.php and update the database connection
    settings (beginning line 180) to use the following, (replacing DB_NAME,
    DB_USERNAME, and DB_PASSWORD with info specific to your setup):

    $databases = array (
      'default' =>
      array (
        'default' =>
        array (
          'database' => 'DB_NAME',
          'username' => 'DB_USERNAME',
          'password' => 'DB_PASSWORD',
          'host' => 'localhost',
          'port' => '',
          'driver' => 'mysql',
          'prefix' => '',
        ),
      ),
    );

6.  Default Drupal administration username and password is:
    Username: 
    Password: 
