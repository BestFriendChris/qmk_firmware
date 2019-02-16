#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"

#define LCGS(code) LCTL(LGUI(LSFT(code)))
#define LCS(code) LCTL(LSFT(code))

#define __BASE 0 // default layer
#define __SYMB 1 // symbols
#define __ARRO 2 // arrows
#define __MDIA 3 // mouse & media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,    // can always be here
  EPRM,         
  RGB_SLD,      
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------------------.           ,---------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | XXXXX |           | XXXXX |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+--------------|           |-------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   [   |           |   ]   |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|       |           |       |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |-------|           |-------|   H  |   J  |   K  |   L  |; / L3|   '    |
 * |--------+------+------+------+------+------|   <   |           |   >   |------+------+------+------+------+--------|
 * | Shft-( |   Z  |   X  |   C  |   V  |   B  |       |           |       |   N  |   M  |   ,  |   .  |  /   | Shft-) |
 * `--------+------+------+------+------+--------------'           `--------------+------+------+------+------+--------'
 *   |Esc/L2|      | Ctrl |  Alt | LGui |                                         | RGui | Ctrl |   [  |   ]  | ~L2  |
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.         ,-------------.
 *                                        | ____ | ____ |         | ____ | ____ |
 *                                 ,------|------|------|         |------+------+------.
 *                                 |      |      | Home |         | PgUp |      |      |
 *                                 | Space|Backsp|------|         |------| Tab  |Enter |
 *                                 |      |ace   | End  |         | PgDn |      |      |
 *                                 `--------------------'         `--------------------'
 */
  [__BASE] = LAYOUT_ergodox(
    // left hand
    KC_GRV,            KC_1,         KC_2,         KC_3,         KC_4,              KC_5,         XXXXXXX,      
    KC_TAB,            KC_Q,         KC_W,         KC_E,         KC_R,              KC_T,         KC_LBRC,      
    KC_LCTL,           KC_A,         KC_S,         KC_D,         LT(__ARRO,KC_F),   KC_G,         
    KC_LSPO,           KC_Z,         KC_X,         KC_C,         KC_V,              KC_B,         KC_LABK,      
    LT(__SYMB,KC_ESC), XXXXXXX,      KC_LCTL,      KC_LALT,      KC_LCMD,      
                                                                          XXXXXXX,      XXXXXXX,      
                                                                                        KC_HOME,      
                                                            KC_SPC,       KC_BSPC,      KC_END,       
        // right hand
        XXXXXXX,      KC_6,         KC_7,         KC_8,         KC_9,         KC_0,              KC_MINS,      
        KC_RBRC,      KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,              KC_EQL,       
                      KC_H,         KC_J,         KC_K,         KC_L,         LT(__MDIA,KC_SCLN),KC_QUOT,      
        KC_RABK,      KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,           KC_RSPC,      
        KC_RCMD,      KC_RCTL,      KC_LBRC,      KC_RBRC,      TT(__SYMB),        
        XXXXXXX,      XXXXXXX,      
        KC_PGUP,      
        KC_PGDN,      KC_TAB,       KC_ENT
    ),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,---------------------------------------------------.
 * |  Esc   | ____ | ____ | ____ | ____ | ____ | _____ |           | _____ | ____ | ____ |   -  |   =  |  /   | ______ |
 * |--------+------+------+------+------+--------------|           |-------+------+------+------+------+------+--------|
 * |        |   !  |   #  |   {  |   }  |   |  | _____ |           | _____ | ____ |   7  |   8  |   9  |  *   | ______ |
 * |--------+------+------+------+------+------|       |           |       |------+------+------+------+------+--------|
 * |        |   @  |   $  |   <  |   >  |   `  |-------|           |-------|   \  |   4  |   5  |   6  |  -   | Enter  |
 * |--------+------+------+------+------+------| _____ |           | _____ |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |       |           |       |   &  |   1  |   2  |   3  |  +   | ______ |
 * `--------+------+------+------+------+--------------'           `--------------+------+------+------+------+--------'
 *   |      | ____ | Ctrl |  Alt | LGui |                                         |   0  |   .  | ____ | ____ |      |
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.         ,-------------.
 *                                        |Animat| ____ |         |Toggle|Solid |
 *                                 ,------|------|------|         |------+------+------.
 *                                 |Bright|Bright| ____ |         | ____ |Hue   |Hue   |
 *                                 |ness  |ness  |------|         |------|  -   |  +   |
 *                                 |  -   |  +   | ____ |         | ____ |      |      |
 *                                 `--------------------'         `--------------------'
 *
 */
  [__SYMB] = LAYOUT_ergodox(
    // left hand
    KC_ESC,       XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
    _______,      KC_EXLM,      KC_HASH,      KC_LCBR,      KC_RCBR,      KC_PIPE,      XXXXXXX,      
    _______,      KC_AT,        KC_DLR,       KC_LABK,      KC_RABK,      KC_GRV,       
    _______,      KC_PERC,      KC_CIRC,      KC_LBRC,      KC_RBRC,      KC_TILD,      XXXXXXX,      
    _______,      XXXXXXX,      KC_LCTRL,     KC_LALT,      KC_LCMD,      
                                                                          RGB_MOD,      XXXXXXX,      
                                                                                        XXXXXXX,      
                                                            RGB_VAD,      RGB_VAI,      XXXXXXX,      
        // right hand
        XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_MINS,      KC_EQL,       KC_PSLS,      XXXXXXX,      
        XXXXXXX,      XXXXXXX,      KC_7,         KC_8,         KC_9,         KC_PAST,      XXXXXXX,      
                      KC_BSLS,      KC_4,         KC_5,         KC_6,         KC_PMNS,      KC_PENT,      
        XXXXXXX,      KC_AMPR,      KC_1,         KC_2,         KC_3,         KC_PPLS,      XXXXXXX,      
        KC_P0,        KC_DOT,       XXXXXXX,      XXXXXXX,      _______,      
        RGB_TOG,      RGB_SLD,      
        XXXXXXX,      
        XXXXXXX,      RGB_HUD,      RGB_HUI
    ),

