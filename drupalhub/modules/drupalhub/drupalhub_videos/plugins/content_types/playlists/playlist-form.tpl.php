<form role="form" class="playlist-form disabled">

  <div class="form-group name">
    <label for="Name"><?php print t('Name: '); ?></label>
    <input type="text" class="form-control" id="name" placeholder="<?php print t('Enter name'); ?>">
  </div>

  <div class="form-group videos">
    <label for="exampleInputPassword1"><?php print t('Videos: '); ?></label>
    <input type="text" class="form-control" id="playlist-search" placeholder="<?php print t('Type name of a video'); ?>">
    <div class="autocomplete-results disabled"></div>
    <ul class="items">
    </ul>
  </div>

  <div class="form-group description">
    <label for="exampleInputPassword1"><?php print t('Description: '); ?></label>
    <textarea class="form-control" id="description"></textarea>
  </div>

  <div class="form-group access-level">
    <label for="exampleInputFile"><?php print t('Access level: '); ?></label>
    <select name="access_level" class="form-control access_level">
      <option value="1"><?php print t('Public + search'); ?></option>
      <option value="2"><?php print t('Public'); ?></option>
      <option value="3"><?php print t('Private'); ?></option>
    </select>
  </div>

  <div class="buttons">
    <button type="submit" class="btn btn-default"><?php print t('Create list'); ?></button>
  </div>
</form>