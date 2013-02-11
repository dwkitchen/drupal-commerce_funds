<?php
/**
 * @file
 *   commerce_funds.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_funds_default_rules_configuration() {

  $rules = array();
  $rule = rules_reaction_rule();

  $rule->label = t('Adds funds to balance when deposit is completed');
  $rule->active = TRUE;

  $rule->event('commerce_checkout_complete')
  ->action('commerce_funds_update_balance', array(
    'commerce_order:select' => 'commerce-order',
  ));

  $rules['commerce_funds_add_funds_to_balance'] = $rule;

  return $rules;
}
