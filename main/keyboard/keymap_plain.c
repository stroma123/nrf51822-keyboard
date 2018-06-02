/**
 * @brief 基础键盘配列
 *
 * @file keymap_plain.c
 * @author Jim Jiang
 * @date 2018-05-13
 */
#include "keymap_common.h"
#include "keyboard_fn.h"

/** ??Keymap?? */
#ifdef KEYBOARD_4100
const uint8_t keymaps[2][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP( \
           ESC, F1, F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10,  NLCK, PSCR, SLCK, PAUS, \
                1,   2,   3,   4,   5,   6,   7,   8,   9,    0,  MINS,  EQL, BSPC, HOME, \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,    P,  LBRC, RBRC, BSLS, PGUP, \
           CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L, SCLN,  QUOT,    ENT,   PGDOWN, \
           LSFT,  Z,   X,   C,   V,   B,   N,   M,   COMM,  DOT,  SLSH, RSFT,   UP,  END, \
           LCTL,FN0,LALT, GRV,         SPC,          RALT,  INS,   DEL, LEFT, DOWN, RIGHT ),
    /* 1: Fn */
    KEYMAP( \
         TRNS, F11, F12,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,  TRNS, TRNS, TRNS, FN1, \
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  P7,  P8,  P9, PAST,  TRNS, TRNS, TRNS, TRNS, \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  P4,  P5,  P6, PMNS,  TRNS, TRNS, TRNS, TRNS, \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  P1,  P2,  P3, PPLS,  TRNS,     PENT,   TRNS, \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  P0,   TRNS, PDOT,  PSLS,  TRNS, TRNS, TRNS, \
         RCTL,FN0, LGUI,TRNS,       TRNS,           TRNS, TRNS,  TRNS,  TRNS, TRNS, TRNS ),
};

const action_t PROGMEM fn_actions[] = {ACTION_LAYER_MOMENTARY(1), ACTION_FUNCTION(POWER_SLEEP)};

#endif

#ifdef KEYBOARD_60

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP_ANSI(
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT, \
        LCTL,LGUI,LALT,          SPC,                     FN0, RGUI,APP, RCTL),
    /* 1: Poker Fn
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |
     * |-----------------------------------------------------------|
     * |     |FnQ| Up|   |   |   |   |   |   |Cal|   |Hom|Ins|FnL  |
     * |-----------------------------------------------------------|
     * |      |Lef|Dow|Rig|   |   |Psc|Slk|Pau|   |Tsk|End|        |
     * |-----------------------------------------------------------|
     * |        |Del|   |Web|Mut|VoU|VoD|   |PgU|PgD|Del|          |
     * |-----------------------------------------------------------|
     * |    |    |    |         FnS            |    |    |    |    |
     * `-----------------------------------------------------------'
     * Fn:  to Fn overlay
     * FnL: to Layout selector overaly
     * FnQ: toggle Esc overlay
     * FnS: toggle Arrow overlay
     */
    KEYMAP_ANSI(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL, \
        TRNS,TRNS, UP, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,CALC,TRNS,HOME,INS, TRNS,  \
        FN1,LEFT,DOWN,RGHT,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,TRNS,END,      TRNS, \
        TRNS,DEL, TRNS,WHOM,MUTE,VOLU,VOLD,TRNS,PGUP,PGDN,DEL,           TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                     TRNS,TRNS,TRNS,TRNS),
};
const action_t PROGMEM fn_actions[] = {
    /* Poker Layout */
    ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    ACTION_FUNCTION(POWER_SLEEP) // sleep
};

#endif

#ifdef KEYBOARD_400
const uint8_t keymaps[2][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP( \
           1,    2,    3,    A, \
           4,    5,    6,    B, \
           7,    8,    9,    C, \
           LSFT, 0,    RSFT, D  ),
    /* 1: Fn */
    KEYMAP( \
         TRNS, F11, F12, TRNS, \
         CALC,VOLU,VOLD,TRNS, \
         TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,TRNS  ) ,
};

const action_t PROGMEM fn_actions[] = {ACTION_LAYER_MOMENTARY(1), ACTION_FUNCTION(POWER_SLEEP)};
#endif
