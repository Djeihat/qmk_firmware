#include QMK_KEYBOARD_H


#define _MAIN    0
#define _NAVPAD  1
#define _NUMPAD  2
#define _MEDIA   3
#define _PROGRAM 4
#define _MOUSE   5
//#define _UNDEFINED 6
#define _GAMING  7

#define HLD_RST RESET         // Send Reset when held
#define _COPY__ LCTL(KC_C)    // Copy Command
#define __CUT__ LCTL(KC_X)    // Cut Command
#define _UNDO__ LCTL(KC_Z)    // Undo Command
#define _PASTE_ LCTL(KC_V)    // Paste Command
#define EXPLORE	LWIN(KC_E)    // Windows Explorer Command

// #define PLY_DEL when shift is pushed, bkspc becomes del
// #define LS_OPAR MT(KC_LPRN,KC_LSFT) // not functional
// #define RS_CPAR MT(KC_RPRN,KC_RSFT) // not functional

#define LVL_MAIN TO(_MAIN)    // Switch to the Main level
#define LVL_NUM  MO(_NUMPAD)  // Hold for access to Numpad
#define LVL_NAV  MO(_NAVPAD)  // Hold for access to Dirpad
#define LVL_MED  MO(_MEDIA)   // Hold for access to Media
#define LVL_PGM  MO(_PROGRAM) // Hold for access to Programming
#define LVL_MSE  MO(_MOUSE)   // Hold for access to Mouse
#define LVL_GAME TO(_GAMING)  // Switch to the Main level

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code16(C(KC_RGHT));
        } else {
            tap_code16(C(KC_LEFT));
        }
    }
}
#endif


