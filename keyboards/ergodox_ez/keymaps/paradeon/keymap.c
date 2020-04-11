#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum {
    BASE = 0,
    LL,
    RL,
    FL,
    //    ML,
};

#define M_DOUBLE_CLICK M(0)
#define M_TRIPLE_CLICK M(1)
#define M_SHIFT_CLICK M(2)
#define M_CTRL_CLICK M(3)
#define M_SWITCH_WIN_START M(4)
#define M_SWITCH_MAC_START M(5)
#define M_SWITCH_WIN_P_START M(6)
#define M_SWITCH_MAC_TICK M(7)
#define M_MAC_KILL_APP M(8)
#define M_MAC_KILL_WIN M(9)
#define M_MAC_SWITCH_INPUT M(10)
#define M_MAC_SPOT M(11)
#define M_MAC_COPY M(12)
#define M_MAC_CUT M(13)
#define M_MAC_PASTE M(14)
#define M_MAC_TAB M(15)
#define M_MAC_L M(16)
#define M_ALT_CLICK M(17)

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch (id) {
    case 0: return MACRO(T(BTN1), W(100), T(BTN1), END);
    case 1: return MACRO(T(BTN1), W(100), T(BTN1), W(100), T(BTN1), END);
    case 2: return MACRO(D(LSFT), W(50), T(BTN1), W(50), U(LSFT), END);
    case 3: return MACRO(D(LCTL), W(50), T(BTN1), W(50), U(LCTL), END);
    case 4: return MACRO(D(LALT), T(TAB), END);
    case 5: return MACRO(D(LGUI), T(TAB), END);
    case 6: return MACRO(D(LCTL), T(TAB), END);
    case 7: return MACRO(D(LGUI), T(GRV), END);
    case 8: return MACRO(D(LGUI), T(Q), END);
    case 9: return MACRO(D(LGUI), T(W), END);
    case 10: return MACRO(D(LGUI), T(BSLS), END);
    case 11: return MACRO(D(LGUI), T(SLSH), END);
    case 12: return MACRO(D(LGUI), T(C), END);
    case 13: return MACRO(D(LGUI), T(X), END);
    case 14: return MACRO(D(LGUI), T(V), END);
    case 15: return MACRO(D(LGUI), T(T), END);
    case 16: return MACRO(D(LGUI), T(L), END);
    case 17: return MACRO(D(LALT), W(50), T(BTN1), W(50), U(LALT), END);
    }
  }
  return MACRO_NONE;
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | M_OTR  |  1!  |  2@  |  3#  |  4$  |  5%  |  `~  |           |  \|  |   6^ |   7& |   8* |   9( |   0) | /?     |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Esc    |   Q  |   W  |   E  |   R  |   T  | AC   |           |  AC  |   Y  |   U  |   I  |   O  |   P  | BkSp   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------| LAlt |           | RAlt |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  Up  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RGui | LGui | RClk | LClk | M_LL |                                       | LGui | RCtl | Left | Down | Rght |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | DEL  | INS  |       |      | CAPS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | HOME |       | PGUP |      |      |
 *                                 | Spce | M_FL |------|       |------| M_FL | M_RL |
 *                                 |      |      | END  |       | PGDN |      |      |
 *                                 `--------------------'       `--------------------'
 * (*1) -> Ctrl + Alt + U            (Webstorm: Toggle Camel Case)
 * (*2) -> Ctrl + Shift + Alt + P    (Webstorm: Pritter Format)
 * (*3) -> Ctrl + Shift + Alt + Up   (Webstorm: Move Previous Change)
 * (*4) -> Ctrl + Shift + Alt + Down (Webstorm: Move Next Change)
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESC,      KC_1,    KC_2,    KC_3,    KC_4,   KC_5, KC_HOME,  
    KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,   KC_T, KC_END,
    OSM(MOD_LCTL), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,   KC_B, LM(BASE, MOD_LCTL | MOD_LALT),
    KC_LALT, KC_RGUI, KC_BTN2, KC_BTN1, MO(LL), 
            KC_LALT, KC_INS,
                     KC_HOME,
    KC_SPC, MO(FL),   KC_END,


    // right hand
    KC_PGUP, KC_6,  KC_7,    KC_8,    KC_9,   KC_0,     KC_SLSH,
    KC_PGDOWN, KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,     KC_BSPC,
	     KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_ENTER, 
    LM(BASE, MOD_LCTL | MOD_LALT),  KC_N,  KC_M,   KC_COMM, KC_DOT, KC_UP,  KC_LSFT,
		    KC_LGUI, KC_RCTL, KC_LEFT, KC_DOWN,  KC_RIGHT,   
    KC_NO,     KC_LALT,
    KC_PGUP,
    KC_PGDOWN, MO(FL), MO(RL)
),



