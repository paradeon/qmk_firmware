#pragma once

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
};

enum {
  CLN_ALT = 0,
  SOME_OTHER_DANCE
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void cln_finished (qk_tap_dance_state_t *state, void *user_data);
void cln_reset (qk_tap_dance_state_t *state, void *user_data);
