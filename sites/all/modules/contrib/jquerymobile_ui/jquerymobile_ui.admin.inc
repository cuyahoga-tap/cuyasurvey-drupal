<?php

/*
 * @file
 *
 */

/**
 * Form builder; Configure user settings for this site.
 *
 * @ingroup forms
 * @see system_settings_form()
 */ 
function jquerymobile_ui_admin_settings() {
/*    OPTIONS VALUES    */
  $transitions = array(
    '' => t('default'),
    'slide' => t('slide'),
    'slideup' => t('slideup'),
    'slidedown' => t('slidedown'),
    'pop' => t('pop'),
    'fade' => t('fade')
  );
  $booleans = array(
    'true' => t('True'), 
    'false' => t('False')
  );
  
/*    THEME SETTINGS    */
  $form['jquerymobile_ui']['theme_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Theme Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#access' => user_access('manage jquerymobile theme settings'),
  );
  $form['jquerymobile_ui']['theme_settings']['jquerymobile_ui_front'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Front Page - River of News'),
    '#description'   => t('If the front page the default river of news, this option will create a link list.'),
    '#default_value' => variable_get('jquerymobile_ui_front', 'true'),
  );
  $form['jquerymobile_ui']['theme_settings']['jquerymobile_ui_custom_themes'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('jquerymobile_ui_custom_themes', ''),
    '#title' => t('Custom Mobile Themes'),
    '#description' => t('Add new swatches or rename existing swatches. One per line, in <em>css_key|value</em> format, like <em>a|My Swatch</em> or <em>g|Red</em>.'),
  );
  
/*    FILE SETTINGS    */
  $form['jquerymobile_ui']['file_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('File Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#access' => user_access('manage jquerymobile files settings'),
  );
  /* jquery files   */
  $form['jquerymobile_ui']['file_settings']['jquerymobile_ui_jquery_file'] = array(
    '#type' => 'textfield',
    '#title' => t('jQuery JavaScript'),
    '#default_value' => variable_get('jquerymobile_ui_jquery_file', JQUERYMOBILE_UI_JQUERY_FILE),
    '#description' => t('Enter the filename of the jQuery JavaScript file.  Assumes "sites/all/libraries/jquery" as the path. NO leading slashes!'),
  );
  /* jquery mobile files   */
  $form['jquerymobile_ui']['file_settings']['jquerymobile_ui_plugin_js_file'] = array(
    '#type' => 'textfield',
    '#title' => t('jQuery Mobile JavaScript'),
    '#default_value' => variable_get('jquerymobile_ui_plugin_js_file', JQUERYMOBILE_UI_PLUGIN_JS_FILE),
    '#description' => t('Enter the filename of the jQuery Mobile JavaScript file. Assumes "sites/all/libraries/jquery.mobile" as path. NO leading slashes!'),
  );  
  $form['jquerymobile_ui']['file_settings']['jquerymobile_ui_plugin_structure_file'] = array(
    '#type' => 'textfield',
    '#title' => t('jQuery Mobile Structure CSS'),
    '#default_value' => variable_get('jquerymobile_ui_plugin_structure_file', JQUERYMOBILE_UI_PLUGIN_STRUCTURE_FILE),
    '#description' => t('Enter the filename of the jQuery Mobile CSS file. Assumes "sites/all/libraries/jquery.mobile" as path. NO leading slashes!'),
  ); 
  $form['jquerymobile_ui']['file_settings']['jquerymobile_ui_plugin_css_file'] = array(
    '#type' => 'textfield',
    '#title' => t('jQuery Mobile Themes CSS'),
    '#default_value' => variable_get('jquerymobile_ui_plugin_css_file', JQUERYMOBILE_UI_PLUGIN_CSS_FILE),
    '#description' => t('Enter the filename of the jQuery Mobile CSS file. Assumes "sites/all/libraries/jquery.mobile" as path. NO leading slashes!'),
  ); 
/* custom jquery mobile files   */
  $form['jquerymobile_ui']['file_settings']['jquerymobile_ui_custom_js_file'] = array(
    '#type' => 'textfield',
    '#title' => t('jQuery Mobile Custom JavaScript'),
    '#default_value' => variable_get('jquerymobile_ui_custom_js_file', JQUERYMOBILE_UI_CUSTOM_JS_FILE),
    '#description' => t('Enter the filename of your custom jQuery Mobile JavaScript file. Assumes "sites/all/libraries/jquery.custom" as path. NO leading slashes!'),
  );  
  $form['jquerymobile_ui']['file_settings']['jquerymobile_ui_custom_css_file'] = array(
    '#type' => 'textfield',
    '#title' => t('jQuery Mobile Custom CSS'),
    '#default_value' => variable_get('jquerymobile_ui_custom_css_file', JQUERYMOBILE_UI_CUSTOM_CSS_FILE),
    '#description' => t('Enter the filename of your custom jQuery Mobile CSS file. Assumes "sites/all/libraries/jquery.custom" as path. NO leading slashes!'),
  );
  
/*    ADVANCED SETTINGS    */
  $form['jquerymobile_ui']['advanced_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#access' => user_access('manage jquerymobile advanced settings'),
  );

/* ns */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_ns'] = array(
    '#type' => 'textfield',
    '#title' => t('Namespace') . ' (<em>ns</em>)',
    '#default_value' => variable_get('jquerymobile_ui_ns', ''),
    '#description' => t('The namespace used in data- attributes, for example, data-role. Can be set to anything, including a blank string which is the default. When using, it\'s clearest if you include a trailing dash, such as "mynamespace-" which maps to data-mynamespace-foo="...".<br>NOTE: if you\'re using data- namespacing, you\'ll need to manually update/override one selector in the theme CSS. The following data selectors should incorporate the namespace you\'re using:<br>.ui-mobile [data-mynamespace-role=page], .ui-mobile [data-mynamespace-role=dialog], .ui-page { ...'),
  );
