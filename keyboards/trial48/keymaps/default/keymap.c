/* Copyright 2020 nabe
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
#include "keymap_jp.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _SYMBOL,
    _NUMPAD,
    _FNCTN,
    _JP_QWE,
    _JP_SYM,
    _JP_NUM,
    _JP_FN,
    _RGBLED
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    MAIL = SAFE_RANGE,
    LED_OFF,
    LED_RST,
    IND_ONLY
};

//Tap Dance Declarations
enum {
    TD_ESC_JP = 0,
    TD_ESC_QWERTY,
    TD_F2_F5
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_JP] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, _JP_QWE),
    [TD_ESC_QWERTY] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, _QWERTY),
    [TD_F2_F5]= ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F5)
};

// Deifines the keycode macros
#define ENT_SYM LT(_SYMBOL, KC_ENT)
#define ENT_NUM LT(_NUMPAD, KC_ENT)
#define APP_LED LT(_RGBLED, KC_APP)

#define EN_SY_J LT(_JP_SYM, KC_ENT)
#define EN_NM_J LT(_JP_NUM, KC_ENT)

#define SPC_SFT SFT_T(KC_SPC)
#define TAB_SFT SFT_T(KC_TAB)
#define DOT_SFT SFT_T(KC_DOT)

#define TAB_CTL CTL_T(KC_TAB)
#define SPC_CTL CTL_T(KC_SPC)
#define DOT_CTL CTL_T(KC_DOT)

#define DEL_GUI GUI_T(KC_DEL)

#define KC_IME  A(KC_GRV)
#define PS_WNDW SGUI(KC_S)

#define D_ES_JP TD(TD_ESC_JP)
#define D_ES_QW TD(TD_ESC_QWERTY)
#define D_F2_F5 TD(TD_F2_F5)

// Keymap setting
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,  D_F2_F5,                                                                                           KC_F6,   D_ES_JP, \
        KC_LSFT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RCTL, \
        KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,  \
                                   DEL_GUI, TAB_CTL, SPC_SFT, ENT_SYM, ENT_NUM, TAB_SFT, SPC_CTL, APP_LED                    \
    ),
    [_SYMBOL] = LAYOUT(
        _______, KC_PSCR,                                                                                           _______, KC_ESC,  \
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
        _______, KC_TILD, KC_PLUS, KC_EQL,  KC_UNDS, KC_MINS,                   KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_COLN, _______, \
        _______, PS_WNDW, KC_GRV,  KC_BSLS, KC_PIPE, KC_IME,                    KC_QUOT, KC_DQUO, KC_LABK, KC_RABK, KC_QUES, _______, \
                                   _______, _______, _______, _______, _______, _______, _______, _______                    \
    ),
    [_NUMPAD] = LAYOUT(
        _______, KC_EQL,                                                                                            _______, KC_ESC,  \
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  MAIL,    _______, \
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______, \
        _______, KC_PERC, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS,                   KC_TAB,  KC_SPC,  KC_PSCR, PS_WNDW, XXXXXXX, _______, \
                                   KC_COMM, DOT_CTL, SPC_SFT, _______, _______, _______, _______, _______                    \
    ),
    [_FNCTN] = LAYOUT(
        _______, XXXXXXX,                                                                                           XXXXXXX, KC_ESC,  \
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
        _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
                                   DEL_GUI, TAB_CTL, SPC_SFT, _______, _______, _______, _______, _______                    \
    ),
    [_JP_QWE] = LAYOUT(
        KC_ESC,  D_F2_F5,                                                                                           KC_F6,   D_ES_QW, \
        KC_LSFT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN, KC_RCTL, \
        KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    JP_COMM, JP_DOT,  JP_SLSH, KC_DEL,  \
                                   DEL_GUI, TAB_CTL, SPC_SFT, EN_SY_J, EN_NM_J, TAB_SFT, SPC_CTL, APP_LED                    \
    ),
    [_JP_SYM] = LAYOUT(
        _______, PS_WNDW,                                                                                           _______, KC_ESC,  \
        _______, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC,                   JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, _______, \
        _______, JP_TILD, JP_PLUS, JP_EQL,  JP_UNDS, JP_MINS,                   JP_LBRC, JP_RBRC, JP_LCBR, JP_RCBR, JP_COLN, _______, \
        _______, PS_WNDW, JP_GRV,  JP_BSLS, JP_PIPE, JP_ZKHK,                   JP_QUOT, JP_DQUO, JP_LABK, JP_RABK, KC_QUES, _______, \
                                   _______, _______, _______, _______, _______, _______, _______, _______                    \
    ),
    [_JP_NUM] = LAYOUT(
        _______, JP_EQL,                                                                                            _______, KC_ESC,  \
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  MAIL,    _______, \
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______, \
        _______, JP_PERC, JP_SLSH, JP_ASTR, JP_MINS, JP_PLUS,                   KC_TAB,  KC_SPC,  KC_PSCR, PS_WNDW, XXXXXXX, _______, \
                                   JP_COMM, DOT_CTL, SPC_SFT, _______, _______, _______, _______, _______                    \
    ),
    [_JP_FN] = LAYOUT(
        _______, XXXXXXX,                                                                                           XXXXXXX, KC_ESC,  \
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
        _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
                                   DEL_GUI, TAB_CTL, SPC_SFT, _______, _______, _______, _______, _______                    \
    ),
    [_RGBLED] = LAYOUT(
        _______, XXXXXXX,                                                                                           XXXXXXX, KC_ESC,  \
        _______, LED_OFF, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                   XXXXXXX, RGB_M_P, RGB_M_SW,RGB_M_X, XXXXXXX, _______, \
        _______, LED_RST, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,                  XXXXXXX, RGB_M_B, RGB_M_SN,RGB_M_G, XXXXXXX, _______, \
        _______, IND_ONLY,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RGB_M_R, RGB_M_K, RGB_M_T, XXXXXXX, _______, \
                                   _______, _______, _______, _______, _______, _______, _______, _______                    \
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // One-shot e-mail
        case MAIL:
            if (record->event.pressed) {
                SEND_STRING("test@gmail.com");
            } else {
            }
            break;
#ifdef RGBLIGHT_ENABLE
        case LED_OFF:
            if (record->event.pressed) {
                rgblight_set_effect_range(0, 50);
                rgblight_disable();
            } else {
            }
            break;
        // Reset LED config
        case LED_RST:
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                rgblight_set_effect_range(1, 49);
                rgblight_sethsv_at(HSV_PURPLE, 0);
            } else {
            }
            break;
        // INDICATER ONLY
        case IND_ONLY:
            if (record->event.pressed) {
                rgblight_enable();
                rgblight_set_effect_range(1, 49);
                rgblight_sethsv(0, 0, 0);
                rgblight_sethsv_at(HSV_PURPLE, 0);
            } else {
            }
            break;
#endif
    }
    return true;
}

#ifdef RGBLIGHT_ENABLE

void keyboard_post_init_user(void) {
    if (rgblight_is_enabled()) {
        rgblight_set_effect_range(1, 49);
        rgblight_sethsv_at(HSV_RED, 0);
    }
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOL, _NUMPAD, _FNCTN);
    state = update_tri_layer_state(state, _JP_SYM, _JP_NUM, _JP_FN);
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _SYMBOL:
    case _JP_SYM:
        rgblight_sethsv_at(HSV_BLUE, 0);
        break;
    case _NUMPAD:
    case _JP_NUM:
        rgblight_sethsv_at(HSV_GREEN, 0);
        break;
    case _JP_QWE:
        rgblight_sethsv_at(HSV_PINK, 0);
        break;
    case _FNCTN:
    case _JP_FN:
        rgblight_sethsv_at(HSV_YELLOW, 0);
        break;
    case _RGBLED:
        rgblight_sethsv_at(HSV_PURPLE, 0);
        break;
    default:
        rgblight_sethsv_at(HSV_RED, 0);
        break;
    }
#endif
    return state;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool led_update_user(led_t led_state) {
    return true;
}
