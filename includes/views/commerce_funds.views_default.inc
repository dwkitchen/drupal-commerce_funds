<?php
/**
 * @file
 * Views for the default funds UI.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_funds_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'commerce_funds_user_accounts';
  $view->description = '';
  $view->tag = 'Commerce Funds';
  $view->base_table = 'commerce_funds_account';
  $view->human_name = 'Commerce Funds: User Accounts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Commerce Funds: User Accounts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own transactions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Commerce Funds: Balance */
  $handler->display->display_options['fields']['balance']['id'] = 'balance';
  $handler->display->display_options['fields']['balance']['table'] = 'commerce_funds_account';
  $handler->display->display_options['fields']['balance']['field'] = 'balance';
  /* Field: Commerce Funds: Currency */
  $handler->display->display_options['fields']['currency_code']['id'] = 'currency_code';
  $handler->display->display_options['fields']['currency_code']['table'] = 'commerce_funds_account';
  $handler->display->display_options['fields']['currency_code']['field'] = 'currency_code';
  /* Field: Commerce Funds: Funds Account */
  $handler->display->display_options['fields']['account_id']['id'] = 'account_id';
  $handler->display->display_options['fields']['account_id']['table'] = 'commerce_funds_account';
  $handler->display->display_options['fields']['account_id']['field'] = 'account_id';
  $handler->display->display_options['fields']['account_id']['label'] = '';
  $handler->display->display_options['fields']['account_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['account_id']['alter']['text'] = 'View transactions';
  $handler->display->display_options['fields']['account_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['account_id']['alter']['path'] = 'user/!1/funds/[account_id]/transactions';
  $handler->display->display_options['fields']['account_id']['element_label_colon'] = FALSE;
  /* Contextual filter: Commerce Funds: User */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'commerce_funds_account';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'user/%/funds';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Funds Account';
  $handler->display->display_options['menu']['description'] = '30';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'commerce_funds_user_transactions';
  $view->description = '';
  $view->tag = 'Commerce Funds';
  $view->base_table = 'commerce_funds_transaction';
  $view->human_name = 'Commerce Funds: User Transactions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Commerce Funds: User Transactions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own transactions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Commerce Funds: Transaction Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'commerce_funds_transaction';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Commerce Funds: Transaction Amount */
  $handler->display->display_options['fields']['amount']['id'] = 'amount';
  $handler->display->display_options['fields']['amount']['table'] = 'commerce_funds_transaction';
  $handler->display->display_options['fields']['amount']['field'] = 'amount';
  /* Field: Commerce Funds: Notes */
  $handler->display->display_options['fields']['notes']['id'] = 'notes';
  $handler->display->display_options['fields']['notes']['table'] = 'commerce_funds_transaction';
  $handler->display->display_options['fields']['notes']['field'] = 'notes';
  /* Contextual filter: Commerce Funds: User Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'commerce_funds_transaction';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Commerce Funds: Funds Account */
  $handler->display->display_options['arguments']['account_id']['id'] = 'account_id';
  $handler->display->display_options['arguments']['account_id']['table'] = 'commerce_funds_transaction';
  $handler->display->display_options['arguments']['account_id']['field'] = 'account_id';
  $handler->display->display_options['arguments']['account_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['account_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['account_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['account_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['account_id']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'user/%/funds/%/transactions';
  $handler->display->display_options['menu']['title'] = 'Transactions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  $views[$view->name] = $view;

  return $views;

}