// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  // EL_COPY,
  // EL_CUT,
  // EL_PASTE,
  // TS_BRK,
};

// #include "elentok.h"
#include "generated-layout.h"
// #include "iris-layout.h"

// less bright version
#define HSV_CYAN1       128, 255, 100

void keyboard_post_init_user(void) {
  rgb_matrix_enable_noeeprom();
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  rgb_matrix_sethsv_noeeprom(HSV_CYAN1);
}

// #define _QWERTY 0
// #define _LOWER 1
// #define _RAISE 2
// #define _ADJUST 3

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   LOWER,
//   RAISE,
//   ADJUST,
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case EL_COPY:
    //   if (record->event.pressed) {
    //     tap_code16(LGUI(KC_C)); // send Cmd+C / Win+C
    //     layer_move(LBASE);
    //   }
    //   break;
    // case EL_CUT:
    //   if (record->event.pressed) {
    //     tap_code16(LGUI(KC_X)); // send Cmd+X / Win+X
    //     layer_move(LBASE);
    //   }
    //   break;
    // case EL_PASTE:
    //   if (record->event.pressed) {
    //     tap_code16(LGUI(KC_V)); // send Cmd+V / Win+V
    //     layer_move(LBASE);
    //   }
    //   break;
    // case TS_BRK:
    //   if (!record->event.pressed) {
    //     SEND_STRING("() => {  }");
    //     SEND_STRING(SS_TAP(X_LEFT));
    //     SEND_STRING(SS_TAP(X_LEFT));
    //   }
    //   break;
    // case EC_VI_C:
    //   if (!record->event.pressed) {
    //     SEND_STRING(SS_TAP(X_DEL));
    //     layer_move(L1);
    //   }
    //   break;
    // case EC_VI_X:
    //   if (!record->event.pressed) {
    //     SEND_STRING(SS_LGUI("x"));
    //     layer_move(L3);
    //   }
    //   break;
    // case EC_VI_O:
    //   if (!record->event.pressed) {
    //     // SEND_STRING(SS_TAP(X_ENT));
    //     SEND_STRING("\n");
    //     layer_move(L1);
    //   }
    //   break;
    // case EC_VI_Y: // yank
    //   if (!record->event.pressed) {
    //     // SEND_STRING(SS_TAP(X_ENT));
    //     SEND_STRING(SS_LGUI("c"));
    //     layer_move(L3);
    //   }
    //   break;
    // case EC_ALFRED:
    //   if (!record->event.pressed) {
    //     SEND_STRING(SS_LGUI(" "));
    //     layer_move(L1);
    //   }
    //   break;
    // case EC_WIN:
    //   if (record->event.pressed) {
    //     SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_TAB));
    //   } else {
    //     SEND_STRING(SS_UP(X_LGUI));
    //   }
    //   break;
    // case QWERTY:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_QWERTY);
    //   }
    //   return false;
    //   break;
    // case LOWER:
    //   if (record->event.pressed) {
    //     layer_on(_LOWER);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_LOWER);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    // case RAISE:
    //   if (record->event.pressed) {
    //     layer_on(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    // case ADJUST:
    //   if (record->event.pressed) {
    //     layer_on(_ADJUST);
    //   } else {
    //     layer_off(_ADJUST);
    //   }
    //   return false;
    //   break;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(LF, KC_V):
    case LT(LJK, KC_COMM):
      return 150;  // shorter hold for nav/JK layers
    default:
      return TAPPING_TERM;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(get_highest_layer(state)) {
  // case L2:
  //   rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
  //   break;
  // case L3:
  //   rgb_matrix_sethsv_noeeprom(HSV_GREEN);
  //   break;
  // case L4:
  //   rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
  //   break;
  // case VI_VIS:
  //   rgb_matrix_sethsv_noeeprom(HSV_BLUE);
  //   break;
  case LGAME:
    rgb_matrix_sethsv_noeeprom(HSV_RED);
    break;
  case LSEL:
    rgb_matrix_sethsv_noeeprom(HSV_GREEN);
    break;
  case LNUM:
    rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
    break;
  // case LONE:
  //   rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
  //   break;
  default:
    rgb_matrix_sethsv_noeeprom(HSV_CYAN1);
    break;
  }

  return state;
}



