(function ($) {
  if (Drupal.jsAC) {
    // Override autocomplete setStatus. See "misc/autocomplete.js".
    Drupal.jsAC.prototype.setStatus = function (status) {
      switch (status) {
        case 'begin':
          $(this.input).addClass('throbbing');
          $(this.input).closest('.autocomplete-wrapper').find('i').addClass('fa-spin');
          $(this.ariaLive).html(Drupal.t('Searching for matches...'));
          break;
        case 'cancel':
        case 'error':
        case 'found':
          $(this.input).removeClass('throbbing');
          $(this.input).closest('.autocomplete-wrapper').find('i').removeClass('fa-spin');
          break;
      }
    };
  }
  Drupal.behaviors.omegaMusicBlog = {
    attach: function (context, settings) {
      // Open all external links in a new window/tab.
      $('a').each(function() {
        var obj = this;
        if (obj.hostname != document.location.hostname) {
          obj.target = '_blank';
        }
      });
      // Expand status body field on focus.
      var bodyField = $('#block-formblock-status .field-name-field-body textarea', context);
      var defaultValue = bodyField.val();
      bodyField.focus(function() {
        $(this).animate({'rows':'5'}, 100);
      }).blur(function() {
        if ($(this).val() == defaultValue) {
          $(this).animate({'rows':'1'}, 100);
        }
      });

      // Form submit hover.
      var submit = $('.form-submit', context);
      submit.hover(function() {
        $(this).animate({'backgroundColor': '#d1344e'}, 100);
      }, function() {
        $(this).animate({'backgroundColor': '#525252'}, 'fast');
      });

      // Toggle checkbox label classes.
      var checkboxLabels = $('.form-type-checkbox label', context);
      checkboxLabels.click(function() {
        $(this).find('i').toggleClass('fa-square-o').toggleClass('fa-check-square-o');
      });

      // Toggle radio label classes.
      var radioLabels = $('.form-type-radio label', context);
      radioLabels.click(function() {
        $(this).closest('.form-radios').find('label').find('i').toggleClass('fa-circle-o').toggleClass('fa-dot-circle-o');
      });

      // Toggle top bar.
      var topBar = $('.l-top-bar', context);
      var topBarContent = $('.l-top-bar-content', context);
      var topBarToggle = $('.l-top-bar-expand .expand i', context);
      topBarToggle.click(function() {
        var opacity = topBarContent.is(':visible') ? 0 : 1;
        topBarContent.animate({'opacity': opacity}, 500);
        topBar.slideToggle('fast');
        $(this).toggleClass('fa-arrow-circle-down').toggleClass('fa-arrow-circle-up');
      });

      // Media detection in textareas.
      var textAreas = $('.field-name-field-body textarea');
      textAreas.on('input', function(e) {
        var obj = $(this);
        var media;
        var mediaRendered = $('#media-rendered');
        if (media = detectMedia(obj)) {
          renderMedia(media, obj);
          obj.closest('.form-textarea-wrapper').addClass('media-found');
        }
        else {
          obj.closest('.form-textarea-wrapper').removeClass('media-found');
          mediaRendered.remove();
        }
      });
    }
  };

  /**
   * Detect any media pasted into a textarea.
   * Currently supported media:
   *   - YouTube
   *   - Soundcloud
   *   - Vimeo
   *
   * @param obj
   *   The textarea object.
   *
   * @return string|bool
   *   The type of media if any media is detected, false otherwise.
   */
  function detectMedia(obj) {
    // Cache some values.
    var val = obj.val();
    var mediaType = false;
    // Cache media regular expressions.
    var youTubeReg = /(?:https?:\/\/)?(?:www.)?(?:youtube.com|youtu.be)(?:\/)(?:watch?v=)?([^&]+)/;
    var soundcloudReg = /https?:\/\/(soundcloud.com|snd.sc)\/(.*)/;
    var vimeoReg = /(http:\/\/|https:\/\/)?(www\.)?(vimeo\.com\/)([0-9]+)/;

    // Does the body text contain any media URL?
    if (youTubeReg.test(val)) {
      mediaType = 'youtube';
    }
    else if (soundcloudReg.test(val)) {
      mediaType = 'soundcloud';
    }
    else if (vimeoReg.test(val)) {
      mediaType = 'vimeo';
    }
    return mediaType;
  }

  /**
   * Render media.
   *
   * @param mediaType
   *   The type of media to render.
   * @param obj
   *   The textarea object beneath which we will render the media.
   */
  function renderMedia(mediaType, obj) {
    var html = '<div id="media-rendered"></div>';
    $(html).appendTo(obj.closest('.form-textarea-wrapper:not(.media-found)'));
    // Cache media regular expressions.
    var youTubeReg = /(?:https?:\/{2})?(?:w{3}\.)?youtu(?:be)?\.(?:com|be)(?:\/watch\?v=|\/)([^\s&]+)/;
    var soundcloudReg = /((http:\/\/(soundcloud\.com\/.*|soundcloud\.com\/.*\/.*|soundcloud\.com\/.*\/sets\/.*|soundcloud\.com\/groups\/.*|snd\.sc\/.*))|(https:\/\/(soundcloud\.com\/.*|soundcloud\.com\/.*\/.*|soundcloud\.com\/.*\/sets\/.*|soundcloud\.com\/groups\/.*)))/i;
    var vimeoReg = /(http:\/\/|https:\/\/)?(www\.)?(vimeo\.com\/)([0-9]+)/;
    switch (mediaType) {
      case 'youtube':
        var youTubeVideoID = obj.val().match(youTubeReg);
        var embed = '<iframe width="350" height="197" src="//www.youtube.com/embed/' + youTubeVideoID[1] + '" frameborder="0" allowfullscreen></iframe>';
        break;
      case 'soundcloud':
        var soundcloudURL = obj.val().match(soundcloudReg);
        // Initialize soundcloud app (http://soundcloud.com/you/apps).
        SC.initialize({
          client_id: Drupal.settings.musicExtras.soundcloudClientId
        });
        SC.oEmbed(soundcloudURL[1], {color: "d1344e"},  document.getElementById("media-rendered"));
        break;
      case 'vimeo':
        break;
    }
    $(embed).appendTo(obj.closest('.form-textarea-wrapper:not(.media-found)').find('#media-rendered'));
  }
})(jQuery);