/* Keymap R:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | `    | '    | _    | {    | }    |      |           |      |      | MPRV | MNXT | MPLY |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | \    | "    | +    | =    | -    |------|           |------|      | VOLD | VOLU | MUTE |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | |    | ~    | [    | ]    |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RL] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_GRV,  KC_QUOT, KC_UNDS, KC_LCBR, KC_RCBR, KC_TRNS,
       KC_TRNS, KC_BSLS, KC_DQT,  KC_PLUS, KC_EQL,  KC_MINS,
       KC_TRNS, KC_TRNS, KC_PIPE, KC_TILD, KC_LBRC, KC_RBRC, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS,
                         KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_MPLY, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap L:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      | F1   | F2   | F3   | F4   | F5   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | CAD    | M_SW | M_SA | W_SW | SINS | CATB |      |           | CAD  | F6   | F7   | F8   | F9   | F10  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CAF4   | M_CT | M_CP | M_PS | CMDL | CMTB |------|           |------| INS  | TAB  | DEL  | F11  | F12  |        |
 * |--------+------+------+------+------+------|      |           | AF4  |------+------+------+------+------+--------|
 * |        | ACLK | SCLK | CCLK | DCLK | TCLK |      |           |      | KILA | KILW | SWIN | SPOT |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LL] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
       LCA(KC_DEL), M_SWITCH_MAC_TICK,   M_SWITCH_MAC_START,   M_SWITCH_WIN_START,   S(KC_INS),   LCA(KC_TAB),   KC_TRNS,
       LALT(KC_F4), M_MAC_CUT,  M_MAC_COPY,  M_MAC_PASTE, M_MAC_L, M_MAC_TAB,
       KC_TRNS, M_SHIFT_CLICK, M_ALT_CLICK, M_CTRL_CLICK, M_DOUBLE_CLICK, M_TRIPLE_CLICK, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS,
                         KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_TRNS,
		    KC_INS, KC_TAB, KC_DEL, KC_F11, KC_F12, KC_TRNS,
       KC_TRNS, M_MAC_KILL_APP, M_MAC_KILL_WIN, M_MAC_SWITCH_INPUT, M_MAC_SPOT, KC_PGUP, KC_TRNS,
                            KC_TRNS,    KC_TRNS, KC_HOME,  KC_PGDOWN,    KC_END,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),




/* Keymap 0: Flip layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | [{     |  6^  |  7&  |  8*  |  9(  |  0)  |  \|  |           |  `~  |   1! |   2@ |   3# |   4$ |   5% | Tab    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ]}     |   Y  |   U  |   I  |   O  |   P  | Tab  |           | LClk |   Q  |   W  |   E  |   R  |   T  | Esc    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Enter  |   H  |   J  |   K  |   L  |   ;  |------|           |------|   A  |   S  |   D  |   F  |   G  | LCtrl  |
 * |--------+------+------+------+------+------| Entr |           | RClk |------+------+------+------+------+--------|
 * | LShift |   N  |   M  |   ,  |   .  |   /  |      |           |      |   Z  |   X  |   C  |   V  |   B  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt | Left | Down | Up   | Rght |                                       | M_LL | LClk | RClk | LGui | LAlt |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | DEL  | INS  |       |      | CAPS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PGUP |       | HOME |      |      |
 *                                 | M_RL |      |------|       |------|      | Spce |
 *                                 |      |      | PGDN |       | END  |      |      |
 *                                 `--------------------'       `--------------------'
 * (*1) -> Ctrl + Alt + U            (Webstorm: Toggle Camel Case)
 * (*2) -> Ctrl + Shift + Alt + P    (Webstorm: Pritter Format)
 * (*3) -> Ctrl + Shift + Alt + Up   (Webstorm: Move Previous Change)
 * (*4) -> Ctrl + Shift + Alt + Down (Webstorm: Move Next Change)
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[FL] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_LBRC,       KC_6,  KC_7,    KC_8,    KC_9,   KC_0,     KC_BSLS, 
    KC_RBRC,       KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,     KC_TAB,
    KC_ENTER,      KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN,   
    OSM(MOD_LSFT), KC_N,  KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_ENTER, 
		    KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, OSM(MOD_LALT),   
            KC_DELT, KC_INS,
                     KC_PGUP,
    MO(RL), KC_NO,   KC_PGDOWN,

    // right hand
    KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,   KC_5, KC_TRNS, 
    KC_BTN1,        KC_Q,    KC_W,    KC_E,    KC_R,   KC_T, KC_ESC,
		KC_A,    KC_S,    KC_D,    KC_F,   KC_G, OSM(MOD_LCTL), 
     KC_BTN2,      KC_Z,    KC_X,    KC_C,    KC_V,   KC_B, OSM(MOD_LSFT),
    KC_LGUI, KC_BTN2, KC_BTN1, MO(LL), OSM(MOD_LALT), 
    KC_NO,     KC_CAPS,
    KC_HOME,
    KC_END, KC_NO, KC_SPC
)

/* Keymap 0: Magnet Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |   6  |   7  |   8  |   9  |   0  | /      |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   Y  |   U  |   I  |   O  |      | Bksp   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  M   |   ,  |   .  |  Up  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      | Left | Down | Rght |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 * (*1) -> Ctrl + Alt + U            (Webstorm: Toggle Camel Case)
 * (*2) -> Ctrl + Shift + Alt + P    (Webstorm: Pritter Format)
 * (*3) -> Ctrl + Shift + Alt + Up   (Webstorm: Move Previous Change)
 * (*4) -> Ctrl + Shift + Alt + Down (Webstorm: Move Next Change)
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
/*
[ML] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO, KC_NO,  
    KC_NO,        KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO, KC_NO,
    OSM(MOD_LCTL), KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
    KC_LSFT,       KC_Z,    KC_NO,    KC_NO,    KC_NO,   KC_NO, KC_NO,
    KC_LALT, KC_RGUI, KC_BTN2, KC_BTN1, MO(LL), 
            KC_DELT, KC_INS,
                     KC_HOME,
    KC_SPC, MO(FL),   KC_END,


    // right hand
    KC_BSLS, KC_6,  KC_7,    KC_8,    KC_9,   KC_0,     KC_SLSH,
    M_ALT_CTL, KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,     KC_BSPC,
	     KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_ENTER, 
    KC_LALT,  KC_N,  KC_M,   KC_COMM, KC_DOT, KC_UP,  KC_LSFT,
		    KC_LGUI, KC_RCTL, KC_LEFT, KC_DOWN,  KC_RIGHT,   
    KC_NO,     KC_CAPS,
    KC_PGUP,
    KC_PGDOWN, MO(FL), MO(RL)
),
*/


};


/* const uint16_t PROGMEM fn_actions[] = { */
/*     [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols) */
/* }; */

/* const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) */
/* { */
/*   // MACRODOWN only works in this function */
/*       switch(id) { */
/*         case 0: */
/*         if (record->event.pressed) { */
/*           SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION); */
/*         } */
/*         break; */
/*         case 1: */
/*         if (record->event.pressed) { // For resetting EEPROM */
/*           eeconfig_init(); */
/*         } */
/*         break; */
/*       } */
/*     return MACRO_NONE; */
/* }; */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
