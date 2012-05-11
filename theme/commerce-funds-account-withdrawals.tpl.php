<?php
/**
* @file
* Definition of commerece-funds-account-withdrawals.tpl.php.
*/
$user = user_load($variables['uid']);

$transactions = db_query("SELECT * FROM {commerce_funds_withdraw_requests} WHERE uid='$user->uid' AND status='Pending Approval'");

$methods = commerce_funds_get_enabled_withdrawal_methods();

$header = array(t('Time'), t('Amount'), t('Method'), t('Status'));

$rows = array();

foreach ($transactions as $transaction) {
    $rows[] = array(
        date('d/m/Y   g:i:s A', $transaction->created), commerce_currency_format($transaction->amount, commerce_default_currency()), $methods[$transaction->method], $transaction->status
    );
}

print t('<h2>Pending Withdrawals</h2>');

print theme('table', array('header' => $header, 'rows' => $rows));

$transactions = db_query("SELECT * FROM {commerce_funds_withdraw_requests} WHERE uid='$user->uid' AND status!='Pending Approval'");

$header = array(t('Time'), t('Amount'), t('Method'), t('Status'));

$rows = array();

foreach ($transactions as $transaction) {
    $rows[] = array(
        date('d/m/Y   g:i:s A', $transaction->created), commerce_currency_format($transaction->amount, commerce_default_currency()), $methods[$transaction->method], $transaction->status == 'Declined'? $transaction->status.'<br><br>Reason: '.$transaction->notes : $transaction->status
    );
}

print t('<h2>Previous Requests</h2>');

print theme('table', array('header' => $header, 'rows' => $rows));

?>

