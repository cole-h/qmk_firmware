#include QMK_KEYBOARD_H

/*
,-----------------------------------------------------------------------------------------------------------------.
| ,--------------------------------------------------------------------------------.   ,------------------------. |
| | Esc |   | F1 | F2 | F3 | F4 |   | F5 | F6 | F7 | F8 |   | F9 | F10| F11 | F12  |   | SysRq | ScrLck | Pause | |
| |--------------------------------------------------------------------------------|   |------------------------| |
| | Grv |  1  |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0  |  - |  = | Backspace  |   | Ins   | Home   | PgUp  | |
| |--------------------------------------------------------------------------------|   |------------------------| |
| |  Tab   |  Q  |  W |  E |  R |  T |  Y |  U |  I |  O |  P  |  [ |  ] |    \    |   | Del   | End    | PgDn  | |
| |--------------------------------------------------------------------------------|   `------------------------' |
| | CapsLck |  A  |  S |  D |  F |  G |  H |  J |  K |  L |  ;  |  ' |    Enter    |                              |
| |--------------------------------------------------------------------------------|           ,--------.         |
| |   LShift   |  Z  |  X |  C |  V |  B |  N |  M |  , |  . |  /  |    RShift     |           | Up     |         |
| |--------------------------------------------------------------------------------|   ,------------------------. |
| | LCtrl | LGUI | LAlt |             Space             | RAlt | Fn | Menu | RCtrl |   | Left  | Down   | Right | |
| `--------------------------------------------------------------------------------'   `------------------------' |
`-----------------------------------------------------------------------------------------------------------------'
*/

enum custom_keycodes {
    /* CTRL keycodes */
    L_BRI = SAFE_RANGE, // LED Brightness Increase
    L_BRD,              // LED Brightness Decrease
    L_EDG_I,            // LED Edge Brightness Increase
    L_EDG_D,            // LED Edge Brightness Decrease
    L_EDG_M,            // LED Edge lighting mode
    L_PTN,              // LED Pattern Select Next
    L_PTP,              // LED Pattern Select Previous
    L_PSI,              // LED Pattern Speed Increase
    L_PSD,              // LED Pattern Speed Decrease
    L_RATIOI,           // LED Ratio Brightness Increase
    L_RATIOD,           // LED Ratio Brightness Decrease
    L_T_MD,             // LED Toggle Mode
    L_T_ONF,            // LED Toggle On / Off
    L_ON,               // LED On
    L_OFF,              // LED Off
    L_T_BR,             // LED Toggle Breath Effect
    L_T_PTD,            // LED Toggle Scrolling Pattern Direction and effect
    U_T_AGCR,           // USB Toggle Automatic GCR control
    DBG_TOG,            // DEBUG Toggle On / Off
    DBG_MTRX,           // DEBUG Toggle Matrix Prints
    DBG_KBD,            // DEBUG Toggle Keyboard Prints
    DBG_MOU,            // DEBUG Toggle Mouse Prints
    DBG_FAC,            // DEBUG Factory light testing (All on white)
    MD_BOOT,            // Restart into bootloader after hold timeout

    /* Custom keycodes */
};

/* Tapdance keycodes */
enum tapdance_keycodes {
    LSHFT,
    RSHFT,
};

