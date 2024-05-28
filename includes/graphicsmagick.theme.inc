<?php
/**
 * @file
 * Theme functions for the GraphicsMagick Effects module.
 */

/**
 * Returns HTML for the summary of the image blur effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the blur effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_blur_summary(array $variables) {
  $data = $variables['data'];
  $summary = '';

  if ($data['radius']) {
    $summary = t('radius @radius', array('@radius' => $data['radius']));
  }
  if ($data['sigma']) {
    $summary .= ' ' . t('sigma @sigma', array('@sigma' => $data['sigma']));
  }

  return $summary;
}

/**
 * Returns HTML for the summary of the image emboss effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the emboss effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_emboss_summary(array $variables) {
  return theme('graphicsmagick_blur_summary', $variables);
}

/**
 * Returns HTML for the summary of the image gamma effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the gamma effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_gamma_summary(array $variables) {
  $data = $variables['data'];
  $summary = '';

  if ($data['gamma']) {
    $summary = t('gamma @gamma', array('@gamma' => $data['gamma']));
  }

  return $summary;
}

/**
 * Returns HTML for the summary of the image noise effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the noise effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_noise_summary(array $variables) {
  $data = $variables['data'];
  $options = graphicsmagick_image_noise_options();
  $summary = '';

  if ($data['noise'] && isset($options[$data['noise']])) {
    $summary = t('noise @noise', array('@noise' => $options[$data['noise']]));
  }

  return $summary;
}

/**
 * Returns HTML for the summary of the image oil paint effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the oil paint effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_oil_paint_summary(array $variables) {
  $data = $variables['data'];
  $summary = '';

  if ($data['radius']) {
    $summary = t('radius @radius', array('@radius' => $data['radius']));
  }

  return $summary;
}

/**
 * Returns HTML for the summary of the image solarize effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the solarize effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_solarize_summary(array $variables) {
  $data = $variables['data'];
  $summary = '';

  if ($data['radius']) {
    $summary = t('level @level', array('@level' => $data['level']));
  }

  return $summary;
}

/**
 * Returns HTML for the summary of the image spread effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the spread effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_spread_summary(array $variables) {
  return theme('graphicsmagick_oil_paint_summary', $variables);
}

/**
 * Returns HTML for the summary of the image swirl effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the swirl effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_swirl_summary(array $variables) {
  $data = $variables['data'];
  $summary = '';

  if ($data['degrees']) {
    $summary = t('degrees @degrees', array('@degrees' => $data['degrees']));
  }

  return $summary;
}
