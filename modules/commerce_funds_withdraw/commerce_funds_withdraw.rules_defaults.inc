<?php

/**
 * @file
 * Default rule configurations for License.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_funds_withdraw_default_rules_configuration() {
  $rules = array();
  $rule = array();

  $rule = rules_reaction_rule();

  $rule->label = t('Transfer approved withdraw requests to users accounts.');
  $rule->tags = array('Commerce Funds');
  $rule->active = TRUE;

  $rule
    ->event('cron')
    ->action('entity_fetch', array(
      'type' => 'user',
      'id' => '1',
      'entity_fetched:label' => 'Admin User',
      'entity_fetched:var' => 'admin_user',
    ))
    ->action('views_bulk_operations_action_load_list', array(
      'view' =>  'customers_with_approved_withdraws|default',
      'view_user:select' => 'admin-user',
      'entity_list:label' => t('Withdraws'),
      'entity_list:var' => 'withdraws',
    ));

  $loop = rules_loop(array(
    'list:select' => 'withdraws',
    'item:label' => t('Current withdraw request'),
    'item:var' => 'withdraw',
  ));

  $loop->action('execute_withdraw', array(
    'withdraw:select' => 'withdraw',
  ));

  $rule->action($loop);

  $rules['transfer_approved_withdraws_to_paypal'] = $rule;

  return $rules;
}