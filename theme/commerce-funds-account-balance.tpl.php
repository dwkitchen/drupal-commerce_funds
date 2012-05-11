<?php
/**
* @file
* Definition of commerece-funds-account-balance.tpl.php.
*/
$user = user_load($variables['uid']);

$balance = db_query("SELECT * FROM {commerce_funds_user_funds} WHERE uid='$user->uid'")->fetchAssoc();

if($balance){ ?>
    
<h3>Balance: </h3><span><?php print commerce_currency_format($balance['balance'], commerce_default_currency()); ?></span>

<?php } else{ ?>

<h3>Balance: </h3><span><?php print commerce_currency_format(0, commerce_default_currency()); ?></span>

<?php } ?>