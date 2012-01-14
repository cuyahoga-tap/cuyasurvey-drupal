-------------------------
Overview
-------------------------

The "webapp" directory contains site code, and "db", an initial site database.

-------------------------
Installation Instructions
-------------------------

1.  Refer to webapp/INSTALL.txt file for server requirements.

2.  Copy contents under webapp to the web server's document root
    directory. Make sure .htaccess file is copied.

3.  Create a new database in MySQL.

5.  Load data from a SQL file found in the db directory into the
    new database.

6.  Copy webapp/sites/default/default.settings.php file as
    webapp/sites/default/settings.php and update the
    database connection settings (beginning line 180)
    to use the following, (replacing DB_NAME, DB_USERNAME,
    and DB_PASSWORD with info specific to your setup):

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

8.  Default Drupal administration username and password is:
    Username: 
    Password: 