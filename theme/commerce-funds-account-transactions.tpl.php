<?php
/**
* @file
* Definition of commerece-funds-account-transactions.tpl.php.
*/
$user = user_load($variables['uid']);

$transactions = db_query("SELECT * FROM {commerce_funds_transactions} WHERE uid='$user->uid' OR type='Transfer' AND reference=$user->uid");

$header = array(t('Time'), t('Amount'), t('Transaction Type'), t('Details'));

$rows = array();

foreach ($transactions as $transaction) {

    if ($transaction->type == 'Transfer') {
        if ($user->uid == $transaction->reference) {
            $from_user = user_load($transaction->uid);
            $rows[] = array(
                date('d/m/Y   g:i:s A', $transaction->created), commerce_currency_format($transaction->amount, commerce_default_currency()), $transaction->type, t('Transfer From: ') . $from_user->mail . '<br ><br>' . $transaction->notes
            );
        } else {
            $to_user = user_load($transaction->reference);
            $rows[] = array(
                date('d/m/Y   g:i:s A', $transaction->created), commerce_currency_format($transaction->amount, commerce_default_currency()), $transaction->type, t('Transfer to: ') . $to_user->mail . '<br ><br>' . $transaction->notes
            );
        }
    }elseif ($transaction->type == 'Escrow Payment') {
        $to_user = user_load($transaction->reference);
        $rows[] = array(
            date('d/m/Y   g:i:s A', $transaction->created), commerce_currency_format($transaction->amount, commerce_default_currency()), $transaction->type, t('Escrow allocated to: ') . $to_user->mail . '<br ><br>' . $transaction->notes
        );
    } 
    else {
        $rows[] = array(
            date('d/m/Y   g:i:s A', $transaction->created), commerce_currency_format($transaction->amount, commerce_default_currency()), $transaction->type, $transaction->notes
        );
    }
}

print theme('table', array('header' => $header, 'rows' => $rows));

?>

