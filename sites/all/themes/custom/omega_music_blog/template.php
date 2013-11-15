<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

require_once 'preprocess/preprocess.forms.php';
require_once 'preprocess/preprocess.page.php';

/**
 * Returns HTML for a feed icon.
 */
function omega_music_blog_feed_icon($variables) {
  $text = t('Subscribe to !feed-title', array('!feed-title' => $variables['title']));
  return l('', $variables['url'], array('attributes' => array('class' => array('fa', 'fa-rss'), 'title' => $text)));
}
