<?php
/**
 * @file
 * commerce_funds.views.inc
 */

/**
 * Impliments hook_views_data().
 */
function commerce_funds_views_data() {
  $data = array();

  $data['commerce_funds_account']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all the available operations links for the account.'),
      'handler' => 'commerce_funds_handler_field_account_operations',
    ),
  );

  $data['commerce_funds_transaction']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all the available operations links for the transaction.'),
      'handler' => 'commerce_funds_handler_field_transaction_operations',
    ),
  );

  return $data;
}
