<?php

/**
 * A wrapper function for mobile_jquery_theme_get_settings().
 * 
 * @param $name
 *   The name of the setting that you want to retrieve. 
 * @param $default (optional)
 *   The name (key) of the theme that you want to fetch the
 *   setting for. Defaults to NULL.   
 * @param $theme (optional)
 *   The key (machin-readable name) of a theme. Defaults to the key of the
 *   current theme if not defined.
 *   
 * @see 
 *   mobile_jquery_theme_get_setting().
 */
function mobile_jquery_theme_get_setting($name, $theme = NULL) {
	switch($name){
		case 'exclude':
			$setting = mobile_jquery_theme_get_info($name, $theme);
			break;
		default:
		  $setting = theme_get_setting($name, $theme);
			break;
  }

  return isset($setting) ? $setting : NULL; 
}

function mobile_jquery_get_settings($theme = NULL) {

  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }
	if($theme) {
		$themes = list_themes();
    $theme_object = $themes[$theme];
	}
	return $theme_object->info['settings'];
}


function mobile_jquery_theme_get_info($setting_name, $theme = NULL) {
// If no key is given, use the current theme if we can determine it.
  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  $output = array();

  if ($theme) {
    $themes = list_themes();
    $theme_object = $themes[$theme];

    // Create a list which includes the current theme and all its base themes.
    if (isset($theme_object->base_themes)) {
      $theme_keys = array_keys($theme_object->base_themes);
      $theme_keys[] = $theme;
    }
    else {
      $theme_keys = array($theme);
    }
    foreach ($theme_keys as $theme_key) {
      if (!empty($themes[$theme_key]->info[$setting_name])) {
        $output[$setting_name] = $themes[$theme_key]->info[$setting_name];
      }
    }
  }
  
  return $output;
}



