<?php

$plugin = array(
  'label' => t('Voting API'),
  'resource' => 'voting_api',
  'name' => 'voting_api__1_0',
  'data_provider_options' => array(
    'table_name' => 'votingapi_vote',
    'id_column' => 'vote_id',
  ),
  'description' => t('Expose the content along with the author name.'),
  'class' => 'VotingAPIDrupalHub',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
