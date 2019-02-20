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

#define __BASE 0 // L0 - default layer
#define __TEST 1 // L1 - testing layer for new keymaps
#define __SYMB 2 // L2 - symbols
#define __ARRO 3 // L3 - arrows
#define __MDIA 4 // L4 - mouse & media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,    // can always be here
  EPRM,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap L0: Basic layer
 *
 * ,---------------------------------------------------.           ,---------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  ~L1  |           |       |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+--------------|           |-------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  | E/L2 | R/L3 |   T  |   [   |           |   ]   |   Y  |   U  | I/L2 |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|       |           |       |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |-------|           |-------|   H  |   J  |   K  |   L  | ;/L4 |   '    |
 * |--------+------+------+------+------+------|   <   |           |   >   |------+------+------+------+------+--------|
 * | Shft-( |   Z  |   X  |   C  |   V  |   B  |       |           |       |   N  |   M  |   ,  |   .  |  /   | Shft-) |
 * `--------+------+------+------+------+--------------'           `--------------+------+------+------+------+--------'
 *   |Esc/L2|      | Ctrl |  Alt | LGui |                                         |  Up  | Down |   [  |   ]  | ~L2  |
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.         ,-------------.
 *                                        |      |      |         |      |  ~L3 |
 *                                 ,------|------|------|         |------+------+------.
 *                                 |      |      | Home |         | PgUp |      |      |
 *                                 | Space|Backsp|------|         |------| Tab  |Enter |
 *                                 |      |ace   | End  |         | PgDn |      |      |
 *                                 `--------------------'         `--------------------'
 */
  [__BASE] = LAYOUT_ergodox(
    // left hand
    KC_GRV,            KC_1,         KC_2,         KC_3,            KC_4,              KC_5,         TG(__TEST),
    KC_TAB,            KC_Q,         KC_W,         LT(__SYMB,KC_E), LT(__ARRO,KC_R),   KC_T,         KC_LBRC,
    KC_LCTL,           KC_A,         KC_S,         KC_D,            KC_F,              KC_G,
    KC_LSPO,           KC_Z,         KC_X,         KC_C,            KC_V,              KC_B,         KC_LABK,
    LT(__SYMB,KC_ESC), XXXXXXX,      KC_LCTL,      KC_LALT,         KC_LCMD,
                                                                          XXXXXXX,      XXXXXXX,
                                                                                        KC_HOME,
                                                            KC_SPC,       KC_BSPC,      KC_END,
        // right hand
        XXXXXXX,      KC_6,         KC_7,         KC_8,            KC_9,         KC_0,              KC_MINS,
        KC_RBRC,      KC_Y,         KC_U,         LT(__SYMB,KC_I), KC_O,         KC_P,              KC_EQL,
                      KC_H,         KC_J,         KC_K,            KC_L,         LT(__MDIA,KC_SCLN),KC_QUOT,
        KC_RABK,      KC_N,         KC_M,         KC_COMM,         KC_DOT,       KC_SLSH,           KC_RSPC,
                                    KC_UP,        KC_DOWN,         KC_LBRC,      KC_RBRC,           TT(__SYMB),
        XXXXXXX,      TT(__ARRO),
        KC_PGUP,
        KC_PGDN,      KC_TAB,       KC_ENT
    ),

