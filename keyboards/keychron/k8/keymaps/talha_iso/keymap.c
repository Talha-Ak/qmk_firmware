/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 * Copyright 2020 Dimitris Mantzouranis <d3xter93@gmail.com>
 * Copyright 2022 Harrison Chan (Xelus)
 * Copyright 2022 Thomas Bowman Mørch (tbowmo)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include <lib/lib8tion/lib8tion.h>

#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer

enum layer_names {
    WIN_BASE    = 0,
    WIN_FN      = 1,
    MAC_BASE    = 2,
    MAC_FN      = 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  +--------------------------------------------------------------------------+----------------+
    | ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|????|PAUS|
    +--------------------------------------------------------------------------+------|----|----|
    |  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |SCRL|PGUP|
    +--------------------------------------------------------------------------+------|----|----|
    |  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |      | |DEL |END |PGDN|
    +--------------------------------------------------------------------  RET | +--------------+
    | CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  # |     |                |
    +--------------------------------------------------------------------------+      |----|    |
    | LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |    |
    +--------------------------------------------------------------------------+------|----|----|
    |LCTRL| LGUI| LALT |            SPACE            | RALT| RGUI | FN | RCTRL | |LFT |DWN |RGT |
    +--------------------------------------------------------------------------+----------------+
*/
    [WIN_BASE] = LAYOUT_tkl_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      KC_PSCR, KC_F24,  RGB_TOG,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,              KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                       KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_RALT, KC_RGUI, MO(1),   KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [WIN_FN] = LAYOUT_tkl_iso(
          RESET,          KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT,  KC_MUTE, KC_VOLD, KC_VOLU,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     RGB_SPI, RGB_SAI, RGB_HUI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              RGB_SPD, RGB_SAD, RGB_HUD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       RGB_VAI,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______,     RGB_RMOD,RGB_VAD, RGB_MOD
    ),
    [MAC_BASE] = LAYOUT_tkl_iso(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       _______,
        _______, XXXXXXX, _______,                   _______,                                     _______, XXXXXXX, _______, _______,     _______, _______, _______
    ),
    [MAC_FN] = LAYOUT_tkl_iso(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       _______,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______,     _______, _______, _______
    )
};

bool dip_switch_update_user(uint8_t index, bool active){
  switch(index){
    case 0:
      if(active){ // Mac/iOS mode
        layer_move(MAC_BASE);
      }
      else{ // Win/Android mode
        layer_move(WIN_BASE);
      }
      break;
    case 1:
      if(active){ //Cable mode
        // do stuff
      }
      else{ //BT mode
        // do stuff
      }
      break; 

  }
  return true;
}

void keyboard_post_init_user(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_custom_boot_anim);
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  if (get_highest_layer(layer_state) > 0) {
    if (IS_LAYER_ON(1)) {
      for (uint8_t i = led_min; i < led_max; i++) {
        if (i >= 1 && i < 13) { // F Row
          rgb_matrix_set_color(i, RGB_WHITE);
          continue;
        }
        
        switch (i) {
          case 0:
            rgb_matrix_set_color(i, RGB_ORANGE);
            break;
          case 30: // RGB_SPI
            break;
          case 31: {  // RGB_SAI
            HSV hsv = rgb_matrix_get_hsv();
            hsv.s = qadd8(hsv.s, RGB_MATRIX_SAT_STEP * 2);
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            break;
          }
          case 32: { // RGB_HUI
            HSV hsv = rgb_matrix_get_hsv();
            hsv.h = qadd8(hsv.h, RGB_MATRIX_HUE_STEP);
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            break;
          }
          case 47: // RGB_SPD
            break;
          case 48: { // RGB_SAD
            HSV hsv = rgb_matrix_get_hsv();
            hsv.s = qsub8(hsv.s, RGB_MATRIX_SAT_STEP * 2);
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            break;
          }
          case 49: { // RGB_HUD
            HSV hsv = rgb_matrix_get_hsv();
            hsv.h = qsub8(hsv.h, RGB_MATRIX_HUE_STEP);
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            break;
          }
          default:
            break;
        }
      }
    }

    if (IS_LAYER_ON(2)) {
      // 79 = L_GUI
      if (79 >= led_min && 79 < led_max) {
        rgb_matrix_set_color(79, RGB_RED);
      }
      if (83 >= led_min && 83 < led_max) {
        rgb_matrix_set_color(83, RGB_RED);
      }
    }
  }
}



