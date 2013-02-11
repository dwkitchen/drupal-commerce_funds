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
class CommerceFundsAccountEntityController extends DrupalCommerceEntityController {

  /**
   * Create a default payment transaction.
   *
   * @param array $values
   *   An array of values to set, keyed by property name.
   *
   * @return object
   *   A funds account object with all default fields initialized.
   */
  public function create(array $values = array()) {

    $values += array(
      'account_id' => NULL,
      'balance' => 0,
      'currency_code' => variable_get('commerce_default_currency'),
    );

    return parent::create($values);
  }

}
