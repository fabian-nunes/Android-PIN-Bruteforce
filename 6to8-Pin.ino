#include "DigiKeyboard.h"

const int num[] = {39, 30, 31, 32, 33, 34, 35, 36, 37, 38};
int digits[] = {0, 0, 0, 0, 0, 0, 0, 0}; // Array to hold digits
int count = 0;
bool useEightDigits = false;

void setup() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  delay(3000);
}

void loop() {
  if (count == 5) {
    triggerRetry();
    count = 0;
  }

  sendDigits();

  if (useEightDigits) {
    DigiKeyboard.sendKeyStroke(num[digits[6]]);
    DigiKeyboard.sendKeyStroke(num[digits[7]]);
  }

  DigiKeyboard.sendKeyStroke(40);
  delay(1000);
  
  incrementDigits();
  count++;
}

void triggerRetry() {
  digitalWrite(1, HIGH);
  DigiKeyboard.sendKeyStroke(40);
  delay(31000);
  digitalWrite(1, LOW);
}

void sendDigits() {
  for (int i = 0; i < 6; ++i) {
    DigiKeyboard.sendKeyStroke(num[digits[i]]);
  }
}

void incrementDigits() {
  for (int i = 5; i >= 0; --i) {
    digits[i]++;

    if (digits[i] == 10) {
      digits[i] = 0;
    } else {
      break;
    }
  }

  if (digits[0] == 10) {
    useEightDigits = true;
    for (int i = 0; i < 8; ++i) {
      digits[i] = 0;
    }
  }
}
