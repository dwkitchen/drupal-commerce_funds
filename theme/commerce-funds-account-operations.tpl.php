<?php
/**
* @file
* Definition of commerece-funds-account-operations.tpl.php.
*/
global $base_url;
$user = user_load($variables['uid']);
?>

<ul>
    <?php if (user_access('deposit funds', $user)) { ?>

        <li><a href="<?php print $base_url . '/user/funds/deposit'; ?>">Deposit Funds</a></li>

    <?php } ?>
        
    <?php if (user_access('transfer funds', $user)) { ?>

        <li><a href="<?php print $base_url . '/user/funds/transfer'; ?>">Transfer Funds</a></li>

    <?php } ?>
        
    <?php if (user_access('create escrow payment', $user)) { ?>

        <li><a href="<?php print $base_url . '/user/funds/create-escrow'; ?>">Create Escrow Payment</a></li>

    <?php } ?>
        
    <?php if (user_access('withdraw funds', $user)) { ?>

        <li><a href="<?php print $base_url . '/user/funds/withdraw'; ?>">Withdraw Funds</a></li>

   <?php } ?>

   <?php if (user_access('manage own escrow payment', $user)) { ?>

        <li><a href="<?php print $base_url . '/user/funds/escrow-payments'; ?>">Manage Escrow Payments</a></li>

   <?php } ?>
        
   <?php if (user_access('withdraw funds', $user)) { ?>

        <li><a href="<?php print $base_url . '/user/funds/manage/withdrawal-methods'; ?>">Configure Withdrawal Methods</a></li>

   <?php } ?>
        
  <?php if (user_access('withdraw funds', $user)) { ?>

        <li><a href="<?php print $base_url . '/user/funds/withdrawals'; ?>">Withdrawal Requests</a></li>

   <?php } ?>

   <?php if (user_access('view own transactions', $user)) { ?>

        <li><a href="<?php print $base_url . '/user/funds/transactions'; ?>">View Transactions</a></li>

   <?php } ?>
</ul>