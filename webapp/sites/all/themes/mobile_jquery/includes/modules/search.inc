<?php

/**
  * Implementation of hook form alter
  */


function mobile_jquery_form_search_block_form_alter(&$form, &$form_state) {
    $form['search_block_form']['#attributes']['data-type'] = 'search';
}