/* Layers */
enum layers {
    QWERTY,
    COLEMAK,
    UTIL1,
    UTIL2,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [LSHFT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [RSHFT] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
};

/* Key aliases */
#define HUH(kc) LCTL(LALT(LGUI(kc)))
#define MT_C2E LCTL_T(KC_ESC)
#define TD_LSFT TD(LSHFT)
#define TD_RSFT TD(RSHFT)
#define TG_NKRO MAGIC_TOGGLE_NKRO // Toggle 6KRO / NKRO mode

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,    KC_F12,            KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_MINS,   KC_EQL,  KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_LBRC,   KC_RBRC, KC_BSLS,  KC_DEL,  KC_END,  KC_PGDN, \
        MT_C2E,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   KC_QUOT,   KC_ENT,                                       \
        TD_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   TD_RSFT,                               KC_UP,            \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(UTIL1), MO(UTIL2), KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT  \
    ),

    [COLEMAK] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,    KC_F12,            KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_MINS,   KC_EQL,  KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,   KC_LBRC,   KC_RBRC, KC_BSLS,  KC_DEL,  KC_END,  KC_PGDN, \
        MT_C2E,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,      KC_QUOT,   KC_ENT,                                       \
        TD_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   TD_RSFT,                               KC_UP,            \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(UTIL1), MO(UTIL2), KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT  \
    ),

    /*
    [COLEMAK] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, _______, _______,   _______, _______, _______, \
        _______, _______, KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______, ______,                                        \
        _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______, _______,                              _______,          \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______  \
    ),
    */

    [UTIL1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,    _______, _______,           _______,    _______,    _______,    \
        _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9),     G(KC_0),    _______, _______, _______,  _______,    _______,    _______,    \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   L_EDG_I, _______, _______, _______, _______, _______,     _______,    _______, _______, _______,  _______,    _______,    _______,    \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   L_EDG_D, _______, _______, _______, _______, _______,     _______,    _______, _______,                                               \
        _______, L_T_MD,  L_T_ONF, _______, L_EDG_M, MD_BOOT, TG_NKRO, _______, _______, DF(COLEMAK), DF(QWERTY), _______,                                G(KC_UP),               \
        _______, _______, _______,                   DBG_FAC,                            _______,     _______,    _______, _______,           G(KC_LEFT), G(KC_DOWN), G(KC_RGHT)  \
    ),

    [UTIL2] = LAYOUT(
        _______, _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______,            _______, _______, _______, \
        _______, HUH(KC_1), HUH(KC_2), HUH(KC_3), HUH(KC_4), HUH(KC_5), HUH(KC_6), HUH(KC_7), HUH(KC_8), HUH(KC_9), HUH(KC_0), _______, _______, _______,   _______, _______, _______, \
        _______, KC_KP_7,   KC_KP_8,   KC_KP_9,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______,   KC_MPLY, KC_MSTP, KC_MUTE, \
        _______, KC_KP_4,   KC_KP_5,   KC_KP_6,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, _______,                                       \
        _______, KC_KP_1,   KC_KP_2,   KC_KP_3,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                              KC_VOLU,          \
        _______, KC_KP_0,   KC_PDOT,                         _______,                                    _______,   _______,   _______, _______,            KC_MPRV, KC_VOLD, KC_MNXT  \
    ),

    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                       \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______,          \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______  \
    ),
    */
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL   (get_mods() & MOD_BIT(KC_LCTL)   || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT    (get_mods() & MOD_BIT(KC_LALT)   || get_mods() & MOD_BIT(KC_RALT))

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_C2E:
            return 150;
        default:
            return TAPPING_TERM;
    }
}

void led_set_user(uint8_t usb_led) {
  // Force-enable Numlock for numpad layer
  if (!(usb_led & (1 << USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }
}

// Called whenever a key is pressed or released
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer = 0;
    static uint8_t scroll_effect = 0;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) {
                    gcr_desired = LED_GCR_MAX;
                } else {
                    gcr_desired += LED_GCR_STEP;
                }
                
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                }
            }
            break;

        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) {
                    gcr_desired = 0;
                } else {
                    gcr_desired -= LED_GCR_STEP;
                }
                
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                }
            }
            break;

        case L_EDG_M:
            if (record->event.pressed) {
                led_edge_mode++;

                if (led_edge_mode > LED_EDGE_MODE_MAX) {
                    led_edge_mode = LED_EDGE_MODE_ALL;
                }
            }
            break;

        case L_EDG_I:
            if (record->event.pressed) {
                led_edge_brightness += 0.1;

                if (led_edge_brightness > 1) {
                    led_edge_brightness = 1;
                }
            }
            break;

        case L_EDG_D:
            if (record->event.pressed) {
                led_edge_brightness -= 0.1;

                if (led_edge_brightness < 0) {
                    led_edge_brightness = 0;
                }
            }
            break;

        case L_RATIOI:
            if (record->event.pressed) {
                led_ratio_brightness += 0.2;

                if (led_ratio_brightness > 2.0) {
                    led_ratio_brightness = 2.0;
                }
            }
            break;

        case L_RATIOD:
            if (record->event.pressed) {
                led_ratio_brightness -= 0.2;

                if (led_ratio_brightness < 0.0) {
                    led_ratio_brightness = 0.0;
                }
            }
            break;

        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) {
                    led_animation_id = 0;
                } else {
                    led_animation_id++;
                }
            }
            break;

        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) {
                    led_animation_id = led_setups_count - 1;
                } else {
                    led_animation_id--;
                }
            }
            break;

        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            break;

        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;

                if (led_animation_speed < 0) {
                    led_animation_speed = 0;
                }
            }
            break;

        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;

                if (led_lighting_mode > LED_MODE_MAX_INDEX) {
                    led_lighting_mode = LED_MODE_NORMAL;
                }
            }
            break;

        case L_T_ONF:
            if (record->event.pressed) {
                I2C3733_Control_Set(!I2C3733_Control_Get());
            }
            break;

        case L_ON:
            if (record->event.pressed) {
                I2C3733_Control_Set(1);
            }
            break;

        case L_OFF:
            if (record->event.pressed) {
                I2C3733_Control_Set(0);
            }
            break;

        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;

                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            break;

        case L_T_PTD:
            if (record->event.pressed) {
                scroll_effect++;

                if (scroll_effect == 1) {
                    // Patterns with scroll move horizontal (Right to left)
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                } else if (scroll_effect == 2) {
                    // Patterns with scroll move vertical (Top to bottom)
                    led_animation_direction = 1;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 3) {
                    // Patterns with scroll move vertical (Bottom to top)
                    led_animation_direction = 0;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 4) {
                    // Patterns with scroll explode from center
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else if (scroll_effect == 5) {
                    // Patterns with scroll implode on center
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else {
                    // Patterns with scroll move horizontal (Left to right)
                    scroll_effect = 0;
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                }
            }
            break;

        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            break;

        case DBG_FAC:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                led_lighting_mode = LED_MODE_NORMAL;
                led_edge_brightness = 1;
                led_edge_mode = LED_EDGE_MODE_ALL;
                led_animation_breathing = 0;
                led_animation_id = 7; // led_programs.c led_setups leds_white index
                gcr_desired = LED_GCR_MAX;
                I2C3733_Control_Set(1);
            }
            break;

        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            break;

        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            break;

        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            break;

        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            break;

        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= BOOTKEY_HOLD_MS) {
                    reset_keyboard();
                }
            }
            break;

        default:
            return true; // Process all other keycodes normally
    }

    return false;
}

