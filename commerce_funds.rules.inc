<?php
/**
 * @file
 *   commerce_funds.rules.inc
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_funds_rules_action_info() {
  $actions = array();

  $actions['commerce_funds_update_balance'] = array(
    'label' => t('Deposits funds into users account after the order is fully paid'),
    'parameter' => array(
      'account_user' => array(
        'type' => 'user',
        'label' => t('User'),
      ),
      'amount' => array(
        'type' => 'commerce_price',
        'label' => t('Commerce Order Amount'),
      ),
    ),
    'group' => t('Commerce Funds'),
    'callbacks' => array(
      'execute' => 'commerce_funds_update_balance',
    ),
  );

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