/* Keymap L1: Testing Layer - Completely overwrites Base
 *
 * ,---------------------------------------------------.           ,---------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | _____ |           |       |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+--------------|           |-------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  | E/L2 | R/L3 |   T  |   [   |           |   ]   |   Y  |   U  | I/L2 |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|       |           |       |------+------+------+------+------+--------|
 * | Ctrl   |   A  |S/Ctrl| D/Alt| F/Cmd|   G  |-------|           |-------|   H  | J/Cmd| K/Alt|L/Ctrl| ;/L4 |   '    |
 * |--------+------+------+------+------+------|   <   |           |   >   |------+------+------+------+------+--------|
 * | Shft-( |   Z  |   X  |   C  |   V  |   B  |       |           |       |   N  |   M  |   ,  |   .  |  /   | Shft-) |
 * `--------+------+------+------+------+--------------'           `--------------+------+------+------+------+--------'
 *   |Esc/L2| ~L3  |      |      |Shft-(|                                         |Shft-)|  _   |   [  | ]/L3 | ~L2  |
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.         ,-------------.
 *                                        |      |      |         |      |  ~L3 |
 *                                 ,------|------|------|         |------+------+------.
 *                                 |      |      | Home |         | PgUp |      |      |
 *                                 | Space|Backsp|------|         |------| Tab  |Enter |
 *                                 |      |ace   | End  |         | PgDn |      |      |
 *                                 `--------------------'         `--------------------'
 */
  [__TEST] = LAYOUT_ergodox(
    // left hand
    KC_GRV,            KC_1,         KC_2,         KC_3,            KC_4,              KC_5,         _______,
    KC_TAB,            KC_Q,         KC_W,         LT(__SYMB,KC_E), LT(__ARRO, KC_R),  KC_T,         KC_LBRC,
    KC_LCTL,           KC_A,         LCTL_T(KC_S), LALT_T(KC_D),    LCMD_T(KC_F),      KC_G,
    KC_LSPO,           KC_Z,         KC_X,         KC_C,            KC_V,              KC_B,         KC_LABK,
    LT(__SYMB,KC_ESC), TT(__ARRO),   XXXXXXX,      XXXXXXX,         KC_LSPO,
                                                                          XXXXXXX,      XXXXXXX,
                                                                                        KC_HOME,
                                                            KC_SPC,       KC_BSPC,      KC_END,
        // right hand
        XXXXXXX,      KC_6,         KC_7,         KC_8,            KC_9,         KC_0,                KC_MINS,
        KC_RBRC,      KC_Y,         KC_U,         LT(__SYMB,KC_I), KC_O,         KC_P,                KC_EQL,
                      KC_H,         RCMD_T(KC_J), RALT_T(KC_K),    RCTL_T(KC_L), LT(__MDIA,KC_SCLN),  KC_QUOT,
        KC_RABK,      KC_N,         KC_M,         KC_COMM,         KC_DOT,       KC_SLSH,             KC_RSPC,
                                    KC_RSPC,      KC_UNDS,         KC_LBRC,      LT(__ARRO, KC_RBRC), TT(__SYMB),
        XXXXXXX,      TT(__ARRO),
        KC_PGUP,
        KC_PGDN,      KC_TAB,       KC_ENT
    ),
/* Keymap L2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,---------------------------------------------------.
 * |  Esc   |      |      |      |      |      |       |           |       |      |      |   -  |   =  |  /   |        |
 * |--------+------+------+------+------+--------------|           |-------+------+------+------+------+------+--------|
 * | ______ |   !  |   #  |   {  |   }  |   |  |       |           |       |      |   7  |   8  |   9  |  *   |        |
 * |--------+------+------+------+------+------|       |           |       |------+------+------+------+------+--------|
 * | ______ |   @  |\/Ctrl| [/Alt| ]/Cmd|   `  |-------|           |-------|   $  | 4/Cmd| 5/Alt|6/Ctrl|  -   | Enter  |
 * |--------+------+------+------+------+------|       |           |       |------+------+------+------+------+--------|
 * | ______ |   %  |   ^  |   <  |   >  |   ~  |       |           |       |   &  |   1  |   2  |   3  |  +   | ______ |
 * `--------+------+------+------+------+--------------'           `--------------+------+------+------+------+--------'
 *   | ____ |      |      |   (  |   )  |                                         |   0  |   .  |      |      | ____ |
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.         ,-------------.
 *                                        |Animat|      |         |Toggle|Solid |
 *                                 ,------|------|------|         |------+------+------.
 *                                 |      |      |Brite+|         | Hue+ |      |      |
 *                                 | ____ | ____ |------|         |------| ____ | ____ |
 *                                 |      |      |Brite-|         | Hue- |      |      |
 *                                 `--------------------'         `--------------------'
 *
 */
  [__SYMB] = LAYOUT_ergodox(
    // left hand
    KC_ESC,       XXXXXXX,      XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,      XXXXXXX,
    _______,      KC_EXLM,      KC_HASH,         KC_LCBR,         KC_RCBR,         KC_PIPE,      XXXXXXX,
    _______,      KC_AT,        LCTL_T(KC_BSLS), LALT_T(KC_LBRC), LCMD_T(KC_RBRC), KC_GRV,
    _______,      KC_PERC,      KC_CIRC,         KC_LABK,         KC_RABK,         KC_TILD,      XXXXXXX,
    _______,      XXXXXXX,      XXXXXXX,         KC_LPRN,         KC_RPRN,
                                                                          RGB_MOD,      XXXXXXX,
                                                                                        RGB_VAI,
                                                            _______,      _______,      RGB_VAD,
        // right hand
        XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_MINS,      KC_EQL,       KC_PSLS,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      KC_7,         KC_8,         KC_9,         KC_PAST,      XXXXXXX,
                      KC_DLR,       RCMD_T(KC_4), RALT_T(KC_5), RCTL_T(KC_6), KC_PMNS,      KC_PENT,
        XXXXXXX,      KC_AMPR,      KC_1,         KC_2,         KC_3,         KC_PPLS,      _______,
                                    KC_P0,        KC_DOT,       XXXXXXX,      XXXXXXX,      _______,
        RGB_TOG,      RGB_SLD,
        RGB_HUI,
        RGB_HUD,      _______,      _______
    ),

