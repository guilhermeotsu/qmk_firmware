/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#define SP_NUM LT(_NAV, KC_SPC)
#define Z_MOUSE LT(_MOUSE,KC_Z)
#define SL_FUN LT(_FUN, KC_SLSH)
#define TB_TIL LT(_TIL, KC_TAB)
#define ENT_SYM LT(_SYM, KC_ENT)
#define BSP_NUM LT(_NUMBER, KC_BSPC)

#define GUI_A LGUI_T(KC_A)
#define GUI_S LGUI_T(KC_SCLN)
#define ALT_S LALT_T(KC_S)
#define ALT_L LALT_T(KC_L)
#define CTR_D CTL_T(KC_D)
#define CTR_K CTL_T(KC_K)
#define SFT_F SFT_T(KC_F)
#define SFT_J SFT_T(KC_J)

enum charybdis_keymap_layers {
    _BASE = 0,
    _NAV,
    _NUMBER,
    _MOUSE,
    _SYM,
    _FUN,
    _TIL
};

void tg_function_layer(keyrecord_t *record, uint16_t key, uint16_t lay, void (*toggle_fn)(bool)){
    // Tap send the key
    // Hold active layer and execute the function passed in toggle_fn
    // Didn't do this with tap dance because I don't have memory enough
    if (record->event.pressed) {
        if(record->tap.count == 0) {
            toggle_fn(true);
            layer_on(lay);
        } else {
            register_code(key);
        }
    } else {
        if (record->tap.count == 0) {
            toggle_fn(false);
            layer_off(lay);
        } else {
            unregister_code(key);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t press = XXXXXXX;
  switch(keycode) {
      case SP_NUM:
          press = KC_SPC;
          tg_function_layer(record, press, _NAV, charybdis_set_pointer_dragscroll_enabled);
          return false;
      case SL_FUN:
          press = KC_SLSH;
          tg_function_layer(record, press, _FUN, charybdis_set_pointer_dragscroll_enabled);
          return false;
      case Z_MOUSE:
          press = KC_Z;
          tg_function_layer(record, press, _MOUSE, charybdis_set_pointer_sniping_enabled);
          return false;
  }

  if (record->event.pressed) {
    register_code16(press);
  } else {
    unregister_code16(press);
  }

  return true;
}


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          GUI_A,   ALT_S,   CTR_D,   SFT_F,   KC_G,       KC_H,    SFT_J,   CTR_K,   ALT_L,   GUI_S,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          Z_MOUSE,   KC_X,   KC_C,    KC_V,    KC_B,       KC_N,     KC_M,   KC_COMM, KC_DOT,  SL_FUN,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_ESC,  SP_NUM,    TB_TIL,      ENT_SYM, BSP_NUM
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NAV] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_RSFT, XXXXXXX,    KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX,   KC_HOME, KC_END, XXXXXXX, KC_BSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,    XXXXXXX, KC_DEL
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NUMBER] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_QUOT, KC_4, KC_5, KC_6, KC_EQL,             XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_TILD, KC_1, KC_2, KC_3, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_0,    XXXXXXX, KC_MINS,    XXXXXXX, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_LCTL, KC_RSFT, XXXXXXX,    MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, KC_CUT, KC_COPY,  KC_PSTE, XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         MS_BTN3, MS_BTN1, MS_BTN2,    XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_SYM] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX,    XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, KC_DLR, KC_PERC, KC_CIRC, XXXXXXX,     XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_GRV, KC_EXLM, KC_AT,  KC_HASH, KC_PLUS,     XXXXXXX, KC_LCBR,  KC_RCBR, XXXXXXX, KC_BSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, KC_UNDS,    _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_FUN] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_F12, KC_F7, KC_F8, KC_F9,  XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_F11, KC_F4, KC_F5, KC_F6, XXXXXXX,            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_F10, KC_F1, KC_F2,  KC_F3, XXXXXXX,           XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_TIL] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX,  LALT(KC_4), LALT(KC_5), LALT(KC_6),   XXXXXXX,KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX,  LALT(KC_1), LALT(KC_2), LALT(KC_3),   XXXXXXX,XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, S(KC_BSLS),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,    XXXXXXX, KC_MPLY
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  // [LAYER_RAISE] = LAYOUT(
  // // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
  //      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  //      XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  //      XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  // // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
  //                        XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
  // //                   ╰───────────────────────────╯ ╰──────────────────╯
  // ),
};
// clang-format on