/* autoInitializePage */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_autoInitializePage'] = array(
    '#type' => 'radios',
    '#title' => t('Auto Initialize Page') . ' (<em>autoInitializePage</em>)',
    '#default_value' => variable_get('jquerymobile_ui_autoInitializePage', 'true'),
    '#description' => t('When the DOM is ready, the framework should automatically call $.mobile.initializePage. If false, page will not initialize, and will be visually hidden until until $.mobile.initializePage is manually called.'),
    '#options' => $booleans,
  );
/* subPageUrlKey */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_subPageUrlKey'] = array(
    '#type' => 'textfield',
    '#title' => t('Sub Page URL Key') . ' (<em>subPageUrlKey</em>)',
    '#default_value' => variable_get('jquerymobile_ui_subPageUrlKey', 'ui-page'),
    '#description' => t('The url parameter used for referencing widget-generated sub-pages (such as those generated by nested listviews). Translates to to example.html&ui-page=subpageIdentifier. The hash segment before &ui-page= is used by the framework for making an Ajax request to the URL where the sub-page exists.'),
  );
/* activePageClass */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_activePageClass'] = array(
    '#type' => 'textfield',
    '#title' => t('Active Page Class') . ' (<em>activePageClass</em>)',
    '#default_value' => variable_get('jquerymobile_ui_activePageClass', 'ui-page-active'),
    '#description' => t('The class assigned to page currently in view, and during transitions'),
  );
/* activeBtnClass */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_activeBtnClass'] = array(
    '#type' => 'textfield',
    '#title' => t('Active Button Class') . ' (<em>activeBtnClass</em>)',
    '#default_value' => variable_get('jquerymobile_ui_activeBtnClass', 'ui-btn-active'), 
    '#description' => t('The class used for "active" button state, from CSS framework.'),
  );
/* ajaxEnabled */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_ajaxEnabled'] = array(
    '#type' => 'radios',
    '#title' => t('AJAX Enabled') . ' (<em>ajaxEnabled</em>)',
    '#default_value' => variable_get('jquerymobile_ui_ajaxEnabled', 'true'),
    '#description' => t('jQuery Mobile will automatically handle link clicks and form submissions through Ajax, when possible. If false, url hash listening will be disabled as well, and urls will load as regular http requests.'),
    '#options' => $booleans,
  );
