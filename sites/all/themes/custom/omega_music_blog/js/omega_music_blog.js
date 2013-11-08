(function ($) {
  Drupal.behaviors.omegaMusicBlog = {
    attach: function (context, settings) {
      // Expand status body field on focus.
      var bodyField = $('#block-formblock-status .field-name-field-body textarea', context);
      bodyField.focus(function() {
        $(this).animate({'rows':'5'}, 100);
      }).blur(function() {
        $(this).animate({'rows':'1'}, 100);
      });
    }
  };
})(jQuery);
