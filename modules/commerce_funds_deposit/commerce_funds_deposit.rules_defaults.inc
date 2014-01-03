<?php

/**
 * @file
 * Default rule configurations for License.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_funds_deposit_default_rules_configuration() {
  $rules = array();
  $rule = array();

  $rule = rules_reaction_rule();

  $rule->label = t('Activates funds deposit when the order is paid in full');
  $rule->tags = array('Commerce Funds');
  $rule->active = TRUE;

  $rule
    ->event('commerce_payment_order_paid_in_full')
    ->action('commerce_funds_credit', array(
      'account_user:select' => 'site:current-user',
      'amount:select' => 'commerce-order:commerce-order-total',
    ));

  $rules['commerce_funds_activate_funds'] = $rule;

  return $rules;
}