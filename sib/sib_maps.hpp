// Copyright (c) 2024 Bryan Rykowski
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include "sib.hpp"

static std::unordered_map<std::string, Uint8> str_to_cbuttons
({
	{"A",SDL_CONTROLLER_BUTTON_A},
	{"B",SDL_CONTROLLER_BUTTON_B},
	{"X",SDL_CONTROLLER_BUTTON_X},
	{"Y",SDL_CONTROLLER_BUTTON_Y},
	{"BACK",SDL_CONTROLLER_BUTTON_BACK},
	{"GUIDE",SDL_CONTROLLER_BUTTON_GUIDE},
	{"START",SDL_CONTROLLER_BUTTON_START},
	{"LEFTSTICK",SDL_CONTROLLER_BUTTON_LEFTSTICK},
	{"RIGHTSTICK",SDL_CONTROLLER_BUTTON_RIGHTSTICK},
	{"LEFTSHOULDER",SDL_CONTROLLER_BUTTON_LEFTSHOULDER},
	{"RIGHTSHOULDER",SDL_CONTROLLER_BUTTON_RIGHTSHOULDER},
	{"DPAD_UP",SDL_CONTROLLER_BUTTON_DPAD_UP},
	{"DPAD_DOWN",SDL_CONTROLLER_BUTTON_DPAD_DOWN},
	{"DPAD_LEFT",SDL_CONTROLLER_BUTTON_DPAD_LEFT},
	{"DPAD_RIGHT",SDL_CONTROLLER_BUTTON_DPAD_RIGHT},
	{"MISC1",SDL_CONTROLLER_BUTTON_MISC1},
	{"PADDLE1",SDL_CONTROLLER_BUTTON_PADDLE1},
	{"PADDLE2",SDL_CONTROLLER_BUTTON_PADDLE2},
	{"PADDLE3",SDL_CONTROLLER_BUTTON_PADDLE3},
	{"PADDLE4",SDL_CONTROLLER_BUTTON_PADDLE4},
	{"TOUCHPAD",SDL_CONTROLLER_BUTTON_TOUCHPAD} 
});

static std::unordered_map<std::string, Sib::Axis> str_to_caxis
({
	{"LEFTXPOS",Sib::Axis::Left_X_Pos},	
	{"LEFTXNEG",Sib::Axis::Left_X_Neg},	
	{"LEFTYPOS",Sib::Axis::Left_Y_Pos},
	{"LEFTYPOS",Sib::Axis::Left_Y_Pos},
	{"RIGHTXPOS",Sib::Axis::Right_X_Pos},
	{"RIGHTXNEG",Sib::Axis::Right_X_Neg},
	{"RIGHTYPOS",Sib::Axis::Right_Y_Pos},
	{"RIGHTYNEG",Sib::Axis::Right_Y_Neg},
	{"TRIGGERLEFT",Sib::Axis::Left_Trigger},
	{"TRIGGERRIGHT",Sib::Axis::Right_Trigger}
});

