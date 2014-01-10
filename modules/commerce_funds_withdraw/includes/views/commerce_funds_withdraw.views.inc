<?php

<?php
/**
 * @file
*   commerce_funds.views.inc
*/

/**
 * Impliments hook_views_data().
*/
function commerce_funds_withdraw_views_data() {
  $data = array();

  $data['commerce_funds_withdraw_requests']['table'] = array(
    'group' => t("Withdraw Requests"),
    'title' => t("Withdraw Requests"),
    'help' => t(""),
  );
  $data['commerce_funds_withdraw_requests']['table']['base'] = array(
    'field' => 'request_id',
    'title' => 'Withdraw Requests',
    'help' => t(""),
    'weight' => 10,
  );

  $data['commerce_funds_withdraw_requests']['uid'] = array(
    'title' => t('User Uid'),
    'help' => t('The user ID.'),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User ID'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['commerce_funds_withdraw_requests']['created'] = array(
    'title' => t('Created On'),
    'help' => t('Time of creation.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['commerce_funds_withdraw_requests']['method'] = array(
    'title' => t('Withdraw Method'),
    'help' => t('The Withdraw Method.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['commerce_funds_withdraw_requests']['amount'] = array(
    'title' => t('Withdraw Amount'),
    'help' => t('The Amount of withdraw.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['commerce_funds_withdraw_requests']['status'] = array(
    'title' => t('Withdraw Status'),
    'help' => t('Withdraw Status.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'commerce_funds_status_views_handler_filter_in_operator',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['commerce_funds_withdraw_requests']['notes'] = array(
    'title' => t('Notes'),
    'help' => t('Comments.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );


  return $data;
}