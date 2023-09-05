/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 @Kulllerkeks

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
//#include <stdio.h>
//#include "keymap_german.h"

#define _LayerBase 0    //base layer, alpha keys and homerow mods           --finished
#define _LayerNav 2     //arrowkeys on the right side, mods on the left     --nearly finished
#define _LayerProg 3    //special chars and stuff                           --changes number keys to numpad keys
#define _LayerNumb 4    //numpad on the right,                              --open
#define _LayerMacro 5   //copy, paste and co                                --open
#define _LayerGame 6    //game layer with wasd and common mods on the left  --open
#define _LayerGame2 7   //numbers and function keys on the left             --open
#define _LayerMouse 8   //mouse keys and back button                        --open
#define _LayerQud 9     //qaves of qud layer with numpad and common keys    --open


enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
};

// base layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LayerBase] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------------------.                    ,---------------------------------------------------------------------------------------------------.
      KC_TAB,     DE_Q,         DE_W,         DE_E,          DE_R,        DE_T,                        DE_Z, DE_U,         DE_I,         DE_O,         DE_P,            DE_UDIA,
  //|--------------+-------------------+-----------------+-----------------+----------------+-----------|                    |----------+----------------+------------------+-----------------+--------------------+-------------|
      KC_PEQL,    LGUI_T(DE_A), LALT_T(DE_S), LCTL_T(DE_D), LSFT_T(DE_F), DE_G,                        DE_H, LSFT_T(DE_J), LCTL_T(DE_K), LALT_T(DE_L), LGUI_T(DE_ODIA), DE_ADIA,
  //|--------------+-------------------+-----------------+-----------------+----------------+-----------|                    |----------+----------------+------------------+-----------------+--------------------+-------------|
      KC_LSFT,    DE_Y,         DE_X,         DE_C,         DE_V,         DE_B,                        DE_N, DE_M,         DE_COMM,      DE_DOT,       DE_MINS,         KC_ESC,
  //|--------------+-------------------+-----------------+-----------------+----------------+-----------|                    |----------+----------------+------------------+-----------------+--------------------+-------------|
                      MO(_LayerMacro),   LT(_LayerNav,KC_SPC),  LT(_LayerNumb,KC_BSPC),                            LT(_LayerMacro,KC_TAB),   LT(_LayerProg,KC_ENT),   KC_ESC
                    //`--------------------------------------------------------------------------------'                     `--------------------------------------------------------------------------------'
  ),

  [_LayerNav] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------------------------------.                    ,---------------------------------------------------------------------------------------------------.
      KC_NO,    KC_F5,         KC_F9,         KC_F11,        KC_F10,    KC_F12,                        KC_DEL,  KC_HOME,     KC_UP,         KC_END,         KC_WH_U,     KC_NO,
  //|--------------+-------------------+-----------------+-----------------+----------------+-----------|                    |----------+----------------+------------------+-----------------+--------------------+-------------|
      KC_NO,    KC_LGUI,       KC_LALT,       KC_LCTL,       KC_LSFT,   KC_NO,                         KC_NO,   KC_LEFT,     KC_DOWN,       KC_RGHT,        KC_WH_D,     KC_NO,
  //|--------------+-------------------+-----------------+-----------------+----------------+-----------|                    |----------+----------------+------------------+-----------------+--------------------+-------------|
      KC_NO,    KC_NO,         KC_NO,         KC_NO,         KC_NO,     KC_NO,                         DE_N,    DE_M,        DE_COMM,       DE_DOT,         DE_MINS,     KC_NO,
  //|--------------+-------------------+-----------------+-----------------+----------------+-----------|                    |----------+----------------+------------------+-----------------+--------------------+-------------|
                         KC_NO,           KC_TRNS,               KC_NO,                                            KC_NO,           KC_NO,           KC_ESC
                    //`--------------------------------------------------------------------------------'                     `--------------------------------------------------------------------------------'
  ),

  [_LayerProg] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,  DE_EXLM, DE_AT,   DE_HASH, DE_DLR,  DE_PERC,                     DE_CIRC, DE_AMPR, DE_ASTR, DE_SLSH, DE_UNDS, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, DE_DQUO, DE_LPRN, DE_RPRN, DE_LCBR, DE_RCBR,                     DE_MINS,  DE_EQL, DE_SCLN, DE_COLN, DE_BSLS, DE_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, DE_EURO, DE_TILD, DE_PIPE, DE_LBRC, DE_RBRC,                     DE_PLUS, DE_PLUS, DE_ACUT, DE_QUES, DE_LABK, DE_RABK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        LCTL_T(KC_LGUI),   KC_SPC,  MO(_LayerNumb),   KC_TRNS, LCTL_T(KC_ENT), KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_LayerNumb] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TO(_LayerGame), KC_NO,  KC_NO,  KC_NO,  KC_NO,  DE_PERC,                   DE_PLUS,   KC_P7,   KC_P8,   KC_P9,   DE_ASTR,   KC_NUM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,    KC_NO,     KC_NO,  KC_NO,  DE_SS,  KC_NO,                       DE_MINS,   KC_P4,   KC_P5,   KC_P6,   DE_SLSH,   DE_DOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TO(_LayerBase),    KC_NO,     KC_NO,  KC_NO,  KC_NO,  KC_NO,                       KC_P0,      KC_P1,   KC_P2,   KC_P3,   DE_COMM,   DE_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|     |--------+--------+--------+--------+--------+--------+--------|
                                 LCTL_T(KC_LGUI), KC_TRNS,  KC_TRNS,      KC_TRNS , KC_ENT, KC_LALT
                                      //`--------------------------'     `--------------------------'
  ),

  [_LayerGame] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,     DE_T,   DE_Q,    DE_W,    DE_E,   DE_R,                         DE_Z,   DE_U,   DE_I,    DE_O,   DE_P,    DE_UDIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,     DE_G,   DE_A,    DE_S,    DE_D,   DE_F,                         DE_H,   DE_J,   DE_K,    DE_L,   DE_ODIA, DE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    DE_B,   DE_Y,    DE_X,    DE_C,   DE_V,                         DE_N,   DE_M,   DE_COMM, DE_DOT, DE_MINS, DE_AT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LCTL, KC_SPC,MO(_LayerGame2),  KC_LALT, KC_ENT,  KC_BSPC
                                      //`--------------------------'  `-----------z---------------'
  ),

  [_LayerGame2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ENT,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_SPC,  KC_TRNS,   TO(_LayerBase),   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  [_LayerMouse] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO, KC_NO,   KC_NO,   KC_NO, KC_MS_BTN2, KC_MS_WH_UP,              KC_MS_BTN1, KC_MS_BTN2, KC_NO,   KC_NO,   KC_NO,    KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_NO,  KC_MS_BTN4, KC_MS_BTN5, KC_MS_BTN1, KC_MS_WH_DOWN,         KC_NO,  KC_NO,      KC_NO,   KC_NO,   KC_NO,    KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_NO,   KC_NO,   KC_NO, KC_MS_BTN3, KC_NO,                        KC_NO,  KC_NO,      KC_NO,   KC_NO,   KC_NO,    KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                               LCTL_T(KC_LGUI), LT(_LayerNav,KC_SPC),  KC_LSFT,   KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on

#ifdef OLED_ENABLE

/* clean black screen */
static const char PROGMEM cleanScreen [512] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };


