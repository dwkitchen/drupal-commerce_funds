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

  // Expose the transaction amount.
  $data['commerce_funds_account']['balance'] = array(
    'title' => t('Balance'),
    'help' => t('The balance of the account.'),
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

//   $data['commerce_funds_account']['operations'] = array(
//     'field' => array(
//       'title' => t('Operations links'),
//       'help' => t('Display all the available operations links for the account.'),
//       'handler' => 'commerce_funds_handler_field_account_operations',
//     ),
//   );

  // Expose the transaction amount.
  $data['commerce_payment_transaction']['amount'] = array(
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

//   $data['commerce_funds_transaction']['operations'] = array(
//     'field' => array(
//       'title' => t('Operations links'),
//       'help' => t('Display all the available operations links for the transaction.'),
//       'handler' => 'commerce_funds_handler_field_transaction_operations',
//     ),
//   );

  return $data;
}