// #TODO: Layered Encoders, Refine Gaming Layer, Improve AltTab functionality

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_5x7(
        KC_GRAVE, KC_1, KC_2   , KC_3   , KC_4  , KC_5  , KC_HOME,                       KC_END  , KC_6   , KC_7  , KC_8   , KC_9   , KC_0   , KC_EQL,
        KC_TAB  , KC_Q, KC_W   , KC_E   , KC_R  , KC_T  , KC_BSLS,                       KC_SLSH , KC_Y   , KC_U  , KC_I   , KC_O   , KC_P   , KC_SCLN,
        KC_LSPO , KC_A, KC_S   , KC_D   , KC_F  , KC_G  , KC_LBRC,                       KC_RBRC , KC_H   , KC_J  , KC_K   , KC_L   , KC_QUOT, KC_RSPC,
        KC_LCTL , KC_Z, KC_X   , KC_C   , KC_V  , KC_B  ,                                          KC_N   , KC_M  , KC_COMM, KC_DOT , KC_MINS, KC_RCTL,
                        KC_LALT, KC_ESC ,                                                                           KC_LWIN, KC_RALT,
									      KC_BSPC, KC_DEL,                                         KC_ENT , KC_SPC,
                                                          LVL_MAIN, LVL_MED,    XXXXXXX, LVL_GAME,
                                                          LVL_NAV , LVL_NUM,    LVL_MSE, LVL_PGM
    ),
	[_NAVPAD] = LAYOUT_5x7(
        XXXXXXX, KC_F1  , KC_F2  , KC_F3     , KC_F4  , KC_F5  , KC_F12,                         KC_F11 , KC_F6  , KC_F7    , KC_F8  , KC_F9  , KC_F10 , XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, EXPLORE   , XXXXXXX, XXXXXXX, XXXXXXX ,                       XXXXXXX, XXXXXXX, KC_HOME  , KC_UP  , KC_END , XXXXXXX, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX, XXXXXXX, XXXXXXX ,                       XXXXXXX, XXXXXXX, KC_LEFT  , KC_DOWN, KC_RGHT, XXXXXXX , KC_LSFT,
        KC_TRNS, _UNDO__, __CUT__, _COPY__   , _PASTE_, XXXXXXX,                                          XXXXXXX, S(KC_TAB), XXXXXXX, KC_TAB , XXXXXXX , KC_TRNS,
                          KC_LALT, KC_TRNS   ,                                                                     KC_BSPC  , KC_DEL ,
                                               KC_TRNS, KC_TRNS,                                          KC_TRNS, KC_TRNS  ,
                                                                 KC_TRNS , KC_TRNS,     KC_TRNS, KC_TRNS,
															     LVL_NAV , KC_TRNS,     KC_TRNS, KC_TRNS
    ),
    [_NUMPAD] = LAYOUT_5x7(
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F12,                         KC_F11  , KC_F6  , KC_F7  , KC_F8, KC_F9  , KC_F10 , XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                       XXXXXXX , XXXXXXX, KC_P7  , KC_P8, KC_P9  , KC_PMNS, KC_CIRC,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                       XXXXXXX , XXXXXXX, KC_P4  , KC_P5, KC_P6  , KC_PPLS, KC_PSLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                           XXXXXXX, KC_P1  , KC_P2, KC_P3  , KC_PAST, XXXXXXX,
                          KC_BSPC, KC_DEL ,                                                                               KC_P0, KC_PDOT,
                                            KC_TRNS, KC_TRNS,                                           KC_TRNS, KC_TRNS,
                                                              KC_TRNS , KC_TRNS,     KC_TRNS, KC_TRNS,
															  KC_TRNS , LVL_NUM,     KC_TRNS, KC_TRNS
    ),
    [_MEDIA] = LAYOUT_5x7(
        XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HLD_RST,                       XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX , XXXXXXX, KC_MUTE, KC_VOLU, KC_MPLY, XXXXXXX, XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX , XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX,                                                                              XXXXXXX, XXXXXXX,
                                          KC_TRNS, KC_TRNS,                                          KC_TRNS, KC_TRNS,
                                                            KC_TRNS, LVL_NUM,    KC_TRNS, KC_TRNS,
                                                            KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS
    ),
	[_PROGRAM] = LAYOUT_5x7(
        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F12  ,                      KC_F11 , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX,
        KC_PIPE, KC_AT  , KC_DLR , KC_LCBR, KC_RCBR, KC_ASTR, XXXXXXX ,                      XXXXXXX, XXXXXXX, KC_HOME, KC_UP  , KC_END , XXXXXXX, XXXXXXX,
        KC_GRV , KC_MINS, KC_UNDS, KC_LBRC, KC_RBRC, KC_PLUS, XXXXXXX ,                      XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_LSFT,
        KC_TILD, KC_PERC, KC_COLN, KC_LABK, KC_RABK, KC_HASH,                                         XXXXXXX, KC_EXLM, KC_EQL , KC_PDOT, XXXXXXX, KC_SPC ,
                          KC_BSLS, KC_SLSH  ,                                                                           KC_LWIN, KC_RALT,
                                            KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS,
                                                              KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS ,
															  KC_TRNS , KC_TRNS,    KC_TRNS, LVL_NUM
    ),
	[_MOUSE] = LAYOUT_5x7(
        XXXXXXX, XXXXXXX, KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN5, XXXXXXX , XXXXXXX,             XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX   , KC_MS_U   , XXXXXXX   , XXXXXXX , XXXXXXX,             XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT, XXXXXXX, KC_MS_L   , KC_MS_D   , KC_MS_R   , XXXXXXX , XXXXXXX,             XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
        KC_LCTL, XXXXXXX, C(KC_PGUP), XXXXXXX   , C(KC_PGDN), XXXXXXX ,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL,
                          XXXXXXX   , XXXXXXX   ,                                                                        XXXXXXX, XXXXXXX,
                                                  KC_BTN1   , KC_BTN2 ,                                XXXXXXX, XXXXXXX,
                                                              KC_TRNS , KC_TRNS,    KC_TRNS, KC_TRNS,
                                                              KC_TRNS , KC_TRNS,    LVL_MSE, KC_TRNS
    ),
	[_GAMING] = LAYOUT_5x7(
        KC_GRAVE, KC_1, KC_2   , KC_3   , KC_4  , KC_5  , KC_HOME,                       KC_END  , KC_6   , KC_7  , KC_8   , KC_9   , KC_0   , KC_EQL,
        KC_TAB  , KC_Q, KC_W   , KC_E   , KC_R  , KC_T  , KC_BSLS,                       KC_SLSH , KC_Y   , KC_U  , KC_I   , KC_O   , KC_P   , KC_SCLN,
        KC_LSPO , KC_A, KC_S   , KC_D   , KC_F  , KC_G  , KC_LBRC,                       KC_RBRC , KC_H   , KC_J  , KC_K   , KC_L   , KC_QUOT, KC_RSPC,
        KC_LCTL , KC_Z, KC_X   , KC_C   , KC_V  , KC_B  ,                                          KC_N   , KC_M  , KC_COMM, KC_DOT , KC_MINS, KC_RCTL,
                        KC_LALT, KC_ESC ,                                                                           KC_LWIN, KC_RALT,
									      KC_SPC, KC_ENT,                                          KC_BSPC, KC_DEL,
                                                          LVL_MAIN, LVL_MED,    XXXXXXX, LVL_GAME,
                                                          LVL_NAV , LVL_NUM,    LVL_MSE, LVL_PGM
    )
};