// 'Layer Image Game', 32x11px
static const char PROGMEM layerImageGame [64] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xde, 0x8e, 0xde, 0xfe, 0xfc, 0xfc, 0x6c, 0x7c,
	0x6c, 0xfc, 0xfc, 0xde, 0xfe, 0x76, 0xfe, 0xdc, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Layer Image Nav', 32x11px
static const char PROGMEM layerImageNav [64] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x70, 0xf8, 0xac, 0x26, 0x22, 0x20, 0x20, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x20, 0x20, 0x22, 0x26, 0xac, 0xf8, 0x70, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Layer Image Prog', 32x11px
static const char PROGMEM layerImageProg [64] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x05, 0x55, 0x05, 0x55, 0x05, 0x55, 0x05, 0x55, 0x05,
	0x55, 0x05, 0x55, 0x05, 0x55, 0x05, 0xfd, 0x05, 0x05, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x05, 0x04, 0x05, 0x04, 0x05, 0x04, 0x05, 0x04,
	0x05, 0x04, 0x05, 0x04, 0x05, 0x04, 0x07, 0x04, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Layer Image Base', 32x11px
static const char PROGMEM layerImageBase [64] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0xf8, 0x0c, 0xc6, 0xc3, 0x01,
	0xe3, 0xe6, 0x0c, 0xfe, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0,
	0x06, 0x06, 0x04, 0x04, 0x04, 0x05, 0x07, 0x05, 0x04, 0x04, 0x04, 0x07, 0x04, 0x07, 0x07, 0x04,
	0x04, 0x04, 0x04, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x07, 0x06, 0x04, 0x07, 0x04
};
// 'Layer Image Numb', 32x11px
static const char PROGMEM layerImageNumb [64] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x05, 0x55, 0x05, 0x55,
	0x05, 0x55, 0x05, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x05, 0x04, 0x05,
	0x04, 0x05, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Layer Image Game2', 32x11px
