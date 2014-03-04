<?php
/**
 * @file
 * commerce_funds_withdraw.views.inc
 */

/**
 * Impliments hook_views_data().
 */
function commerce_funds_withdraw_views_data() {
  $data = array();

  // Expose the transaction amount.
  $data['commerce_funds_withdraw_requests']['amount'] = array(
    'title' => t('Amount'),
    'help' => t('The amount of the transaction.'),
    'field' => array(
      'handler' => 'commerce_funds_handler_field_amount',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  return $data;
}