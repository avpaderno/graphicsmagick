<?php

namespace \graphicsmagick\Utility;

/**
 * Performs color conversions.
 */
class Color {

  /**
   * Validates whether a color value is correct.
   *
   * @param string $value
   *   The string to validate.
   *
   * @return bool
   *   TRUE if the value is valid, or FALSE if it is not.
   */
  public static function validate(string $value): bool {
    try {
      $pixel = new \GmagickPixel($value);
    }
    catch (\GmagickPixelException) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Parses a color string.
   *
   * @param ?string $value
   *   The color string to parse or NULL. In the latter case, 'transparent' is
   *   used.
   * @param bool $include_alpha
   *   TRUE if the alpha channel must be included, FALSE otherwise.
   *
   * @return array
   *   An array containing the 'r', 'g', 'b', and 'a' keys.
   *
   * @throws \InvalidArgumentException
   *   The argument is not a valid color value.
   */
  public static function toRgb(?string $value, bool $include_alpha = FALSE): array {
    try {
      $pixel = new \GmagickPixel($value ?? 'transparent');
      $color = $pixel->getColor(TRUE);

      if ($include_alpha) {
        // GmagickPixel::getColor() doesn't include the alpha channel, which
        // needs to be retrieved with GmagickPixel::getColorValue().
        // \Gmagick::Gmagick::COLOR_ALPHA throws
        // "GmagickPixelException: Unknown color type" despite the constant is
        // shown from `php --rc Gmagick`. The code only works with
        // \Gmagick::COLOR_OPACITY.
        $alpha = $pixel->getColorValue(\Gmagick::COLOR_OPACITY);
        $color['a'] = intval(round(256 * $alpha));
      }
    }
    catch (\GmagickPixelException $e) {
      throw new \InvalidArgumentException("'{$value}' is not a valid color value.", 0, $e);
    }
  }

  /**
   * Converts RGB color arrays or strings to lowercase CSS notation.
   *
   * @param array|string|null $input
   *   The value to convert or NULL. If the value is an array the first three
   *   elements will be used as the red, green and blue components. If the value
   *   is NULL, 'transparent' will be instead used.
   * @param bool $include_alpha
   *   TRUE if the alpha channel must be included, FALSE otherwise.
   *
   * @return string
   *   The lowercase simple color representation of the given color.
   *
   * @throws \InvalidArgumentException
   *   The argument is not a valid color value.
   */
  public static function toHex(array|string|null $input, bool $include_alpha = FALSE): string {
    $output = '';

    if (is_null($input)) {
      $input = 'transparent';
    }

    if (is_string($input)) {
      try {
        $pixel = new \GmagickPixel($input);
        $input = $pixel->getColor(TRUE);

        if ($include_alpha) {
        // GmagickPixel::getColor() doesn't include the alpha channel, which
        // needs to be retrieved with GmagickPixel::getColorValue().
        // \Gmagick::Gmagick::COLOR_ALPHA throws
        // "GmagickPixelException: Unknown color type" despite the constant is
        // shown from `php --rc Gmagick`. The code only works with
        // \Gmagick::COLOR_OPACITY.
        $alpha = $pixel->getColorValue(\Gmagick::COLOR_OPACITY);
          $input['a'] = intval(round(256 * $alpha));
        }
      }
      catch (\GmagickPixelException $e) {
        throw new \InvalidArgumentException("'{$input}' is not a valid color value.", 0, $e);
      }
    }

    if (is_array($input)) {
      $output = '#' . sprintf(
        '%02x%02x%02x', $input['r'] ?? '', $input['g'] ?? '', $input['b'] ?? ''
      );

      if ($include_alpha && isset($input['a'])) {
        $output .= sprintf('%02x', $input['a']);
      }
    }

    return $output;
  }

}
