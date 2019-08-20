#include "paradeon.h"
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"


int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    return DOUBLE_TAP;
  }
  else return 8;
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap clntap_state = {
  .is_press_action = true,
  .state = 0
};

void cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  clntap_state.state = cur_dance(state);
  switch (clntap_state.state) {
    case SINGLE_TAP: register_code(KC_LSFT); register_code(KC_SCLN); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_SCLN); unregister_code(KC_SCLN); register_code(KC_SCLN); break;
  }
}

void cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (clntap_state.state) {
    case SINGLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_SCLN);  break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_SCLN); break;
  }
  clntap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [CLN_ALT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,cln_finished, cln_reset)
};
