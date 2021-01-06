#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7(
        KC_GRAVE, KC_1, KC_2   , KC_3   , KC_4  , KC_5  , KC_HOME                                         KC_END , KC_6  , KC_7, KC_8   , KC_9   , KC_0   , KC_EQL,
        KC_TAB  , KC_Q, KC_W   , KC_E   , KC_R  , KC_T  , KC_BSLS                                         KC_SLSH, KC_Y  , KC_U, KC_I   , KC_O   , KC_P   , KC_QUOT,
        KC_LSFT , KC_A, KC_S   , KC_D   , KC_F  , KC_G  , KC_LBRC                                         KC_RBRC, KC_H  , KC_J, KC_K   , KC_L   , KC_SCLN, KC_RSFT,
        KC_LCTR , KC_Z, KC_X   , KC_C   , KC_V  , KC_B  ,                                                          KC_N  , KC_M, KC_COMM, KC_DOT , KC_MINS, KC_RCTR,
                        KC_LEFT, KC_RGHT,                                                                                        KC_UP  , KC_DOWN,
									      KC_ENT, KC_DEL,                                                 KC_BSPC, KC_SPC,
                                                          TO(_LOWER) , KC_ESC,       KC_WIN , TO(_RAISE),
                                                          MO(_LOWER), KC_LALT,       KC_RALT, MO(_RAISE)
    ),
    [_LOWER] = LAYOUT_5x7(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F12,                         KC_F11    , KC_F6  , KC_F7,  KC_F8, KC_F9 , KC_F10 , _______,
        _______, KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_PIPE,_______,                         _______   , _______, KC_P7,  KC_P8, KC_P9 , KC_PMNS, KC_CIRC,
        _______, KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_GRV ,_______,                         _______   , _______, KC_P4,  KC_P5, KC_P6 , KC_PPLS, _______,
        _______, KC_PERC, KC_COLN, KC_LBRC, KC_RBRC, KC_UNDS,                                             _______, KC_P1,  KC_P2, KC_P3 , KC_PAST, KC_PSLS,
                          KC_LEFT, KC_RGHT,                                                                                KC_P0, KC_PDOT,
                                            KC_ENT , KC_DEL ,                                             KC_BSPC, KC_SPC,
                                                             TO(_QWERTY),_______,    _______, TO(_RAISE),
															 MO(_RAISE), _______,    _______, MO(_QWERTY)
    ),
    [_RAISE] = LAYOUT_5x7(
        _______,_______,_______,_______,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_MS_U,_______,_______,_______,                    _______,_______,_______,_______,_______,_______,KC_MUTE,
        _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,                    _______,_______,_______,_______,_______,_______,KC_VOLU,
        _______,_______,_______,_______,_______,_______,                                    _______,_______,KC_WBAK,KC_MPLY,_______,KC_VOLD,
                        KC_BTN1,KC_BTN2,                                                                    KC_MPRV,KC_MNXT,
                                        _______,_______,                                    _______,_______,
                                                        _______,_______,    _______,_______,
                                                        _______,_______,    _______,_______
    )
};
