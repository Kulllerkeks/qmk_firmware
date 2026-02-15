/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 @Kulllerkeks


Todo:
    -convert aseprite animations to usable codes and implement them in arrays in animation.c
    -compile fitmware as is without animation.c to see if everything works
    -dail in tapterm settings for homerow mods

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_german.h"
//#include "animation.c"
//#include <stdio.h>
//#include "keymap_german.h"

#define _LayerBase 0    //base layer, alpha keys and homerow mods           --finished
#define _LayerNav 2     //arrowkeys on the right side, mods on the left     --nearly finished
#define _LayerProg 3    //special chars and stuff                           --finished
#define _LayerNumb 4    //numpad on the right,                              --finished
#define _LayerMacro 5   //copy, paste and co                                --finished
#define _LayerSpec 6    //Special chars                                     --finished, dont know whats missing
#define _LayerSelect 7  //Special Layer selection and multimedia keys       --finished
#define _LayerGame 8    //game layer with wasd and common mods on the left  --finished
#define _LayerGame2 9   //numbers and function keys on the left             --finished
#define _LayerMouse 10  //mouse keys and back button                        --finished
#define _LayerQud 11    //qaves of qud layer with numpad and common keys    --open


// Custom Keycodes
// Left-hand home row mods
#define HOME_A LGUI_T(DE_A)
#define HOME_S LALT_T(DE_S)
#define HOME_D LCTL_T(DE_D)
#define HOME_F LSFT_T(DE_F)

// Right-hand home row mods
#define HOME_J LSFT_T(DE_J)
#define HOME_K LCTL_T(DE_K)
#define HOME_L LALT_T(DE_L)
#define HOME_ODI RGUI_T(DE_ODIA)

// Layer
#define ESC_MAC LT(_LayerMacro,KC_ESC)
#define NAV_SPC LT(_LayerNav,KC_SPC)
#define NUM_BSPC LT(_LayerNumb,KC_BSPC)
#define MAC_TAB LT(_LayerMacro,KC_TAB)
#define PRO_ENT LT(_LayerProg,KC_ENT)
#define SPEC_ESC LT(_LayerSpec,KC_ESC)
#define MO_SPEC MO(_LayerSpec)
#define MO_SEL MO(_LayerSelect)
#define TO_GAME TO(_LayerGame)
#define TO_QUD TO(_LayerQud)

//Macros
#define M_COPY LCTL(KC_C)
#define M_CUT LCTL(KC_X)
#define M_PASTE LCTL(KC_V)
#define M_REWI LCTL(DE_Z)
#define M_REDO LCTL(DE_Y)

//Mouse
#define MS_LEFT MS_BTN1
#define MS_RIGH MS_BTN2
#define MS_B3 MS_BTN3
#define MS_B4 MS_BTN4
#define MS_B5 MS_BTN5

#define MS_WUP QK_MOUSE_WHEEL_UP
#define MS_WDO QK_MOUSE_WHEEL_DOWN