/* Keymap 2: Arrow
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | Home |PgDown| PgUp | End  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ______ |      |      |      | ____ |      |------|           |------| Left | Down |  Up  |Right |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | ____ | ____ |                                       | ____ | ____ |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |      |      |
 *                                 |  -   |  +   |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [__ARRO] = LAYOUT_ergodox(
    // left hand
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
    _______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,      XXXXXXX,      
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
    XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,      _______,      
                                                                          XXXXXXX,      XXXXXXX,      
                                                                                        XXXXXXX,      
                                                            KC_F14,       KC_F15,       XXXXXXX,      
        // right hand
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
        XXXXXXX,      KC_HOME,      KC_PGDN,      KC_PGUP,      KC_END,       XXXXXXX,      XXXXXXX,      
                      KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,      XXXXXXX,      XXXXXXX,      
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
        _______,      _______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
        XXXXXXX,      XXXXXXX,      
        XXXXXXX,      
        XXXXXXX,      XXXXXXX,      XXXXXXX
    ),

/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |Accel0|Accel1|Accel2| ____ |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | W-Up | W-Dn |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk |      |------|       |------|      | Mute |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [__MDIA] = LAYOUT_ergodox(
    // left hand
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_MS_U,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
    XXXXXXX,      XXXXXXX,      KC_MS_L,      KC_MS_D,      KC_MS_R,      XXXXXXX,      
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_WH_U,      KC_WH_D,      XXXXXXX,      XXXXXXX,      
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_BTN2,      
                                                                          XXXXXXX,      XXXXXXX,      
                                                                                        XXXXXXX,      
                                                            KC_BTN1,      XXXXXXX,      XXXXXXX,      
        // right hand
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      
                      XXXXXXX,      KC_ACL0,      KC_ACL1,      KC_ACL2,      _______,      KC_MPLY,      
        XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_MPRV,      KC_MNXT,      XXXXXXX,      XXXXXXX,      
        KC_VOLU,      KC_VOLD,      KC_MUTE,      XXXXXXX,      XXXXXXX,      
        XXXXXXX,      XXXXXXX,      
        XXXXXXX,      
        XXXXXXX,      XXXXXXX,      KC_MUTE
    ),


};

bool suspended = false;
rgb_config_t rgb_matrix_config;

#define _____OFF_____ {  0,  0,  0}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [__SYMB] = {     // Right hand
                     _____OFF_____, _____OFF_____, {180,255,233}, {180,255,233}, {180,255,233},
                     _____OFF_____, {255,220,201}, {255,220,201}, {255,220,201}, {180,255,233},
                     {205,255,255}, {255,220,201}, {255,220,201}, {255,220,201}, {180,255,233},
                     {205,255,255}, {255,220,201}, {255,220,201}, {255,220,201}, {180,255,233},
                                    {255,220,201}, {180,255,233}, _____OFF_____, _____OFF_____,
      
      // Left hand reverse
      _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
      {205,255,255}, {233,218,217}, {233,218,217}, {205,255,255}, {205,255,255},
      {205,255,255}, {233,218,217}, {233,218,217}, {205,255,255}, {205,255,255},
      {205,255,255}, {233,218,217}, {233,218,217}, {205,255,255}, {205,255,255},
                     _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____
    },

    [__ARRO] = {     // Right hand
                     _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
                     {233,218,217}, {233,218,217}, {233,218,217}, {233,218,217}, _____OFF_____,
                     { 14,222,242}, { 14,222,242}, { 14,222,242}, { 14,222,242}, _____OFF_____,
                     _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
                                    _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
      
      // Left hand reverse
      _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
      _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
      _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
      _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
                     _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____
    },

    [__MDIA] = {     // Right hand
                     _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
                     _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
                     _____OFF_____, {243,222,234}, { 32,176,255}, { 85,203,158}, _____OFF_____,
                     _____OFF_____, _____OFF_____, {141,255,233}, {141,255,233}, _____OFF_____,
                                    { 33,255,255}, { 30, 96,255}, { 14,255,255}, _____OFF_____,
     
      // Left hand reverse
      _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____, _____OFF_____,
      _____OFF_____, _____OFF_____, { 14,255,255}, _____OFF_____, _____OFF_____,
      _____OFF_____, { 14,255,255}, { 14,255,255}, { 14,255,255}, _____OFF_____,
      _____OFF_____, { 33,255,255}, { 33,255,255}, _____OFF_____, _____OFF_____,
                     { 30, 96,255}, _____OFF_____, _____OFF_____, _____OFF_____
    },

};

void set_leds_color( int layer) {
  rgb_matrix_mode_noeeprom(1);
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    uint8_t val = pgm_read_byte(&ledmap[layer][i][2]);
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = val == 0 ? 0 : rgb_matrix_config.val
    };
    RGB rgb = hsv_to_rgb( hsv );
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

void rgb_matrix_indicators_user(void) {
  if(suspended == false) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
      case __BASE:
        rgb_matrix_config.raw = eeprom_read_dword(EECONFIG_RGB_MATRIX);
        rgb_matrix_mode_noeeprom(rgb_matrix_config.mode);
        if(rgb_matrix_config.mode != 1) {
          rgb_matrix_sethsv_noeeprom(rgb_matrix_config.hue, rgb_matrix_config.sat, rgb_matrix_config.val);
        }
        break;
      case __SYMB:
        set_leds_color(1);
        break;
      case __ARRO:
        set_leds_color(2);
        break;
      case __MDIA:
        set_leds_color(3);
        break;
    }
  }
}
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case __SYMB:
        ergodox_right_led_1_on();
        break;
      case __ARRO:
        ergodox_right_led_2_on();
        break;
      case __MDIA:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
