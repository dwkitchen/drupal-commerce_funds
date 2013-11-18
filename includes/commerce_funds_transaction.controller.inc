<?php

/**
 * @file
 * The controller for the payment transaction entity containing the CRUD operations.
 */

/**
 * The controller class for payment transactions contains methods for the
 * transaction CRUD operations. The load method is inherited from the default
 * controller.
 */
class CommerceFundsTransactionEntityController extends DrupalCommerceEntityController {

  /**
   * Create a default payment transaction.
   *
   * @param array $values
   *   An array of values to set, keyed by property name.
   *
   * @return
   *   A payment transaction object with all default fields initialized.
   */
  public function create(array $values = array()) {
    global $user;

    $values += array(
      'transaction_id' => NULL,
      'account_id' => NULL,
      'uid' => $user->uid,
      'type' => '',
      'reference' => '',
      'notes' => '',
      'amount' => 0,
      'currency_code' => variable_get('commerce_default_currency'),
      'created' => '',
    );

    return parent::create($values);
  }

  /**
   * Saves a payment transaction.
   *
   * When saving a transaction without an ID, this function will create a new
   * transaction at that time. Subsequent transactions that should be saved as
   * new revisions should set $transaction->revision to TRUE and include a log
   * string in $transaction->log.
   *
   * @param $transaction
   *   The full transaction object to save.
   * @param $transaction
   *   An optional transaction object.
   *
   * @return
   *   SAVED_NEW or SAVED_UPDATED depending on the operation performed.
   */
  public function save($transaction, DatabaseTransaction $db_transaction = NULL) {
    if (!isset($db_transaction)) {
      $db_transaction = db_transaction();
      $started_transaction = TRUE;
    }

    try {
      global $user;

      // Determine if we will be inserting a new transaction.
      $transaction->is_new = empty($transaction->transaction_id);

      // Set the timestamp fields.
      if (empty($transaction->created)) {
        $transaction->created = REQUEST_TIME;
      }

      // Round the amount to ensure it's an integer for storage.
      $transaction->amount = round($transaction->amount);

      return parent::save($transaction, $db_transaction);
    }
    catch (Exception $e) {
      if (!empty($started_transaction)) {
        $db_transaction->rollback();
        watchdog_exception($this->entityType, $e);
      }
      throw $e;
    }
  }
}