/* Keymap L3: Arrow
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | Home |PgDown| PgUp | End  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ______ |      | Ctrl |  Alt | Cmd  |      |------|           |------| Left | Down |  Up  |Right |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ______ |      |      |      |      |      |      |           |      |      |      |  Up  |      |      | ______ |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | ____ | ____ |                                       | Left | Down | Right|      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      | ____ |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |ScBrt+|       |      |      |      |
 *                                 | ____ | ____ |------|       |------| ____ | ____ |
 *                                 |      |      |ScBrt-|       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [__ARRO] = LAYOUT_ergodox(
    // left hand
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
    _______,      XXXXXXX,      KC_LCTL,      KC_LALT,      KC_LCMD,      XXXXXXX,
    _______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,      _______,
                                                                          XXXXXXX,      XXXXXXX,
                                                                                        KC_F15,
                                                            _______,      _______,      KC_F14,
        // right hand
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      KC_HOME,      KC_PGDN,      KC_PGUP,      KC_END,       XXXXXXX,      XXXXXXX,
                      KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_UP,        XXXXXXX,      XXXXXXX,      _______,
                                    KC_LEFT,      KC_DOWN,      KC_RGHT,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      _______,
        XXXXXXX,
        XXXXXXX,      _______,      _______
    ),

/* Keymap L4: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |Accel0|Accel1|Accel2| ____ |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | W-Dn | W-Up |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
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
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_WH_D,      KC_WH_U,      XXXXXXX,      XXXXXXX,
    XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_BTN1,      KC_BTN2,
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

#define LED_ergodox(           \
    L01, L02, L03, L04, L05,   \
    L11, L12, L13, L14, L15,   \
    L21, L22, L23, L24, L25,   \
    L31, L32, L33, L34, L35,   \
    L41, L42, L43, L44,        \
                               \
    R01, R02, R03, R04, R05,   \
    R11, R12, R13, R14, R15,   \
    R21, R22, R23, R24, R25,   \
    R31, R32, R33, R34, R35,   \
         R42, R43, R44, R45    \
    )                          \
    { /* Right hand */         \
    R01, R02, R03, R04, R05,   \
    R11, R12, R13, R14, R15,   \
    R21, R22, R23, R24, R25,   \
    R31, R32, R33, R34, R35,   \
         R42, R43, R44, R45,   \
                               \
      /* Left hand reverse */  \
    L05, L04, L03, L02, L01,   \
    L15, L14, L13, L12, L11,   \
    L25, L24, L23, L22, L21,   \
    L35, L34, L33, L32, L31,   \
         L44, L43, L42, L41    \
    }

#define LED_______OFF_______ {  0,  0,  0}
#define LED_HSV(  H,  S,  V) {  H,  S,  V}

// Desert Sun color scheme
#define LED__DesSun_Blue____ {141,255,233}
#define LED__DesSun_Orange__ { 14,255,255}
#define LED__DesSun_Tan_____ { 30, 96,255}
#define LED__DesSun_Yellow__ { 33,255,255}

// Material color scheme
#define LED__Mtrl___Green___ { 85,203,158}
#define LED__Mtrl___Red_____ {243,222,234}
#define LED__Mtrl___Yellow__ { 32,176,255}

