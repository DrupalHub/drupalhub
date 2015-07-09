<?php

/**
 * @file
 * Contains DrupalHubRestfulEmptyResponse
 */

class DrupalHubRestfulEmptyResponse extends RestfulException {

  /**
   * Defines the HTTP error code.
   *
   * @var int
   */
  protected $code = 201;

  /**
   * Defines the description.
   *
   * @var string
   */
  protected $description = '';
}
