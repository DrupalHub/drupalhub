<?php

/**
 * Migrate comments.
 */
class Comment extends DrupalHubMigrate {
  public $entityType = 'comment';
  public $bundle = 'question';

  public $csvColumns = array(
    array('id', 'ID'),
    array('node', 'Node'),
    array('body', 'Body'),
    array('uid', 'UID'),
    array('for', 'Voted for'),
    array('against', 'Voted against')
  );

  public $dependencies = array('User', 'Category');

  public function __construct() {
    parent::__construct();

    $this->addFieldMapping('nid', 'node')
      ->sourceMigration('Question');

    // TODO: Fix.
    $this->addFieldMapping('comment_body', 'body');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('User');

    // Get the users which voted against the comment and vor the comment.
    $this->addFieldMapping('for', 'for')
      ->sourceMigration(array('User'))
      ->separator('|');

    $this->addFieldMapping('against', 'against')
      ->sourceMigration(array('User'))
      ->separator('|');
  }

  public function complete($entity, $row) {
    // Vote for/against this comment.
//    $this->vote($entity->for, 'for', $entity->cid);
//    $this->vote($entity->against, 'against', $entity->cid);
  }
}
