/**
 * @class rune::Keyboard
 * @brief This class allows for access to the keyboard.
 *
 * @author Thomas Montano
 * @date May 13 2020
 */

#pragma once
#include "core.h"
#include <gameApplication.h>

namespace rune{

class RUNE_ENGINE Keyboard
{

public: 

///A keyboard key that can be used to get input.
enum Key
{
  ///Unhandled key.
  UNKNOWN = -1,
  ///The Space bar.
  SPACE = 32,
  ///The ' key.
  APOSTROPHE = 39,
  ///The , key.
  COMMA = 44,
  ///The - key.
  DASH = 45,
  ///The . key.
  PERIOD = 46,
  ///The / key.
  SLASH = 47,
  ///The 0 key.
  Num0 = 48,
  ///The 1 key.
  Num1 = 49,
  ///The 2 key.
  Num2 = 50,
  ///The 3 key.
  Num3 = 51,
  ///The 4 key.
  Num4 = 52,
  ///The 5 key.
  Num5 = 53,
  ///The 6 key.
  Num6 = 54,
  ///The 7 key.
  Num7 = 55,
  ///The 8 key.
  Num8 = 56,
  ///The 9 key.
  Num9 = 57,
  ///The ; key.
  SEMICOLON = 59,
  ///The = key.
  EQUAL = 61,
  ///The A key.
  A = 65,
  ///The B key.
  B = 66,
  ///The C key.
  C = 67,
  ///The D key.
  D = 68,
  ///The E key.
  E = 69,
  ///The F key.
  F = 70,
  ///The G key.
  G = 71,
  ///The H key.
  H = 72,
  ///The I key.
  I = 73,
  ///The J key.
  J = 74,
  ///The K key.
  K = 75,
  ///The L key.
  L = 76,
  ///The M key.
  M = 77,
  ///The N key.
  N = 78,
  ///The O key.
  O = 79,
  ///The P key.
  P = 80,
  ///The Q key.
  Q = 81,
  ///The R key.
  R = 82,
  ///The S key.
  S = 83,
  ///The T key.
  T = 84,
  ///The U key.
  U = 85,
  ///The V key.
  V = 86,
  ///The W key.
  W = 87,
  ///The X key.
  X = 88,
  ///The Y key.
  Y = 89,
  ///The Z key.
  Z = 90,
  ///The [ key.
  LEFT_BRACKET = 91,
  ///The \ key.
  BACKSLASH = 92,
  ///The ] key.
  RIGHT_BRACKET = 93,
  ///The ~ key.
  GRAVE_ACCENT = 96,
  ///The Esc key.
  ESCAPE = 256,
  ///The Enter key.
  ENTER = 257,
  ///The Tab key.
  TAB = 258,
  ///The Backspace key.
  BACKSPACE = 259,
  ///The Ins key.
  INSERT = 260,
  ///The Del key.
  DELETE = 261,
  ///The Right Arrow key. 
  RIGHT = 262,
  ///The Left Arrow key. 
  LEFT = 263,
  ///The Down Arrow key.  
  DOWN = 264,
  ///The Up Arrow key.  
  UP = 265,
  ///The Page Up key.  
  PAGE_UP = 266,
  ///The Page Down key.  
  PAGE_DOWN = 267,
  ///The Home key.  
  HOME = 268,
  ///The End key.  
  END = 269,
  ///The Caps Lock key.  
  CAPS_LOCK = 280,
  ///The Scroll Lock key.  
  SCROLL_LOCK = 281,
  ///The Number Lock key.  
  NUM_LOCK = 282,
  ///The Print Screen Key.  
  PRINT_SCREEN = 283,
  ///The F1 key.  
  F1 = 290,
  ///The F2 key.  
  F2 = 291,
  ///The F3 key.  
  F3 = 292,
  ///The F4 key.  
  F4 = 293,
  ///The F5 key.  
  F5 = 294,
  ///The F6 key.  
  F6 = 295,
  ///The F7 key.  
  F7 = 296,
  ///The F8 key.  
  F8 = 297,
  ///The F9 key.  
  F9 = 298,
  ///The F10 key.  
  F10 = 299,
  ///The F11 key.  
  F11 = 300,
  ///The F12 key.  
  F12 = 301,
  ///The numpad 0 key.
 	NUMPAD0 = 320,
  ///The numpad 1 key.
  NUMPAD1 = 321,
  ///The numpad 2 key.
  NUMPAD2 = 322,
  ///The numpad 3 key.
  NUMPAD3 = 323,
  ///The numpad 4 key.
  NUMPAD4 = 324,
  ///The numpad 5 key.
  NUMPAD5 = 325,
  ///The numpad 6 key.
  NUMPAD6 = 326,
  ///The numpad 7 key.
  NUMPAD7 = 327,
  ///The numpad 8 key.
  NUMPAD8 = 328,
  ///The numpad 9 key.
  NUMPAD9 = 329,
  ///The numpad decimal key.
  NUMPADDECIMAL = 330,
  ///The numpad slash key.
  NUMPADDIVIDE = 331,
  ///The numpad * key.
  NUMPADMULTIPLY = 332,
  ///The numpad - key.
  NUMPADSUBTRACT = 333,
  ///The numpad + key.
  NUMPADADD = 334,
  ///The numpad enter key.
  NUMPADENTER = 335,
  ///The Left Shift key.  
  LEFT_SHIFT = 340,
  ///The Left Control key.  
  LEFT_CONTROL = 341,
  ///The Left Alt key.  
  LEFT_ALT = 342,
  ///The Right Shift key.  
  RIGHT_SHIFT = 344,
  ///The Right Control Key. 
  RIGHT_CONTROL = 345,
  ///The Right Alt Key.  
  RIGHT_ALT = 346
};

  ///Determines whether or not the key is being pressed.
  static bool isKeyPressed(Key);

};

}