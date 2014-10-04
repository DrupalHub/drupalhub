core = 7.x
api = 2

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = 3.0-rc4

projects[breakpoints][subdir] = "contrib"
projects[breakpoints][version] = 1.1

projects[calendar][subdir] = "contrib"
projects[calendar][version] = 3.4
projects[calendar][patch][] = "https://www.drupal.org/files/issues/calendar-illegal_offset-1471400-78.patch"

projects[colorbox][subdir] = "contrib"
projects[colorbox][version] = 2.8

projects[ckeditor][subdir] = "contrib"
projects[ckeditor][version] = 1.15

projects[ctools][subdir] = "contrib"
projects[ctools][path][] = "https://www.drupal.org/files/issues/ctools-combined_patch_from_n2195211-15_and_n2195471-29--n2195471-47.patch"
projects[ctools][version] = 1.4

projects[date][subdir] = "contrib"
projects[date][version] = 2.8

projects[devel][subdir] = "contrib"
projects[devel][version] = 1.5

projects[diff][subdir] = "contrib"
projects[diff][version] = 3.2

projects[email][subdir] = "contrib"
projects[email][version] = 1.3

projects[entity][subdir] = "contrib"
projects[entity][version] = 1.5

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = 1.1

projects[entityreference_prepopulate][subdir] = "contrib"
projects[entityreference_prepopulate][version] = 1.3

projects[entity_validator][download][type] = "git"
projects[entity_validator][download][url] = "https://github.com/Gizra/entity_validator.git"
projects[entity_validator][download][branch] = 7.x-1.x
projects[entity_validator][subdir] = "contrib"
projects[entity_validator][type] = "module"

projects[entity_view_count][download][type] = "git"
projects[entity_view_count][download][url] = "https://github.com/DrupalHub/entity_view_count.git"
projects[entity_view_count][download][branch] = 7.x-1.x
projects[entity_view_count][subdir] = "contrib"
projects[entity_view_count][type] = "module"

projects[features][subdir] = "contrib"
projects[features][version] = 2.2

projects[fboauth][version] = "1.6"
projects[fboauth][subdir] = contrib

projects[flag][subdir] = "contrib"
projects[flag][version] = 2.2

projects[galleryformatter][subdir] = "contrib"
projects[galleryformatter][version] = 1.3

projects[github_connect][download][type] = git
projects[github_connect][download][branch] = 7.x-1.x
projects[github_connect][download][revision] = e091c59
projects[github_connect][subdir] = contrib

projects[imagefield_crop][subdir] = contrib
projects[imagefield_crop][version] = "1.1"

projects[gravatar][version] = "1.1"
projects[gravatar][subdir] = contrib

projects[inline_devel][version] = "2.0"
projects[inline_devel][subdir] = contrib

projects[insert][version] = "1.3"
projects[insert][subdir] = contrib

projects[jquery_update][version] = "2.4"
projects[jquery_update][subdir] = contrib

projects[link][subdir] = "contrib"
projects[link][version] = 1.2

projects[libraries][subdir] = "contrib"
projects[libraries][version] = 2.2

projects[link][subdir] = "contrib"
projects[link][version] = 1.2

projects[message][version] = "1.9"
projects[message][subdir] = contrib

projects[message_ui][version] = "1.4"
projects[message_ui][subdir] = contrib

projects[message_notify][version] = "2.5"
projects[message_notify][subdir] = contrib

projects[message_subscribe][version] = "1.0-rc2"
projects[message_subscribe][subdir] = contrib

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = 1.8

projects[migrate][subdir] = "contrib"
projects[migrate][version] = 2.5

projects[migrate_extras][subdir] = "contrib"
projects[migrate_extras][version] = 2.4

projects[oauth][version] = 3.2
projects[oauth][subdir] = contrib

projects[og][subdir] = contrib
projects[og][version] = 2.7

projects[panels][version] = "3.4"
projects[panels][subdir] = contrib

projects[panels_bootstrap_layouts][version] = "3.0"
projects[panels_bootstrap_layouts][subdir] = contrib

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = 1.2

projects[picture][subdir] = "contrib"
projects[picture][version] = 2.7

projects[retina_images][subdir] = "contrib"
projects[retina_images][version] = "1.0-beta4"

projects[restful][subdir] = "contrib"
projects[restful][download][url] = "git://github.com/Gizra/restful.git"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = 2.0

projects[token][subdir] = "contrib"
projects[token][version] = 1.5

projects[twitter][version] = "5.8"
projects[twitter][subdir] = contrib

projects[video_embed_field][version] = "2.0-beta8"
projects[video_embed_field][subdir] = contrib

projects[votingapi][version] = "2.12"
projects[votingapi][subdir] = contrib

projects[vote_up_down][download][type] = "git"
projects[vote_up_down][download][url] = "https://github.com/DrupalHub/voteupdown.git"
projects[vote_up_down][download][branch] = 7.x-2.x
projects[vote_up_down][download][tag] = 0.1
projects[vote_up_down][subdir] = "contrib"
projects[vote_up_down][type] = "module"

projects[views][subdir] = "contrib"
projects[views][version] = 3.8

projects[views_bootstrap][subdir] = contrib
projects[views_bootstrap][version] = "3.1"

projects[views_bulk_operations][subdir] = contrib
projects[views_bulk_operations][version] = "3.2"

projects[views_infinite_scroll][subdir] = "contrib"
projects[views_infinite_scroll][version] = 1.1

; Themes
projects[bootstrap] = bootstrap
projects[bootstrap][version] = 3.0
projects[bootstrap][type] = "theme"

; Libraries
libraries[jquery_caret_position][download][type] = "git"
libraries[jquery_caret_position][type] = "libraries"
libraries[jquery_caret_position][download][url] = "https://github.com/wolasss/jquery-caret-position-getter.git"

libraries[font_awesome][download][type] = "file"
libraries[font_awesome][type] = "libraries"
libraries[font_awesome][download][url] = "http://fortawesome.github.io/Font-Awesome/assets/font-awesome-4.2.0.zip"

libraries[colorbox][type] = "libraries"
libraries[colorbox][download][type] = "file"
libraries[colorbox][download][url] = "https://github.com/jackmoore/colorbox/archive/1.x.zip"

libraries[ckeditor][type] = "libraries"
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.3.3/ckeditor_4.3.3_full.zip"

libraries[autopager][type] = "libraries"
libraries[autopager][download][type] = "file"
libraries[autopager][download][url] = "https://github.com/sagotsky/jquery-autopager/archive/v1.2.zip"

libraries[datepicker][type] = "libraries"
libraries[datepicker][download][type] = "file"
libraries[datepicker][download][url] = "https://github.com/eternicode/bootstrap-datepicker/zipball/1.3.0"