static std::unordered_map<std::string, SDL_Scancode> str_to_scancodes
({
	{"A",SDL_SCANCODE_A},
	{"B",SDL_SCANCODE_B},
	{"C",SDL_SCANCODE_C},
	{"D",SDL_SCANCODE_D},
	{"E",SDL_SCANCODE_E},
	{"F",SDL_SCANCODE_F},
	{"G",SDL_SCANCODE_G},
	{"H",SDL_SCANCODE_H},
	{"I",SDL_SCANCODE_I},
	{"J",SDL_SCANCODE_J},
	{"K",SDL_SCANCODE_K},
	{"L",SDL_SCANCODE_L},
	{"M",SDL_SCANCODE_M},
	{"N",SDL_SCANCODE_N},
	{"O",SDL_SCANCODE_O},
	{"P",SDL_SCANCODE_P},
	{"Q",SDL_SCANCODE_Q},
	{"R",SDL_SCANCODE_R},
	{"S",SDL_SCANCODE_S},
	{"T",SDL_SCANCODE_T},
	{"U",SDL_SCANCODE_U},
	{"V",SDL_SCANCODE_V},
	{"W",SDL_SCANCODE_W},
	{"X",SDL_SCANCODE_X},
	{"Y",SDL_SCANCODE_Y},
	{"Z",SDL_SCANCODE_Z},
	{"1",SDL_SCANCODE_1},
	{"2",SDL_SCANCODE_2},
	{"3",SDL_SCANCODE_3},
	{"4",SDL_SCANCODE_4},
	{"5",SDL_SCANCODE_5},
	{"6",SDL_SCANCODE_6},
	{"7",SDL_SCANCODE_7},
	{"8",SDL_SCANCODE_8},
	{"9",SDL_SCANCODE_9},
	{"0",SDL_SCANCODE_0},
	{"RETURN",SDL_SCANCODE_RETURN},
	{"ESCAPE",SDL_SCANCODE_ESCAPE},
	{"BACKSPACE",SDL_SCANCODE_BACKSPACE},
	{"TAB",SDL_SCANCODE_TAB},
	{"SPACE",SDL_SCANCODE_SPACE},
	{"MINUS",SDL_SCANCODE_MINUS},
	{"EQUALS",SDL_SCANCODE_EQUALS},
	{"LEFTBRACKET",SDL_SCANCODE_LEFTBRACKET},
	{"RIGHTBRACKET",SDL_SCANCODE_RIGHTBRACKET},
	{"BACKSLASH",SDL_SCANCODE_BACKSLASH},
	{"NONUSHASH",SDL_SCANCODE_NONUSHASH},
	{"SEMICOLON",SDL_SCANCODE_SEMICOLON},
	{"APOSTROPHE",SDL_SCANCODE_APOSTROPHE},
	{"GRAVE",SDL_SCANCODE_GRAVE},
	{"COMMA",SDL_SCANCODE_COMMA},
	{"PERIOD",SDL_SCANCODE_PERIOD},
	{"SLASH",SDL_SCANCODE_SLASH},
	{"CAPSLOCK",SDL_SCANCODE_CAPSLOCK},
	{"F1",SDL_SCANCODE_F1},
	{"F2",SDL_SCANCODE_F2},
	{"F3",SDL_SCANCODE_F3},
	{"F4",SDL_SCANCODE_F4},
	{"F5",SDL_SCANCODE_F5},
	{"F6",SDL_SCANCODE_F6},
	{"F7",SDL_SCANCODE_F7},
	{"F8",SDL_SCANCODE_F8},
	{"F9",SDL_SCANCODE_F9},
	{"F10",SDL_SCANCODE_F10},
	{"F11",SDL_SCANCODE_F11},
	{"F12",SDL_SCANCODE_F12},
	{"PRINTSCREEN",SDL_SCANCODE_PRINTSCREEN},
	{"SCROLLLOCK",SDL_SCANCODE_SCROLLLOCK},
	{"PAUSE",SDL_SCANCODE_PAUSE},
	{"INSERT",SDL_SCANCODE_INSERT},
	{"HOME",SDL_SCANCODE_HOME},
	{"PAGEUP",SDL_SCANCODE_PAGEUP},
	{"DELETE",SDL_SCANCODE_DELETE},
	{"END",SDL_SCANCODE_END},
	{"PAGEDOWN",SDL_SCANCODE_PAGEDOWN},
	{"RIGHT",SDL_SCANCODE_RIGHT},
	{"LEFT",SDL_SCANCODE_LEFT},
	{"DOWN",SDL_SCANCODE_DOWN},
	{"UP",SDL_SCANCODE_UP},
	{"NUMLOCKCLEAR",SDL_SCANCODE_NUMLOCKCLEAR},
	{"KP_DIVIDE",SDL_SCANCODE_KP_DIVIDE},
	{"KP_MULTIPLY",SDL_SCANCODE_KP_MULTIPLY},
	{"KP_MINUS",SDL_SCANCODE_KP_MINUS},
	{"KP_PLUS",SDL_SCANCODE_KP_PLUS},
	{"KP_ENTER",SDL_SCANCODE_KP_ENTER},
	{"KP_1",SDL_SCANCODE_KP_1},
	{"KP_2",SDL_SCANCODE_KP_2},
	{"KP_3",SDL_SCANCODE_KP_3},
	{"KP_4",SDL_SCANCODE_KP_4},
	{"KP_5",SDL_SCANCODE_KP_5},
	{"KP_6",SDL_SCANCODE_KP_6},
	{"KP_7",SDL_SCANCODE_KP_7},
	{"KP_8",SDL_SCANCODE_KP_8},
	{"KP_9",SDL_SCANCODE_KP_9},
	{"KP_0",SDL_SCANCODE_KP_0},
	{"KP_PERIOD",SDL_SCANCODE_KP_PERIOD},
	{"NONUSBACKSLASH",SDL_SCANCODE_NONUSBACKSLASH},
	{"APPLICATION",SDL_SCANCODE_APPLICATION},
	{"POWER",SDL_SCANCODE_POWER},
	{"KP_EQUALS",SDL_SCANCODE_KP_EQUALS},
	{"F13",SDL_SCANCODE_F13},
	{"F14",SDL_SCANCODE_F14},
	{"F15",SDL_SCANCODE_F15},
	{"F16",SDL_SCANCODE_F16},
	{"F17",SDL_SCANCODE_F17},
	{"F18",SDL_SCANCODE_F18},
	{"F19",SDL_SCANCODE_F19},
	{"F20",SDL_SCANCODE_F20},
	{"F21",SDL_SCANCODE_F21},
	{"F22",SDL_SCANCODE_F22},
	{"F23",SDL_SCANCODE_F23},
	{"F24",SDL_SCANCODE_F24},
	{"EXECUTE",SDL_SCANCODE_EXECUTE},
	{"HELP",SDL_SCANCODE_HELP},
	{"MENU",SDL_SCANCODE_MENU},
	{"SELECT",SDL_SCANCODE_SELECT},
	{"STOP",SDL_SCANCODE_STOP},
	{"AGAIN",SDL_SCANCODE_AGAIN},
	{"UNDO",SDL_SCANCODE_UNDO},
	{"CUT",SDL_SCANCODE_CUT},
	{"COPY",SDL_SCANCODE_COPY},
	{"PASTE",SDL_SCANCODE_PASTE},
	{"FIND",SDL_SCANCODE_FIND},
	{"MUTE",SDL_SCANCODE_MUTE},
	{"VOLUMEUP",SDL_SCANCODE_VOLUMEUP},
	{"VOLUMEDOWN",SDL_SCANCODE_VOLUMEDOWN},
	{"KP_COMMA",SDL_SCANCODE_KP_COMMA},
	{"KP_EQUALSAS400",SDL_SCANCODE_KP_EQUALSAS400},
	{"INTERNATIONAL1",SDL_SCANCODE_INTERNATIONAL1},
	{"INTERNATIONAL2",SDL_SCANCODE_INTERNATIONAL2},
	{"INTERNATIONAL3",SDL_SCANCODE_INTERNATIONAL3},
	{"INTERNATIONAL4",SDL_SCANCODE_INTERNATIONAL4},
	{"INTERNATIONAL5",SDL_SCANCODE_INTERNATIONAL5},
	{"INTERNATIONAL6",SDL_SCANCODE_INTERNATIONAL6},
	{"INTERNATIONAL7",SDL_SCANCODE_INTERNATIONAL7},
	{"INTERNATIONAL8",SDL_SCANCODE_INTERNATIONAL8},
	{"INTERNATIONAL9",SDL_SCANCODE_INTERNATIONAL9},
	{"LANG1",SDL_SCANCODE_LANG1},
	{"LANG2",SDL_SCANCODE_LANG2},
	{"LANG3",SDL_SCANCODE_LANG3},
	{"LANG4",SDL_SCANCODE_LANG4},
	{"LANG5",SDL_SCANCODE_LANG5},
	{"LANG6",SDL_SCANCODE_LANG6},
	{"LANG7",SDL_SCANCODE_LANG7},
	{"LANG8",SDL_SCANCODE_LANG8},
	{"LANG9",SDL_SCANCODE_LANG9},
	{"ALTERASE",SDL_SCANCODE_ALTERASE},
	{"SYSREQ",SDL_SCANCODE_SYSREQ},
	{"CANCEL",SDL_SCANCODE_CANCEL},
	{"CLEAR",SDL_SCANCODE_CLEAR},
	{"PRIOR",SDL_SCANCODE_PRIOR},
	{"RETURN2",SDL_SCANCODE_RETURN2},
	{"SEPARATOR",SDL_SCANCODE_SEPARATOR},
	{"OUT",SDL_SCANCODE_OUT},
	{"OPER",SDL_SCANCODE_OPER},
	{"CLEARAGAIN",SDL_SCANCODE_CLEARAGAIN},
	{"CRSEL",SDL_SCANCODE_CRSEL},
	{"EXSEL",SDL_SCANCODE_EXSEL},
	{"KP_00",SDL_SCANCODE_KP_00},
	{"KP_000",SDL_SCANCODE_KP_000},
	{"THOUSANDSSEPARATOR",SDL_SCANCODE_THOUSANDSSEPARATOR},
	{"DECIMALSEPARATOR",SDL_SCANCODE_DECIMALSEPARATOR},
	{"CURRENCYUNIT",SDL_SCANCODE_CURRENCYUNIT},
	{"CURRENCYSUBUNIT",SDL_SCANCODE_CURRENCYSUBUNIT},
	{"KP_LEFTPAREN",SDL_SCANCODE_KP_LEFTPAREN},
	{"KP_RIGHTPAREN",SDL_SCANCODE_KP_RIGHTPAREN},
	{"KP_LEFTBRACE",SDL_SCANCODE_KP_LEFTBRACE},
	{"KP_RIGHTBRACE",SDL_SCANCODE_KP_RIGHTBRACE},
	{"KP_TAB",SDL_SCANCODE_KP_TAB},
	{"KP_BACKSPACE",SDL_SCANCODE_KP_BACKSPACE},
	{"KP_A",SDL_SCANCODE_KP_A},
	{"KP_B",SDL_SCANCODE_KP_B},
	{"KP_C",SDL_SCANCODE_KP_C},
	{"KP_D",SDL_SCANCODE_KP_D},
	{"KP_E",SDL_SCANCODE_KP_E},
	{"KP_F",SDL_SCANCODE_KP_F},
	{"KP_XOR",SDL_SCANCODE_KP_XOR},
	{"KP_POWER",SDL_SCANCODE_KP_POWER},
	{"KP_PERCENT",SDL_SCANCODE_KP_PERCENT},
	{"KP_LESS",SDL_SCANCODE_KP_LESS},
	{"KP_GREATER",SDL_SCANCODE_KP_GREATER},
	{"KP_AMPERSAND",SDL_SCANCODE_KP_AMPERSAND},
	{"KP_DBLAMPERSAND",SDL_SCANCODE_KP_DBLAMPERSAND},
	{"KP_VERTICALBAR",SDL_SCANCODE_KP_VERTICALBAR},
	{"KP_DBLVERTICALBAR",SDL_SCANCODE_KP_DBLVERTICALBAR},
	{"KP_COLON",SDL_SCANCODE_KP_COLON},
	{"KP_HASH",SDL_SCANCODE_KP_HASH},
	{"KP_SPACE",SDL_SCANCODE_KP_SPACE},
	{"KP_AT",SDL_SCANCODE_KP_AT},
	{"KP_EXCLAM",SDL_SCANCODE_KP_EXCLAM},
	{"KP_MEMSTORE",SDL_SCANCODE_KP_MEMSTORE},
	{"KP_MEMRECALL",SDL_SCANCODE_KP_MEMRECALL},
	{"KP_MEMCLEAR",SDL_SCANCODE_KP_MEMCLEAR},
	{"KP_MEMADD",SDL_SCANCODE_KP_MEMADD},
	{"KP_MEMSUBTRACT",SDL_SCANCODE_KP_MEMSUBTRACT},
	{"KP_MEMMULTIPLY",SDL_SCANCODE_KP_MEMMULTIPLY},
	{"KP_MEMDIVIDE",SDL_SCANCODE_KP_MEMDIVIDE},
	{"KP_PLUSMINUS",SDL_SCANCODE_KP_PLUSMINUS},
	{"KP_CLEAR",SDL_SCANCODE_KP_CLEAR},
	{"KP_CLEARENTRY",SDL_SCANCODE_KP_CLEARENTRY},
	{"KP_BINARY",SDL_SCANCODE_KP_BINARY},
	{"KP_OCTAL",SDL_SCANCODE_KP_OCTAL},
	{"KP_DECIMAL",SDL_SCANCODE_KP_DECIMAL},
	{"KP_HEXADECIMAL",SDL_SCANCODE_KP_HEXADECIMAL},
	{"LCTRL",SDL_SCANCODE_LCTRL},
	{"LSHIFT",SDL_SCANCODE_LSHIFT},
	{"LALT",SDL_SCANCODE_LALT},
	{"LGUI",SDL_SCANCODE_LGUI},
	{"RCTRL",SDL_SCANCODE_RCTRL},
	{"RSHIFT",SDL_SCANCODE_RSHIFT},
	{"RALT",SDL_SCANCODE_RALT},
	{"RGUI",SDL_SCANCODE_RGUI},
	{"MODE",SDL_SCANCODE_MODE},
	{"AUDIONEXT",SDL_SCANCODE_AUDIONEXT},
	{"AUDIOPREV",SDL_SCANCODE_AUDIOPREV},
	{"AUDIOSTOP",SDL_SCANCODE_AUDIOSTOP},
	{"AUDIOPLAY",SDL_SCANCODE_AUDIOPLAY},
	{"AUDIOMUTE",SDL_SCANCODE_AUDIOMUTE},
	{"MEDIASELECT",SDL_SCANCODE_MEDIASELECT},
	{"WWW",SDL_SCANCODE_WWW},
	{"MAIL",SDL_SCANCODE_MAIL},
	{"CALCULATOR",SDL_SCANCODE_CALCULATOR},
	{"COMPUTER",SDL_SCANCODE_COMPUTER},
	{"AC_SEARCH",SDL_SCANCODE_AC_SEARCH},
	{"AC_HOME",SDL_SCANCODE_AC_HOME},
	{"AC_BACK",SDL_SCANCODE_AC_BACK},
	{"AC_FORWARD",SDL_SCANCODE_AC_FORWARD},
	{"AC_STOP",SDL_SCANCODE_AC_STOP},
	{"AC_REFRESH",SDL_SCANCODE_AC_REFRESH},
	{"AC_BOOKMARKS",SDL_SCANCODE_AC_BOOKMARKS},
	{"BRIGHTNESSDOWN",SDL_SCANCODE_BRIGHTNESSDOWN},
	{"BRIGHTNESSUP",SDL_SCANCODE_BRIGHTNESSUP},
	{"DISPLAYSWITCH",SDL_SCANCODE_DISPLAYSWITCH},
	{"KBDILLUMTOGGLE",SDL_SCANCODE_KBDILLUMTOGGLE},
	{"KBDILLUMDOWN",SDL_SCANCODE_KBDILLUMDOWN},
	{"KBDILLUMUP",SDL_SCANCODE_KBDILLUMUP},
	{"EJECT",SDL_SCANCODE_EJECT},
	{"SLEEP",SDL_SCANCODE_SLEEP},
	{"APP1",SDL_SCANCODE_APP1},
	{"APP2",SDL_SCANCODE_APP2}
});

