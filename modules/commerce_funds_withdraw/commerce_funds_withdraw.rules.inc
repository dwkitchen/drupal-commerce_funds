<?php

/**
 * @file
 * commerce_abandoned_cart_notification.rules.inc
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_funds_withdraw_rules_action_info() {
  $actions = array();

  $actions['execute_withdraw'] = array(
    'label' => t('Execute Withdraw Functionality'),
    'parameter' => array(
      'withdraw' => array(
        'type' => 'commerce_funds_withdraw_requests',
        'label' => 'Withdraw for the current user',
      ),
    ),
    'group' => t('Commerce Funds'),
    'callbacks' => array(
      'execute' => 'commerce_funds_withdraw_action',
    ),
  );

  return $actions;
}