// base layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LayerBase] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                         DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      HOME_A,  HOME_S,  HOME_D,  HOME_F,  DE_G,                         DE_H,    HOME_J,  HOME_K,  HOME_L,  HOME_ODI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,                         DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                              MO(_LayerMacro),   NAV_SPC,  NUM_BSPC,    MAC_TAB,  PRO_ENT,  SPEC_ESC
                            //`--------------------------'  `--------------------------'
  ),

  [_LayerNav] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_F5,   KC_F9,   KC_F11,  KC_F10,  KC_F12,                       KC_DEL,  KC_HOME,  KC_UP,  KC_END,  MS_WHLU,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TAB,                       KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, MS_WHLD,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                              KC_NO,  KC_TRNS,  NUM_BSPC,     MAC_TAB,  PRO_ENT,  KC_ESC
                            //`--------------------------'  `--------------------------'
  ),

  [_LayerProg] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      DE_EXLM, DE_AT,   DE_SLSH, DE_DLR,  DE_PERC,                      DE_ASTR, DE_PLUS, DE_MINS, DE_SLSH, DE_COLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      DE_EQL,  DE_LCBR, DE_RCBR, DE_LPRN, DE_RPRN,                      DE_SCLN, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      DE_DQUO, DE_LABK, DE_RABK, DE_LBRC, DE_RBRC,                      DE_QUES, DE_UNDS, DE_PERC, DE_BSLS, DE_HASH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                               KC_NO,  MO_SPEC,  NUM_BSPC,     MAC_TAB,  KC_TRNS,  KC_ESC
                            //`--------------------------'  `--------------------------'
  ),

  [_LayerNumb] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_NUM,  KC_NO,   KC_NO,   DE_PERC, KC_NO,                        DE_PLUS, KC_P7,   KC_P8,   KC_P9,   DE_ASTR,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, DE_DOT,                       DE_MINS, KC_P4,   KC_P5,   KC_P6,   DE_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_NO,   KC_NO,   DE_DLR,  DE_EURO, KC_PENT,                      KC_P0,   KC_P1,   KC_P2,   KC_P3,   DE_COMM,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_NO,   NAV_SPC,  KC_TRNS,   MAC_TAB,   PRO_ENT,   KC_ESC
                            //`--------------------------'  `--------------------------'
  ),

  [_LayerMacro] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     M_COPY,  M_CUT,   KC_NO,   M_PASTE, KC_F11,                        KC_F12, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     M_REWI,  KC_NO,   KC_NO,   KC_NO,   M_REDO,                        KC_CAPS,KC_INS,  KC_PSCR, KC_NO,   KC_NUM,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_NO,   KC_NO,   MO_SEL,      KC_TRNS, KC_NO,   KC_NO
                            //`--------------------------'  `--------------------------'
  ),

  [_LayerSpec] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   DE_UDIA, KC_NO,   DE_ODIA, KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     DE_ADIA, DE_SS,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                              KC_NO,   KC_TRNS,  NUM_BSPC,    MAC_TAB,   KC_TRNS,   KC_ESC
                            //`--------------------------'  `--------------------------'
  ),

  [_LayerSelect] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     TO_GAME, KC_NO,   KC_NO,   KC_NO,   TO_QUD,                       KC_NO,   KC_VOLD, KC_VOLU,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_MPLY, KC_MPRV, KC_MNXT, KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                              KC_NO,   KC_NO,   KC_TRNS,    KC_TRNS, KC_NO,   KC_NO
                            //`--------------------------'  `--------------------------'
  ),

  [_LayerGame] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_ESC,  DE_Q,    DE_W,    DE_E,   DE_R,                          DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_TAB,  DE_A,    DE_S,    DE_D,   DE_F,                          DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, DE_Y,    DE_X,    DE_C,   DE_V,                          DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                            KC_LCTL, KC_SPC,MO(_LayerGame2),   KC_LALT, KC_ENT,  KC_BSPC
                            //`--------------------------'  `--------------------------'
  ),

  [_LayerGame2] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      DE_M,    DE_B,    DE_G,    DE_T,    KC_ENT,                       KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                KC_LCTL, KC_SPC,  KC_TRNS,   TO(_LayerBase),   KC_NO,   KC_NO
                            //`--------------------------'  `--------------------------'
  ),

  [_LayerMouse] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_NO,   MS_B5,   MS_B4,   MS_B3,   MS_WUP,                       MS_LEFT, MS_RIGH, KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_NO,   KC_NO,   MS_RIGH, MS_LEFT, MS_WDO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_NO ,KC_NO,  KC_LSFT,     KC_LCTL,  KC_NO,   KC_NO
                            //`--------------------------'  `--------------------------'
  ),

  [_LayerQud] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 KC_NO,   KC_NO,  KC_NO,      TO(_LayerBase),KC_NO,   KC_NO
                            //`--------------------------'  `--------------------------'
  )
};
// clang-format on

#ifdef OLED_ENABLE
#endif

/*
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_LayerMouse);
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}
*/
