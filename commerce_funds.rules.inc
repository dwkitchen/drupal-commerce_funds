<?php

/**
 * @file
 * commerce_funds.rules.inc
 */

/**
 * Implements hook_rules_condition_info().
 */
function commerce_funds_rules_condition_info() {
  $condition = array();

  $condition['commerce_funds_checkout_deposit_type'] = array(
    'label' => t('Line item comparison'),
    'parameter' => array(
      'order' => array(
        'type' => 'commerce_order',
        'label' => 'Withdraw for the current user',
      ),
    ),
    'group' => t('Commerce Funds'),
    'callbacks' => array(
      'execute' => 'commerce_line_item_comparison',
    ),
  );

  return $condition;
}

/**
 * Implements hook_rules_action_info().
 */
function commerce_funds_rules_action_info() {
  $actions = array();

  $actions['commerce_funds_credit'] = array(
    'label' => t('Credit user account balance'),
    'parameter' => array(
      'account_user' => array(
        'type' => 'user',
        'label' => t('User'),
      ),
      'amount' => array(
        'type' => 'commerce_price',
        'label' => t('Amount'),
      ),
    ),
    'group' => t('Commerce Funds'),
    'callbacks' => array(
      'execute' => 'commerce_funds_credit',
    ),
  );

  $actions['commerce_funds_debit'] = array(
    'label' => t('Debit user account balance'),
    'parameter' => array(
      'account_user' => array(
        'type' => 'user',
        'label' => t('User'),
      ),
      'amount' => array(
        'type' => 'commerce_price',
        'label' => t('Amount'),
      ),
    ),
    'group' => t('Commerce Funds'),
    'callbacks' => array(
      'execute' => 'commerce_funds_debit',
    ),
  );

  return $actions;
}
