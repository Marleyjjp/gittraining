<?php

/**
 * @file
 * Handler for references_plugin_row_fields.
 */
class references_plugin_row_fields extends views_plugin_row_fields {

  function option_definition() {
    $options = parent::option_definition();

    $options['separator'] = array('default' => '-');

    return $options;
  }

  /**
   * Provide a form for setting options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Expand the description of the 'Inline field' checkboxes.
    $form['inline']['#description'] .= '<br>' . t("<strong>Note:</strong> In 'References' displays, all fields will be displayed inline unless an explicit selection of inline fields is made here." );
  }

  function pre_render($row) {
    // Force all fields to be inline by default.
    if (empty($this->options['inline'])) {
      $fields = $this->view->get_items('field', $this->display->id);
      $this->options['inline'] = drupal_map_assoc(array_keys($fields));
    }

    return parent::pre_render($row);
  }
}