/* linkBindingEnabled */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_linkBindingEnabled'] = array(
    '#type' => 'radios',
    '#title' => t('Link Binding Enabled') . ' (<em>linkBindingEnabled</em>)',
    '#default_value' => variable_get('jquerymobile_ui_linkBindingEnabled', 'true'),
    '#description' => t('jQuery Mobile will automatically bind the clicks on anchor tags in your document. Setting this options to false will prevent all anchor click handling including the addition of active button state and alternate link bluring. This should only be used when attempting to delegate the click management to another library or custom code.'),
    '#options' => $booleans,
  );
/* hashListeningEnabled */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_hashListeningEnabled'] = array(
    '#type' => 'radios',
    '#title' => t('Hash Listening Enabled') . ' (<em>hashListeningEnabled</em>)',
    '#default_value' => variable_get('jquerymobile_ui_hashListeningEnabled', 'true'),
    '#description' => t('jQuery Mobile will automatically listen and handle changes to the location.hash. Disabling this will prevent jQuery Mobile from handling hash changes, which allows you to handle them yourself, or simply to use simple deep-links within a document that scroll to a particular ID.'),
    '#options' => $booleans,
  );
/* pushStateEnabled */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_pushStateEnabled'] = array(
    '#type' => 'radios',
    '#title' => t('Push State Enabled') . ' (<em>pushStateEnabled</em>)',
    '#default_value' => variable_get('jquerymobile_ui_pushStateEnabled', 'true'),
    '#description' => t('Enhancement to use history.replaceState in supported browsers, to convert the hash-based Ajax URL into the full document path. Note that we <a href="http://jquerymobile.com/demos/1.0/docs/pages/page-navmodel.html">recommend</a> disabling this feature if Ajax is disabled or if extensive use of external links are used.'),
    '#options' => $booleans,
  );
/* defaultPageTransition */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_defaultPageTransition'] = array(
    '#type' => 'select',
    '#title' => t('Default Page Transition') . ' (<em>defaultPageTransition</em>)',
    '#default_value' => variable_get('jquerymobile_ui_defaultPageTransition', 'slide'),
    '#description' => t('Set the default transition for page changes that use Ajax. Set to \'none\' for no transitions by default.'),
    '#options' => $transitions,
  );
/* touchOverflowEnabled */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_touchOverflowEnabled'] = array(
    '#type' => 'radios',
    '#title' => t('Touch Overflow Enabled') . ' (<em>touchOverflowEnabled</em>)',
    '#default_value' => variable_get('jquerymobile_ui_touchOverflowEnabled', 'false'),
    '#description' => t('Enable smoother page transitions and true fixed toolbars in devices that support both the overflow: and overflow-scrolling: touch; CSS properties.'),
    '#options' => $booleans,
  );
/* defaultDialogTransition */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_defaultDialogTransition'] = array(
    '#type' => 'select',
    '#title' => t('Default Dialog Transition') . ' (<em>defaultDialogTransition</em>)',
    '#default_value' => variable_get('jquerymobile_ui_defaultDialogTransition', 'pop'),
    '#description' => t('Set the default transition for dialog changes that use Ajax. Set to \'none\' for no transitions by default.'),
    '#options' => $transitions,
  );
/* minScrollBack */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_minScrollBack'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum Scroll Back') . ' (<em>minScrollBack</em>)',
    '#default_value' => variable_get('jquerymobile_ui_loadingMessage', '150'),
    '#description' => t('Minimum scroll distance that will be remembered when returning to a page.'),
  );
/* loadingMessage */  
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_loadingMessage'] = array(
    '#type' => 'textfield',
    '#title' => t('Loading Message') . ' (<em>loadingMessage</em>)',
    '#default_value' => variable_get('jquerymobile_ui_loadingMessage', 'loading'),
    '#description' => t('Set the text that appears when a page is loading. If set to false, the message will not appear at all.'),
  );
/* pageLoadErrorMessage */
  $form['jquerymobile_ui']['advanced_settings']['jquerymobile_ui_pageLoadErrorMessage'] = array(
    '#type' => 'textfield',
    '#title' => t('Page Load Error Message') . ' (<em>pageLoadErrorMessage</em>)',
    '#default_value' => variable_get('jquerymobile_ui_pageLoadErrorMessage', 'Error Loading Page'),
    '#description' => t('Set the text that appears when a page fails to load through Ajax.'),
  );


  return system_settings_form($form);

}
