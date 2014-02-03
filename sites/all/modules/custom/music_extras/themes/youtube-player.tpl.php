<?php

/**
 * @file
 *
 * Template file for theme('media_youtube_video').
 *
 * Variables available:
 *  $uri - The media uri for the YouTube video (e.g., youtube://v/xsy7x8c9).
 *  $url - The full url including query options for the Youtube iframe.
 *  $options - An array containing the Media Youtube formatter options.
 *  $width - The width value set in Media: Youtube file display options.
 *  $height - The height value set in Media: Youtube file display options.
 *
 */

?>
<iframe width="<?php print $width; ?>" height="<?php print $height; ?>" src="<?php print $url; ?>" frameborder="0" allowfullscreen></iframe>