static const char PROGMEM layerImageGame2 [64] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xde, 0x8e, 0xde, 0xfe, 0xfc, 0xfc, 0x6c, 0x7c,
	0x6c, 0xfc, 0xfc, 0xde, 0xfe, 0x76, 0xfe, 0xdc, 0xf8, 0x00, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM layerImageMouse[64] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x04, 0x02, 0x1a,
	0x02, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x04, 0x0c,
	0x14, 0x14, 0x13, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Clean Layer Image', 32x11px
static const char PROGMEM layerImageClean [64] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;
bool isBarking = false;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (isBarking) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }

    /* this fixes the screen on and off bug */
    /*
    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_set_cursor(0,0);
        oled_write_raw_P(cleanScreen, sizeof(cleanScreen));
        oled_off();
        oled_set_cursor(LUNA_X,LUNA_Y);
    }
    */
}

/* KEYBOARD PET END */

static void print_status_narrow(void) {
    /* Print current layer */
    oled_set_cursor(0,0);
    oled_write("LAYER", false);

    switch (get_highest_layer(layer_state)) {
        case _LayerBase:
            oled_set_cursor(0, 4);
            oled_write_raw_P(layerImageClean, sizeof(layerImageClean));
            oled_write_raw_P(layerImageBase, sizeof(layerImageBase));
            oled_set_cursor(0, 7);
            oled_write(" Base  ", false);
            oled_set_cursor(0, 9);
            oled_write("     ", false);
            break;
        case _LayerNav:
            oled_set_cursor(0, 4);
            oled_write_raw_P(layerImageClean, sizeof(layerImageClean));
            oled_write_raw_P(layerImageNav, sizeof(layerImageNav));
            oled_set_cursor(0, 7);
            oled_write(" Nav  ", false);
            oled_set_cursor(0, 9);
            oled_write("     ", false);
            break;
        case _LayerProg:
            oled_set_cursor(0, 4);
            oled_write_raw_P(layerImageClean, sizeof(layerImageClean));
            oled_write_raw_P(layerImageProg, sizeof(layerImageProg));
            oled_set_cursor(0, 7);
            oled_write(" Prog   ", false);
            oled_set_cursor(0, 9);
            oled_write("     ", false);
            break;
        case _LayerNumb:
            oled_set_cursor(0, 4);
            oled_write_raw_P(layerImageClean, sizeof(layerImageClean));
            oled_write_raw_P(layerImageNumb, sizeof(layerImageNumb));
            oled_set_cursor(0, 7);
            oled_write(" Numb   ", false);
            oled_set_cursor(0, 9);
            oled_write("     ", false);
            break;
        case _LayerGame:
            oled_set_cursor(0, 4);
            oled_write_raw_P(layerImageClean, sizeof(layerImageClean));
            oled_write_raw_P(layerImageGame, sizeof(layerImageGame));
            oled_set_cursor(0, 7);
            oled_write(" Game  ", false);
            oled_set_cursor(0, 9);
            oled_write("     ", false);
            break;
        case _LayerGame2:
            oled_set_cursor(0, 4);
            oled_write_raw_P(layerImageClean, sizeof(layerImageClean));
            oled_write_raw_P(layerImageGame2, sizeof(layerImageGame2));
            oled_set_cursor(0, 7);
            oled_write(" Game ", false);
            oled_set_cursor(0, 9);
            oled_write("--2--", false);
            break;
        case _LayerMouse:
            oled_set_cursor(0, 4);
            oled_write_raw_P(layerImageClean, sizeof(layerImageClean));
            oled_write_raw_P(layerImageMouse, sizeof(layerImageMouse));
            oled_set_cursor(0, 7);
            oled_write(" Mous ", false);
            oled_set_cursor(0, 9);
            oled_write("     ", false);
            break;
        case _LayerMod:
            oled_set_cursor(0, 4);
            oled_write_raw_P(layerImageClean, sizeof(layerImageClean));
            oled_write_raw_P(layerImageBase, sizeof(layerImageBase));
            oled_set_cursor(0, 7);
            oled_write(" Mod  ", false);
            oled_set_cursor(0, 9);
            oled_write("     ", false);
            break;
    }

    /* KEYBOARD PET RENDER START */
    render_luna(0, 13);
    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */
    if (is_keyboard_master()) {
        print_status_narrow();
    }
    return false;
}

 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* KEYBOARD PET STATUS START */
        case KC_LCTL:
            isSneaking = record->event.pressed;
            break;
        case LCTL_T(KC_ENT):
            isSneaking = record->event.pressed;
            break;
        case KC_SPC:
            isJumping = record->event.pressed;
            if (isJumping) {
                showedJump = false;
            }
            break;
        case LT(_LayerNav,KC_SPC):
            isJumping = record->event.pressed;
            if (isJumping) {
                showedJump = false;
            }
            break;
        case KC_LSFT:
            isBarking = record->event.pressed;
            break;
        /* KEYBOARD PET STATUS END */
    }
    return true;
}
#endif

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_LayerMouse);
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

