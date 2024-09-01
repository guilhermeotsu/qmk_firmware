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

#define SP_NUM LT(_ARR, KC_SPC)
#define Z_HOLD LT(_MOUSE,KC_Z)
#define SL_HOLD LT(_MOUSE, KC_SLSH)
#define TB_TIL LT(_TIL, KC_TAB)
#define ENT_NUM LT(_NUMBER, KC_ENT)
#define BSP_SYN LT(_SYM, KC_BSPC)

#define GUI_A G(KC_A)
#define GUI_S G(KC_SCLN)
#define ALT_S A(KC_S)
#define ALT_L A(KC_L)
#define CTR_D C(KC_D)
#define CTR_K C(KC_K)
#define SFT_F S(KC_F)
#define SFT_J S(KC_J)

enum charybdis_keymap_layers {
    _BASE = 0,
    _ARR,
    _NUMBER,
    _MOUSE,
    _SYM,
    _FUN,
    _TIL
};

enum custom_keycodes {
    TLG1 = SAFE_RANGE,
    TLG2,
    TLG3,
    TLG4,
    TLG5,
    TLG6,
    TD_DOT
};

enum combos {
    THUMB_ESC
};

const uint16_t PROGMEM thumb_combo[] = {SP_NUM, TB_TIL, COMBO_END};
combo_t key_combos[] = {
    [THUMB_ESC] = COMBO(thumb_combo, KC_ESC),
};

// // Function to handle tap dance actions
// void td_dragscroll_finished(tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1 && !state->pressed) {
//         // Single tap: send "."
//         register_code16(KC_DOT);
//     } else if (state->pressed) {
//         // Hold: enable drag scroll
//         charybdis_set_pointer_dragscroll_enabled(true);
//     }
// }
//
// void td_dragscroll_reset(tap_dance_state_t *state, void *user_data) {
//     if (state->pressed) {
//         // On release: disable drag scroll
//         charybdis_set_pointer_dragscroll_enabled(false);
//     }
// }
//
// //Tap Dance Definitions
// tap_dance_action_t tap_dance_actions[] = {
//   //Tap once for "." , hold for enable Drag Scroll, release for disable
//   [TD_DOT]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dragscroll_finished, td_dragscroll_reset),
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // charybdis_set_pointer_dragscroll_enabled(true);
  uint16_t press = XXXXXXX;
  switch(keycode) {
      case TLG1:
          press = LALT(KC_1);
          break;
      case TLG2:
          press = LALT(KC_2);
          break;
      case TLG3:
          press = LALT(KC_3);
          break;
      case TLG4:
          press = LALT(KC_4);
          break;
      case TLG5:
          press = LALT(KC_5);
          break;
      case TLG6:
          press = LALT(KC_6);
          break;
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
          Z_HOLD,   KC_X,   KC_C,    KC_V,    KC_B,       KC_N,     KC_M,   KC_COMM, TD_DOT,  SL_HOLD,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         QK_REP,  SP_NUM,    TB_TIL,      ENT_NUM, BSP_SYN
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_ARR] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME,    KC_PGDN, KC_PGUP, KC_END, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LGUI, KC_LALT, KC_LCTL, KC_RSFT, XXXXXXX,    KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX,   MS_WHLD, MS_WHLU, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,    XXXXXXX, KC_DEL
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NUMBER] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX,             KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_TILD, KC_1, KC_2, KC_3, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_0,    XXXXXXX, XXXXXXX,    _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX,   XXXXXXX, KC_LCTL, KC_RSFT, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, KC_CUT, KC_COPY,  KC_PSTE, XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, MS_BTN1, MS_BTN2,    XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_SYM] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX,    XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, KC_DLR, KC_PERC, KC_CIRC, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_GRV, KC_EXLM, KC_AT,  KC_HASH, KC_PLUS,     XXXXXXX, KC_LCBR,  KC_RCBR, XXXXXXX, KC_BSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, KC_UNDS,    XXXXXXX, _______
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
       XXXXXXX,   TLG4,     TLG5,    TLG6, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX,   TLG1,     TLG2,    TLG3, XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,    XXXXXXX, XXXXXXX
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

// tapdance keycodes
// enum td_keycodes {
//   ALT_LP // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
// };
//
// // define a type containing as many tapdance states as you need
// typedef enum {
//   SINGLE_TAP,
//   SINGLE_HOLD
// } td_state_t;
//
// // create a global instance of the tapdance state type
// static td_state_t td_state;
//
// // function to determine the current tapdance state
// int cur_dance (qk_tap_dance_state_t *state);
//
// // `finished` and `reset` functions for each tapdance keycode
// void altlp_finished (qk_tap_dance_state_t *state, void *user_data);
// void altlp_reset (qk_tap_dance_state_t *state, void *user_data);
//
// int cur_dance (qk_tap_dance_state_t *state) {
//   if (state->count == 1) {
//     if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
//     else { return SINGLE_HOLD; }
//   }
// }
//
// void altlp_finished (qk_tap_dance_state_t *state, void *user_data) {
//   td_state = cur_dance(state);
//   switch (td_state) {
//     case SINGLE_TAP:
//       register_code16(KC_LPRN);
//       break;
//     case SINGLE_HOLD:
//       register_mods(MOD_BIT(KC_LALT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
//       break;
//   }
// }
