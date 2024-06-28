/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] =   LAYOUT_right_ball( 
    KC_GRV   , KC_Q     , KC_W     , KC_E   , KC_R     , KC_T     ,                          KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSPC   ,
    LCTL_T(KC_ESC), KC_A, KC_S     , KC_D   , KC_F     , KC_G     ,                          KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C   , KC_V     , KC_B     ,                          KC_N     , KC_M     , KC_COMM  , MO(KC_DOT),KC_SLSH ,  RSFT_T(KC_ENT)  ,
                   KC_LALT,KC_LGUI,LCTL_T(KC_ESC) ,KC_LGUI,LT(3,KC_TAB),              TG(2), LT(1, KC_SPC),                              CW_TOGG
  ),

  [1] = LAYOUT_right_ball(
    _______ ,  G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                                     _______  , _______  , _______,    _______  , _______  , _______  ,
    _______ ,  G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0) ,                           KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT  ,  _______  , _______   ,
    _______,   QK_KB_3, QK_KB_2, QK_KB_5, QK_KB_4, _______ ,                           QK_KB_8  , QK_KB_9  , KC_BTN1  ,  _______ ,   KC_BTN2  , KC_BTN3  ,
                  _______  , _______ , _______  ,         _______  , _______  ,     _______  , _______                             , _______
  ),

  [2] = LAYOUT_right_ball(
    S(KC_8)  , S(KC_1),     S(KC_2),   S(KC_3),  S(KC_4),   S(KC_5)  ,                           S(KC_6),   S(KC_7),   S(KC_8),   S(KC_9),   S(KC_0), KC_EQL,
    KC_RBRC   , KC_1,       KC_2,      KC_3,     KC_4,      KC_5     ,                           KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    KC_BSLS  ,
    S(KC_RBRC),S(KC_MINS), KC_1     , KC_2    , KC_3     ,S(KC_BSLS),                           _______,    KC_MINS,   S(KC_MINS),_______,   _______, KC_RSFT,
                  KC_0     , KC_DOT  , _______  ,         _______  , _______  ,      _______  ,  _______                         , CW_TOGG
  ),

  [3] = LAYOUT_right_ball(
    KC_F1,    KC_F2,       KC_F3,     KC_F4,     KC_F5,    KC_F6,                      KC_F7,    KC_F8,       KC_F9,    KC_F10,      KC_F11,    KC_F12,  
    _______,  _______,     _______,  _______,     _______,  _______,                   _______,  _______,     _______,  _______,     _______,  _______,  
    _______,  _______,     _______,  _______,     _______,  _______,                   _______,  _______,     _______,  _______,     _______,  _______, 
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,     _______  , _______  ,                            QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
