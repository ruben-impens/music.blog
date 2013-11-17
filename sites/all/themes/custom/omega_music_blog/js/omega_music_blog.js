(function ($) {
  Drupal.behaviors.omegaMusicBlog = {
    attach: function (context, settings) {
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
        $(this).toggleClass('fa-square-o').toggleClass('fa-check-square-o');
      });
      // Toggle radio label classes.
      var radioLabels = $('.form-type-radio label', context);
      radioLabels.click(function() {
        $(this).closest('.form-radios').find('label').toggleClass('fa-circle-o').toggleClass('fa-dot-circle-o');
      });
    }
  };
})(jQuery);
