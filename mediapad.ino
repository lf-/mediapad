#include <stdint.h>

#include "HID-Project.h"

#include <Key.h>
#include <Keypad.h>

const uint8_t rows = 4;
const uint8_t cols = 3;
char keys[rows][cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

uint8_t rowPins[rows] = {1, 6, 5, 3};
uint8_t colPins[cols] = {2, 0, 4};

Keypad kp = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void setup() {
  Serial.begin(9600);
  Consumer.begin();
  Keyboard.begin();
}

void loop() {
  char key = kp.getKey();

  if (key) {
    switch (key) {
    case '4':
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F22);
      Keyboard.release(KEY_LEFT_CTRL);
      break;
    case '5':
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F23);
      Keyboard.release(KEY_LEFT_CTRL);
      break;
    case '6':
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F24);
      Keyboard.release(KEY_LEFT_CTRL);
      break;
    case '7':
      Consumer.write(MEDIA_VOLUME_DOWN);
      break;
    case '8':
      Consumer.write(MEDIA_VOLUME_MUTE);
      break;
    case '9':
      Consumer.write(MEDIA_VOLUME_UP);
      break;
    case '*':
      Consumer.write(MEDIA_PREV);
      break;
    case '0':
      Consumer.write(MEDIA_PLAY_PAUSE);
      break;
    case '#':
      Consumer.write(MEDIA_NEXT);
      break;
    default:
      break;
    }
    Serial.println(key);
  }
}
