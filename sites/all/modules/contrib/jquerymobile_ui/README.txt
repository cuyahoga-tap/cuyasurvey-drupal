
Module: jQuery Mobile
Author: Jason Savino <http://drupal.org/user/411241>

Description
===========


Requirements
============
Libraries module http://drupal.org/project/libraries

Installation
============
*Module
  Copy the 'jquerymobile_ui' module directory into your Drupal
  sites/all/modules directory as usual.

*jQuery & jQuery Mobile
--------------------------------
 1. create a folder in the 'sites/all' directory name 'libraries'
 
 2. create a folder in the newly create 'sites/all/libraries' directory
     named 'jquery'
     
 3. download and extract the jquery mobile framework in the
     newly create 'sites/all/libraries' directory
     -stable: http://code.jquery.com/mobile/1.0/jquery.mobile-1.0.zip
     
 4. rename the folder 'jquery.mobile'
 
 5. download and extract minified and uncompressed version of
     the jquery framework version 1.6.4 into the newly create 
     'sites/all/libraries/jquery' directory
     -Minified: http://code.jquery.com/jquery-1.6.4.min.js
     -Incompressed: http://code.jquery.com/jquery-1.6.4.js
     
 6. create a folder in the newly create 'sites/all/libraries' directory
     named 'jquery.custom'. this will be where you can put your
     customization to the javascript and css. 
     * the module assumes these files are named jquery.custom.js
        and jquery.custom.css. however, you can use the admin settings
        page to enter other filenames if you wish.


Usage
=====

You can put the settings in your site's settings.php file. Just copy, paste and modify the following:

$conf['jquerymobile_ui_front] = '';
$conf['jquerymobile_ui_ns] = '';
$conf['jquerymobile_ui_autoInitializePage] = '';
$conf['jquerymobile_ui_subPageUrlKey] = '';
$conf['jquerymobile_ui_activePageClass] = '';
$conf['jquerymobile_ui_activeBtnClass] = '';
$conf['jquerymobile_ui_ajaxEnabled] = '';
$conf['jquerymobile_ui_hashListeningEnabled] = '';
$conf['jquerymobile_ui_defaultPageTransition] = '';
$conf['jquerymobile_ui_defaultDialogTransition] = '';
$conf['jquerymobile_ui_minScrollBack] = '';
$conf['jquerymobile_ui_loadingMessage] = '';
$conf['jquerymobile_ui_pageLoadErrorMessage'] = '';