led_instruction_t led_instructions[] = {
    // LEDs are normally inactive, no processing is performed on them
    // Flags are used in matching criteria for an LED to be active and indicate how to color it
    // Flags can be found in tmk_core/protocol/arm_atsam/led_matrix.h (prefixed with LED_FLAG_)
    // LED IDs can be found in config_led.h in the keyboard's directory
    // Examples are below

    // All LEDs use the user's selected pattern (this is the factory default)
    { .flags = LED_FLAG_USE_ROTATE_PATTERN },

    // Specific LEDs use the user's selected pattern while all others are off
    /* { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id0 = 0xFFFFFFFF, .id1 = 0xAAAAAAAA, .id2 = 0x55555555, .id3 = 0x11111111 }, */

    // Specific LEDs use specified RGB values while all others are off
    /* { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFF, .id1 = 0x00FF, .id2 = 0x0000FF00, .id3 = 0xFF000000, .r = 75, .g = 150, .b = 225 }, */

    // All LEDs use the user's selected pattern
    // On layer 1, all key LEDs (except the top row which keeps active pattern) are red while all edge LEDs are green
    // When layer 1 is active, key LEDs use red     (id0  32 -  17: 1111 1111 1111 1111 0000 0000 0000 0000 = 0xFFFF0000) (except top row 16 - 1)
    // When layer 1 is active, key LEDs use red     (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    // When layer 1 is active, key LEDs use red     (id2  87 -  65: 0000 0000 0111 1111 1111 1111 1111 1111 = 0x007FFFFF)
    // When layer 1 is active, edge LEDs use green  (id2  95 -  88: 1111 1111 1000 0000 0000 0000 0000 0000 = 0xFF800000)
    // When layer 1 is active, edge LEDs use green  (id3 119 -  96: 0000 0000 1111 1111 1111 1111 1111 1111 = 0x00FFFFFF)
    /* { .flags = LED_FLAG_USE_ROTATE_PATTERN }, */
    /* { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0xFFFF0000, .id1 = 0xFFFFFFFF, .id2 = 0x007FFFFF, .r = 255, .layer = 1 }, */
    /* { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id2 = 0xFF800000, .id3 = 0x00FFFFFF, .g = 127, .layer = 1 }, */

    // All key LEDs use red while edge LEDs use the active pattern
    // All key LEDs use red      (id0  32 -   1: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    // All key LEDs use red      (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    // All key LEDs use red      (id2  87 -  65: 0000 0000 0111 1111 1111 1111 1111 1111 = 0x007FFFFF)
    // Edge uses active pattern  (id2  95 -  88: 1111 1111 1000 0000 0000 0000 0000 0000 = 0xFF800000)
    // Edge uses active pattern  (id3 119 -  96: 0000 0000 1111 1111 1111 1111 1111 1111 = 0x00FFFFFF)
    /* { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFFFFFFFF, .id1 = 0xFFFFFFFF, .id2 = 0x007FFFFF, .r = 255 }, */
    /* { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN , .id2 = 0xFF800000, .id3 = 0x00FFFFFF }, */

    // end must be set to 1 to indicate end of instruction set
    { .end = 1 }
};