// Sunset color scheme
#define LED__Sunset_Blue____ {180,255,233}
#define LED__Sunset_DarkRed_ {255,220,201}
#define LED__Sunset_Orange__ { 14,222,242}
#define LED__Sunset_Purple__ {205,255,255}
#define LED__Sunset_LiteRed_ {233,218,217}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][4] = {
    // LED L2: Symbol Layer
    [__SYMB] = LED_ergodox(
        // Left hand
        LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______,
        LED__Sunset_Purple__, LED__Sunset_Purple__, LED__Sunset_LiteRed_, LED__Sunset_LiteRed_, LED__Sunset_Purple__,
        LED__Sunset_Purple__, LED__Sunset_Purple__, LED__Sunset_LiteRed_, LED__Sunset_LiteRed_, LED__Sunset_Purple__,
        LED__Sunset_Purple__, LED__Sunset_Purple__, LED__Sunset_LiteRed_, LED__Sunset_LiteRed_, LED__Sunset_Purple__,
        LED_______OFF_______, LED_______OFF_______, LED__Sunset_LiteRed_, LED__Sunset_LiteRed_,

        // Right hand
        LED_______OFF_______, LED_______OFF_______, LED__Sunset_Blue____, LED__Sunset_Blue____, LED__Sunset_Blue____,
        LED_______OFF_______, LED__Sunset_DarkRed_, LED__Sunset_DarkRed_, LED__Sunset_DarkRed_, LED__Sunset_Blue____,
        LED__Sunset_Purple__, LED__Sunset_DarkRed_, LED__Sunset_DarkRed_, LED__Sunset_DarkRed_, LED__Sunset_Blue____,
        LED__Sunset_Purple__, LED__Sunset_DarkRed_, LED__Sunset_DarkRed_, LED__Sunset_DarkRed_, LED__Sunset_Blue____,
                              LED__Sunset_DarkRed_, LED__Sunset_Blue____, LED_______OFF_______, LED_______OFF_______
    ),

    // LED L3: Arrow
    [__ARRO] = LED_ergodox(
        // Left hand
        LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______,
        LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______,
        LED_______OFF_______, LED__Sunset_DarkRed_, LED__Sunset_DarkRed_, LED__Sunset_DarkRed_, LED_______OFF_______,
        LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______,
        LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______,

        // Right hand
        LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______,
        LED__Sunset_LiteRed_, LED__Sunset_LiteRed_, LED__Sunset_LiteRed_, LED__Sunset_LiteRed_, LED_______OFF_______,
        LED__Sunset_Orange__, LED__Sunset_Orange__, LED__Sunset_Orange__, LED__Sunset_Orange__, LED_______OFF_______,
        LED_______OFF_______, LED_______OFF_______, LED__Sunset_Orange__, LED_______OFF_______, LED_______OFF_______,
                              LED__Sunset_Orange__, LED__Sunset_Orange__, LED__Sunset_Orange__, LED_______OFF_______
    ),

    // LED L4: Media and mouse keys
    [__MDIA] = LED_ergodox(
        // Left hand
        LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______,
        LED_______OFF_______, LED_______OFF_______, LED__DesSun_Orange__, LED_______OFF_______, LED_______OFF_______,
        LED_______OFF_______, LED__DesSun_Orange__, LED__DesSun_Orange__, LED__DesSun_Orange__, LED_______OFF_______,
        LED_______OFF_______, LED_______OFF_______, LED__DesSun_Yellow__, LED__DesSun_Yellow__, LED_______OFF_______,
        LED_______OFF_______, LED_______OFF_______, LED__DesSun_Tan_____, LED__DesSun_Tan_____,

        // Right hand
        LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______,
        LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______, LED_______OFF_______,
        LED_______OFF_______, LED__Mtrl___Red_____, LED__Mtrl___Yellow__, LED__Mtrl___Green___, LED_______OFF_______,
        LED_______OFF_______, LED_______OFF_______, LED__DesSun_Blue____, LED__DesSun_Blue____, LED_______OFF_______,
                              LED__DesSun_Yellow__, LED__DesSun_Tan_____, LED__DesSun_Orange__, LED_______OFF_______
    ),

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
      case __TEST:
        rgb_matrix_mode_noeeprom(1);
        // Sunset.Blue for testing!
        HSV hsv = {
          .h = 180,
          .s = 255,
          .v = 233
        };
        RGB rgb = hsv_to_rgb( hsv );
        rgb_matrix_set_color_all( rgb.r, rgb.g, rgb.b );
        break;

      case __SYMB:
      case __ARRO:
      case __MDIA:
        set_leds_color(layer);
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
/*
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
*/
      default:
        break;
    }
    return state;

};
