<?php
/**
* @file
* Definition of commerece-funds-account-incoming-escrows.tpl.php.
*/
$user = user_load($variables['uid']);

global $base_url;

$transactions = db_query("SELECT * FROM {commerce_funds_transactions} WHERE reference='$user->uid' AND type='Escrow Payment'");

$header = array(t('Time'), t('Amount'), t('Payment from'), t('Details'), t('Operations'));

$rows = array();

foreach ($transactions as $transaction) {
    $from_user = user_load($transaction->uid);
    $rows[] = array(
        date('d/m/Y   g:i:s A', $transaction->created), commerce_currency_format($transaction->amount, commerce_default_currency()), $from_user->mail, '<a href="'.$base_url.'/user/funds/cancel-escrow/'.$transaction->transaction_id.'">Cancel Payment</a>', $transaction->notes
    );
}

print t('<h2>Incoming Escrows</h2>');

print theme('table', array('header' => $header, 'rows' => $rows));

?>