static std::unordered_map<std::string, SDL_Keycode> str_to_keycodes
({
	{"RETURN",SDLK_RETURN},
	{"ESCAPE",SDLK_ESCAPE},
	{"BACKSPACE",SDLK_BACKSPACE},
	{"TAB",SDLK_TAB},
	{"SPACE",SDLK_SPACE},
	{"EXCLAIM",SDLK_EXCLAIM},
	{"QUOTEDBL",SDLK_QUOTEDBL},
	{"HASH",SDLK_HASH},
	{"PERCENT",SDLK_PERCENT},
	{"DOLLAR",SDLK_DOLLAR},
	{"AMPERSAND",SDLK_AMPERSAND},
	{"QUOTE",SDLK_QUOTE},
	{"LEFTPAREN",SDLK_LEFTPAREN},
	{"RIGHTPAREN",SDLK_RIGHTPAREN},
	{"ASTERISK",SDLK_ASTERISK},
	{"PLUS",SDLK_PLUS},
	{"COMMA",SDLK_COMMA},
	{"MINUS",SDLK_MINUS},
	{"PERIOD",SDLK_PERIOD},
	{"SLASH",SDLK_SLASH},
	{"0",SDLK_0},
	{"1",SDLK_1},
	{"2",SDLK_2},
	{"3",SDLK_3},
	{"4",SDLK_4},
	{"5",SDLK_5},
	{"6",SDLK_6},
	{"7",SDLK_7},
	{"8",SDLK_8},
	{"9",SDLK_9},
	{"COLON",SDLK_COLON},
	{"SEMICOLON",SDLK_SEMICOLON},
	{"LESS",SDLK_LESS},
	{"EQUALS",SDLK_EQUALS},
	{"GREATER",SDLK_GREATER},
	{"QUESTION",SDLK_QUESTION},
	{"AT",SDLK_AT},
	{"LEFTBRACKET",SDLK_LEFTBRACKET},
	{"BACKSLASH",SDLK_BACKSLASH},
	{"RIGHTBRACKET",SDLK_RIGHTBRACKET},
	{"CARET",SDLK_CARET},
	{"UNDERSCORE",SDLK_UNDERSCORE},
	{"BACKQUOTE",SDLK_BACKQUOTE},
	{"a",SDLK_a},
	{"b",SDLK_b},
	{"c",SDLK_c},
	{"d",SDLK_d},
	{"e",SDLK_e},
	{"f",SDLK_f},
	{"g",SDLK_g},
	{"h",SDLK_h},
	{"i",SDLK_i},
	{"j",SDLK_j},
	{"k",SDLK_k},
	{"l",SDLK_l},
	{"m",SDLK_m},
	{"n",SDLK_n},
	{"o",SDLK_o},
	{"p",SDLK_p},
	{"q",SDLK_q},
	{"r",SDLK_r},
	{"s",SDLK_s},
	{"t",SDLK_t},
	{"u",SDLK_u},
	{"v",SDLK_v},
	{"w",SDLK_w},
	{"x",SDLK_x},
	{"y",SDLK_y},
	{"z",SDLK_z},
	{"CAPSLOCK",SDLK_CAPSLOCK},
	{"F1",SDLK_F1},
	{"F2",SDLK_F2},
	{"F3",SDLK_F3},
	{"F4",SDLK_F4},
	{"F5",SDLK_F5},
	{"F6",SDLK_F6},
	{"F7",SDLK_F7},
	{"F8",SDLK_F8},
	{"F9",SDLK_F9},
	{"F10",SDLK_F10},
	{"F11",SDLK_F11},
	{"F12",SDLK_F12},
	{"PRINTSCREEN",SDLK_PRINTSCREEN},
	{"SCROLLLOCK",SDLK_SCROLLLOCK},
	{"PAUSE",SDLK_PAUSE},
	{"INSERT",SDLK_INSERT},
	{"HOME",SDLK_HOME},
	{"PAGEUP",SDLK_PAGEUP},
	{"DELETE",SDLK_DELETE},
	{"END",SDLK_END},
	{"PAGEDOWN",SDLK_PAGEDOWN},
	{"RIGHT",SDLK_RIGHT},
	{"LEFT",SDLK_LEFT},
	{"DOWN",SDLK_DOWN},
	{"UP",SDLK_UP},
	{"NUMLOCKCLEAR",SDLK_NUMLOCKCLEAR},
	{"KP_DIVIDE",SDLK_KP_DIVIDE},
	{"KP_MULTIPLY",SDLK_KP_MULTIPLY},
	{"KP_MINUS",SDLK_KP_MINUS},
	{"KP_PLUS",SDLK_KP_PLUS},
	{"KP_ENTER",SDLK_KP_ENTER},
	{"KP_1",SDLK_KP_1},
	{"KP_2",SDLK_KP_2},
	{"KP_3",SDLK_KP_3},
	{"KP_4",SDLK_KP_4},
	{"KP_5",SDLK_KP_5},
	{"KP_6",SDLK_KP_6},
	{"KP_7",SDLK_KP_7},
	{"KP_8",SDLK_KP_8},
	{"KP_9",SDLK_KP_9},
	{"KP_0",SDLK_KP_0},
	{"KP_PERIOD",SDLK_KP_PERIOD},
	{"APPLICATION",SDLK_APPLICATION},
	{"POWER",SDLK_POWER},
	{"KP_EQUALS",SDLK_KP_EQUALS},
	{"F13",SDLK_F13},
	{"F14",SDLK_F14},
	{"F15",SDLK_F15},
	{"F16",SDLK_F16},
	{"F17",SDLK_F17},
	{"F18",SDLK_F18},
	{"F19",SDLK_F19},
	{"F20",SDLK_F20},
	{"F21",SDLK_F21},
	{"F22",SDLK_F22},
	{"F23",SDLK_F23},
	{"F24",SDLK_F24},
	{"EXECUTE",SDLK_EXECUTE},
	{"HELP",SDLK_HELP},
	{"MENU",SDLK_MENU},
	{"SELECT",SDLK_SELECT},
	{"STOP",SDLK_STOP},
	{"AGAIN",SDLK_AGAIN},
	{"UNDO",SDLK_UNDO},
	{"CUT",SDLK_CUT},
	{"COPY",SDLK_COPY},
	{"PASTE",SDLK_PASTE},
	{"FIND",SDLK_FIND},
	{"MUTE",SDLK_MUTE},
	{"VOLUMEUP",SDLK_VOLUMEUP},
	{"VOLUMEDOWN",SDLK_VOLUMEDOWN},
	{"KP_COMMA",SDLK_KP_COMMA},
	{"KP_EQUALSAS400",SDLK_KP_EQUALSAS400},
	{"ALTERASE",SDLK_ALTERASE},
	{"SYSREQ",SDLK_SYSREQ},
	{"CANCEL",SDLK_CANCEL},
	{"CLEAR",SDLK_CLEAR},
	{"PRIOR",SDLK_PRIOR},
	{"RETURN2",SDLK_RETURN2},
	{"SEPARATOR",SDLK_SEPARATOR},
	{"OUT",SDLK_OUT},
	{"OPER",SDLK_OPER},
	{"CLEARAGAIN",SDLK_CLEARAGAIN},
	{"CRSEL",SDLK_CRSEL},
	{"EXSEL",SDLK_EXSEL},
	{"KP_00",SDLK_KP_00},
	{"KP_000",SDLK_KP_000},
	{"THOUSANDSSEPARATOR",SDLK_THOUSANDSSEPARATOR},
	{"DECIMALSEPARATOR",SDLK_DECIMALSEPARATOR},
	{"CURRENCYUNIT",SDLK_CURRENCYUNIT},
	{"CURRENCYSUBUNIT",SDLK_CURRENCYSUBUNIT},
	{"KP_LEFTPAREN",SDLK_KP_LEFTPAREN},
	{"KP_RIGHTPAREN",SDLK_KP_RIGHTPAREN},
	{"KP_LEFTBRACE",SDLK_KP_LEFTBRACE},
	{"KP_RIGHTBRACE",SDLK_KP_RIGHTBRACE},
	{"KP_TAB",SDLK_KP_TAB},
	{"KP_BACKSPACE",SDLK_KP_BACKSPACE},
	{"KP_A",SDLK_KP_A},
	{"KP_B",SDLK_KP_B},
	{"KP_C",SDLK_KP_C},
	{"KP_D",SDLK_KP_D},
	{"KP_E",SDLK_KP_E},
	{"KP_F",SDLK_KP_F},
	{"KP_XOR",SDLK_KP_XOR},
	{"KP_POWER",SDLK_KP_POWER},
	{"KP_PERCENT",SDLK_KP_PERCENT},
	{"KP_LESS",SDLK_KP_LESS},
	{"KP_GREATER",SDLK_KP_GREATER},
	{"KP_AMPERSAND",SDLK_KP_AMPERSAND},
	{"KP_DBLAMPERSAND",SDLK_KP_DBLAMPERSAND},
	{"KP_VERTICALBAR",SDLK_KP_VERTICALBAR},
	{"KP_DBLVERTICALBAR",SDLK_KP_DBLVERTICALBAR},
	{"KP_COLON",SDLK_KP_COLON},
	{"KP_HASH",SDLK_KP_HASH},
	{"KP_SPACE",SDLK_KP_SPACE},
	{"KP_AT",SDLK_KP_AT},
	{"KP_EXCLAM",SDLK_KP_EXCLAM},
	{"KP_MEMSTORE",SDLK_KP_MEMSTORE},
	{"KP_MEMRECALL",SDLK_KP_MEMRECALL},
	{"KP_MEMCLEAR",SDLK_KP_MEMCLEAR},
	{"KP_MEMADD",SDLK_KP_MEMADD},
	{"KP_MEMSUBTRACT",SDLK_KP_MEMSUBTRACT},
	{"KP_MEMMULTIPLY",SDLK_KP_MEMMULTIPLY},
	{"KP_MEMDIVIDE",SDLK_KP_MEMDIVIDE},
	{"KP_PLUSMINUS",SDLK_KP_PLUSMINUS},
	{"KP_CLEAR",SDLK_KP_CLEAR},
	{"KP_CLEARENTRY",SDLK_KP_CLEARENTRY},
	{"KP_BINARY",SDLK_KP_BINARY},
	{"KP_OCTAL",SDLK_KP_OCTAL},
	{"KP_DECIMAL",SDLK_KP_DECIMAL},
	{"KP_HEXADECIMAL",SDLK_KP_HEXADECIMAL},
	{"LCTRL",SDLK_LCTRL},
	{"LSHIFT",SDLK_LSHIFT},
	{"LALT",SDLK_LALT},
	{"LGUI",SDLK_LGUI},
	{"RCTRL",SDLK_RCTRL},
	{"RSHIFT",SDLK_RSHIFT},
	{"RALT",SDLK_RALT},
	{"RGUI",SDLK_RGUI},
	{"MODE",SDLK_MODE},
	{"AUDIONEXT",SDLK_AUDIONEXT},
	{"AUDIOPREV",SDLK_AUDIOPREV},
	{"AUDIOSTOP",SDLK_AUDIOSTOP},
	{"AUDIOPLAY",SDLK_AUDIOPLAY},
	{"AUDIOMUTE",SDLK_AUDIOMUTE},
	{"MEDIASELECT",SDLK_MEDIASELECT},
	{"WWW",SDLK_WWW},
	{"MAIL",SDLK_MAIL},
	{"CALCULATOR",SDLK_CALCULATOR},
	{"COMPUTER",SDLK_COMPUTER},
	{"AC_SEARCH",SDLK_AC_SEARCH},
	{"AC_HOME",SDLK_AC_HOME},
	{"AC_BACK",SDLK_AC_BACK},
	{"AC_FORWARD",SDLK_AC_FORWARD},
	{"AC_STOP",SDLK_AC_STOP},
	{"AC_REFRESH",SDLK_AC_REFRESH},
	{"AC_BOOKMARKS",SDLK_AC_BOOKMARKS},
	{"BRIGHTNESSDOWN",SDLK_BRIGHTNESSDOWN},
	{"BRIGHTNESSUP",SDLK_BRIGHTNESSUP},
	{"DISPLAYSWITCH",SDLK_DISPLAYSWITCH},
	{"KBDILLUMTOGGLE",SDLK_KBDILLUMTOGGLE},
	{"KBDILLUMDOWN",SDLK_KBDILLUMDOWN},
	{"KBDILLUMUP",SDLK_KBDILLUMUP},
	{"EJECT",SDLK_EJECT},
	{"SLEEP",SDLK_SLEEP}
});

static std::unordered_map<std::string,Uint8> str_to_mbuttons
({
	{"LEFT",SDL_BUTTON_LEFT},
	{"MIDDLE",SDL_BUTTON_MIDDLE},
	{"RIGHT",SDL_BUTTON_RIGHT},
	{"X1",SDL_BUTTON_X1},
	{"X2",SDL_BUTTON_X2}
});

