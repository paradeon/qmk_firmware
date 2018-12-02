#include QMK_KEYBOARD_H
#include "action_layer.h"

enum {
    _BL = 0,
    _UL,
    _DL,
    _XL,
    _ML,
    _FL,
    _NL,
};

enum {
  TD_Z_ML = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Z_ML] = ACTION_TAP_DANCE_DOUBLE(KC_Z, _ML),
};

/* enum custom_keycodes { */
/*   DOUBLE_CLICK_MACRO = SAFE_RANGE */
/* }; */


/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   if (record->event.pressed) { */
/*     switch (keycode) { */
/*     case DOUBLE_CLICK_MACRO: SEND_STRING(SS_TAP(X_MS_BTN1)); return false; */
/*     } */
/*   } */
/*   return true; */
/* }; */

#define M_DOUBLE_CLICK M(0)
#define M_SPACE_EQL_SPACE M(1)
#define M_SPACE_EQL_GT_SPACE M(2)
#define M_SPACE_LT_EQL_SPACE M(3)
#define M_SPACE_MIN_GT_SPACE M(4)
#define M_SPACE_EQL_EQL_SPACE M(5)
#define M_SPACE_LT_SPACE M(6)
#define M_SPACE_GT_SPACE M(7)
#define M_SPACE_PLUS_SPACE M(8)
#define M_COL_SPACE M(9)
#define M_TRIPLE_CLICK M(10)
#define M_SHIFT_CLICK M(11)
#define M_CTRL_CLICK M(12)

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch (id) {
    case 0: return MACRO(T(BTN1), W(100), T(BTN1), END);
    case 1: return MACRO(T(SPC), T(EQL), T(SPC), END);
    case 2: return MACRO(T(SPC), T(EQL), D(LSFT), T(DOT), U(LSFT), T(SPC), END);
    case 3: return MACRO(T(SPC), D(LSFT), T(COMM), U(LSFT), T(EQL), T(SPC), END);
    case 4: return MACRO(T(SPC), T(MINS), D(LSFT), T(DOT), U(LSFT), T(SPC), END);
    case 5: return MACRO(T(SPC), T(EQL), T(EQL), T(SPC), END);
    case 6: return MACRO(T(SPC), D(LSFT), T(COMM), U(LSFT), T(SPC), END);
    case 7: return MACRO(T(SPC), D(LSFT), T(DOT), U(LSFT), T(SPC), END);
    case 8: return MACRO(T(SPC), D(LSFT), T(EQL), U(LSFT), T(SPC), END);
    case 9: return MACRO(D(LSFT), T(SCLN), U(LSFT), T(SPC), END);
    case 10: return MACRO(T(BTN1), W(100), T(BTN1), W(100), T(BTN1), END);
    case 11: return MACRO(D(LSFT), T(BTN1), U(LSFT), END);
    case 12: return MACRO(D(LCTL), T(BTN1), U(LCTL), END);
    }
  }
  return MACRO_NONE;
};

/* enum combos { */
/*   SD_ENT, */
/*   KL_ENT, */
/* }; */

/* const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END}; */
/* const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END}; */

/* combo_t key_combos[COMBO_COUNT] = { */
/*   [SD_ENT] = COMBO(sd_combo, KC_ENT), */
/*   [KL_ENT] = COMBO(kl_combo, KC_ENT), */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BL] = LAYOUT_PARADEON(
    LT(_UL, KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    MT(MOD_LCTL, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, MO(_UL),
    MO(_DL), LT(_ML, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, LT(_FL, KC_COMM), LT(_NL, KC_DOT), MT(MOD_LALT, KC_SLSH),
    KC_APP, KC_TRNS, KC_LGUI, MT(MOD_LALT, KC_GRV), MT(MOD_LSFT, KC_SPC), MT(MOD_RSFT, KC_ENT), MT(MOD_RCTL, KC_BSLS), KC_RGUI, KC_LEAD, MO(_XL)), 

[_DL] = LAYOUT_PARADEON(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CIRC, KC_7, KC_8, KC_9, KC_MINS, KC_DEL,
    KC_TRNS, KC_LEFT, KC_RIGHT, KC_UP, KC_TRNS, KC_TRNS, KC_ASTR, KC_4, KC_5, KC_6, KC_EQL,
    KC_TRNS, KC_TILD, KC_DOWN, KC_PLUS, KC_TRNS, KC_AMPR, KC_0, KC_1, KC_2, KC_3, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_UL] = LAYOUT_PARADEON(
    S(KC_INS), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_BSLS, KC_SCLN, KC_PIPE, KC_UP, KC_UNDS, KC_TRNS,
    KC_LBRC, KC_DQT, KC_LPRN, KC_LCBR, KC_SPC, KC_MINS, KC_LT, KC_COLN, KC_LEFT, KC_RIGHT, KC_TRNS,
    KC_RBRC, KC_QUOT, KC_RPRN, KC_RCBR, KC_ENT, KC_PLUS, KC_GT, KC_EQL, KC_DOWN, KC_QUES, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_FL] = LAYOUT_PARADEON(
    KC_INS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_XL] = LAYOUT_PARADEON(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS),

[_ML] = LAYOUT_PARADEON(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_MS_U, KC_WH_R, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, M_TRIPLE_CLICK, KC_BTN2, M_SHIFT_CLICK, KC_TRNS, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, M_SPACE_EQL_SPACE,
    KC_TRNS, KC_TRNS, KC_BTN1, M_DOUBLE_CLICK, M_CTRL_CLICK, KC_TRNS, KC_WH_D, KC_BTN3, KC_BTN4, KC_BTN5, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_NL] = LAYOUT_PARADEON(
    M_SPACE_LT_SPACE, M_SPACE_GT_SPACE, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, M_SPACE_EQL_SPACE, KC_LEFT, KC_RIGHT, KC_DOWN, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    M_SPACE_EQL_EQL_SPACE, M_SPACE_LT_EQL_SPACE, M_SPACE_EQL_GT_SPACE, M_SPACE_MIN_GT_SPACE, KC_PGDOWN, M_COL_SPACE, KC_TRNS, KC_LSFT, KC_LCTL, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_SPACE_PLUS_SPACE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};