// const uint16_t PROGMEM df_combo[] = {LGUI_T(KC_D), LT(LF, KC_F), COMBO_END};
// // const uint16_t PROGMEM fg_combo[] = {LT(LF, KC_F), KC_G, COMBO_END};
// // const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
// const uint16_t PROGMEM ef_combo[] = {KC_E, LT(LF, KC_F), COMBO_END};
// const uint16_t PROGMEM sd_combo[] = {LSFT_T(KC_S), LGUI_T(KC_D), COMBO_END};
// // const uint16_t PROGMEM sdf_combo[] = {LSFT_T(KC_S), LGUI_T(KC_D), LT(LF, KC_F), COMBO_END};
// // const uint16_t PROGMEM sf_combo[] = {LSFT_T(KC_S), LT(LF, KC_F), COMBO_END};
// const uint16_t PROGMEM jk_combo[] = {LT(LJ, KC_J), RGUI_T(KC_K), COMBO_END};
// const uint16_t PROGMEM jl_combo[] = {LT(LJ, KC_J), RSFT_T(KC_L), COMBO_END};
// const uint16_t PROGMEM uio_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM kl_combo[] = {RGUI_T(KC_K), RSFT_T(KC_L), COMBO_END};
// const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
// const uint16_t PROGMEM wf_combo[] = {KC_W, LT(LF, KC_F), COMBO_END};
// const uint16_t PROGMEM ji_combo[] = {LT(LJ, KC_J), KC_I, COMBO_END};
// const uint16_t PROGMEM jo_combo[] = {LT(LJ, KC_J), KC_O, COMBO_END};
// // const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM mcommadot_combo[] = {LT(LM, KC_M), LALT_T(KC_COMM), KC_DOT, COMBO_END};

// const uint16_t PROGMEM de_combo[] = {LGUI_T(KC_D), KC_E, COMBO_END};
// const uint16_t PROGMEM rf_combo[] = {KC_R, LT(LF, KC_F), COMBO_END};


// #undef COMBO_COUNT
// #define COMBO_COUNT 14

// // const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
// // const uint16_t PROGMEM comma_dot_io_combo[] = {LALT_T(KC_COMM), KC_DOT, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {
//     COMBO(de_combo, KC_LBRC),
//     COMBO(rf_combo, KC_RBRC),

//     COMBO(df_combo, KC_DLR),
//     // COMBO(df_combo, OSM(MOD_LGUI)),
//     // COMBO(fg_combo, KC_DLR),
//     // COMBO(er_combo, KC_LPRN),
//     COMBO(ef_combo, KC_LBRC),
//     COMBO(sd_combo, LCTL(KC_A)), // keycodes with modifiers are possible too!
//     // COMBO(sdf_combo, LGUI(KC_SPC)),
//     // COMBO(sf_combo, LGUI(KC_SPC)),
//     COMBO(jk_combo, KC_ESC),
//     COMBO(jl_combo, KC_UNDS),
//     COMBO(uio_combo, LCTL(LSFT(LGUI(KC_I)))),
//     COMBO(kl_combo, KC_COLON),
//     COMBO(we_combo, KC_TILDE),
//     COMBO(wf_combo, KC_GRV),
//     COMBO(ji_combo, KC_MINS),
//     COMBO(jo_combo, KC_EQL),
//     // COMBO(io_combo, KC_UNDS),
//     COMBO(mcommadot_combo, LGUI(KC_1)),
//     // COMBO(ui_combo, LGUI(KC_1)),
//     // COMBO(comma_dot_io_combo, LGUI(KC_1)),
// };


// Disable combos on the gaming layer
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  return !layer_state_is(LGAME);
}
