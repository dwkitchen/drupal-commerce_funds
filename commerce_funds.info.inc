<?php

/**
 * @file
 * Provides metadata for the commerce funds account and transaction entities.
 */

/**
 * Implements hook_entity_property_info().
 */
function commerce_funds_entity_property_info() {
  $info = array();

  // Add meta-data about the basic commerce_product properties.
  $account_properties = &$info['commerce_funds_account']['properties'];

  $account_properties['id'] = array(
    'label' => t('Commerce funds account ID'),
    'description' => t('The internal numeric ID of the commerce funds account.'),
    'type' => 'integer',
    'schema field' => 'account_id',
  );

  $account_properties['uid'] = array(
    'label' => t('Creator ID'),
    'type' => 'user',
    'description' => t('The unique ID of the commerce recurring entity creator.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_funds entities',
    'schema field' => 'uid',
  );

  $account_properties['currency_code'] = array(
    'label' => t('Currency'),
    'description' => t('The currency of the account.'),
    'type' => 'text',
    'schema field' => 'currency_code',
  );

  // Add meta-data about the basic commerce_product properties.
  $transaction_properties = &$info['commerce_funds_transaction']['properties'];

  $transaction_properties['id'] = array(
    'label' => t('Commerce funds transaction ID'),
    'description' => t('The internal numeric ID of the commerce funds transaction.'),
    'type' => 'integer',
    'schema field' => 'transaction_id',
  );

  $transaction_properties['uid'] = array(
    'label' => t('Creator ID'),
    'type' => 'user',
    'description' => t('The unique ID of the commerce recurring entity creator.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_funds entities',
    'schema field' => 'uid',
  );

  $transaction_properties['account_id'] = array(
    'label' => t('Commerce funds account ID'),
    'description' => t('The internal numeric ID of the commerce funds account.'),
    'type' => 'commerce_funds_account',
    'schema field' => 'account_id',
  );

  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The type of the commerce funds transaction.'),
    'type' => 'token',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_recurring entities',
    'required' => TRUE,
    'schema field' => 'type',
  );

  $transaction_properties['reference'] = array(
    'label' => t('Reference data'),
    'description' => t('In case of a transfer transaction this field will hold the user id of the destination user, same for escrow payment transactions.'),
    'type' => 'text',
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'schema field' => 'reference',
  );

  $transaction_properties['created'] = array(
    'label' => t('Created'),
    'description' => t('Time of creation.'),
    'type' => 'date',
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_recurring entities',
    'schema field' => 'created',
  );

  $transaction_properties['currency_code'] = array(
    'label' => t('Currency'),
    'description' => t('The currency of the account.'),
    'type' => 'text',
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'schema field' => 'currency_code',
  );

  $transaction_properties['notes'] = array(
    'label' => t('Notes'),
    'description' => t('Comments.'),
    'type' => 'text',
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'schema field' => 'notes',
  );

  // Add meta-data about the basic commerce_funds_withdraw properties.
  $withdraw_properties = &$info['commerce_funds_withdraw_requests']['properties'];

  $withdraw_properties['request_id'] = array(
    'label' => t('Commerce funds withdraw ID'),
    'description' => t('The internal numeric ID of the commerce funds withdraws.'),
    'type' => 'integer',
    'schema field' => 'request_id',
  );

  $withdraw_properties['uid'] = array(
    'label' => t('Creator ID'),
    'type' => 'user',
    'description' => t('The unique ID of the commerce recurring entity creator.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_funds entities',
    'schema field' => 'uid',
  );

  $withdraw_properties['created'] = array(
    'label' => t('Created'),
    'description' => t('Time of creation.'),
    'type' => 'date',
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer commerce_recurring entities',
    'schema field' => 'created',
  );

  $withdraw_properties['method'] = array(
    'label' => t('Payment Method'),
    'description' => t('The currency of the account.'),
    'type' => 'text',
    'schema field' => 'method',
  );

  $withdraw_properties['currency_code'] = array(
    'label' => t('Currency'),
    'description' => t('The currency of the account.'),
    'type' => 'text',
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'schema field' => 'currency_code',
  );

  $withdraw_properties['status'] = array(
    'label' => t('Status'),
    'description' => t('The status of the withdraw request.'),
    'options list' => 'commerce_funds_withdraw_requests',
    'type' => 'text',
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'options list' => 'commerce_funds_withdraw_status_options',
    'schema field' => 'status',
  );

  $withdraw_properties['notes'] = array(
    'label' => t('Notes'),
    'description' => t('Notes for the withdraw request.'),
    'type' => 'text',
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'schema field' => 'notes',
  );

  return $info;
}
