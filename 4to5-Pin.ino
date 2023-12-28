#include "DigiKeyboard.h"

int num[] = {39, 30, 31, 32, 33, 34, 35, 36, 37, 38};
int digits[] = {0, 0, 0, 0, 0}; // Array to hold digits
int count = 0;
bool useFiveDigits = false;

void setup() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0); // Helps prevent missing the first character after a delay
  delay(3000);
}

void loop() {
  if (count == 5) {
    triggerRetry(); // Retry after 5 attempts
    count = 0;
  }

  if (useFiveDigits) {
    for (int i = 0; i < 5; ++i) {
      DigiKeyboard.sendKeyStroke(num[digits[i]]);
    }
  } else {
    for (int i = 0; i < 4; ++i) {
      DigiKeyboard.sendKeyStroke(num[digits[i]]);
    }
  }
  
  DigiKeyboard.sendKeyStroke(40); // Send Enter key
  delay(1000);

  incrementDigits();
  count++;
}

void triggerRetry() {
  digitalWrite(1, HIGH); // Change this to 0 if using DigiSpark model B
  DigiKeyboard.sendKeyStroke(40); // Send Enter to dismiss the popup
  delay(31000);
  digitalWrite(1, LOW);
}

void incrementDigits() {
  if (useFiveDigits) {
    digits[4]++;

    for (int i = 4; i > 0; --i) {
      if (digits[i] == 10) {
        digits[i] = 0;
        digits[i - 1]++;
      }
    }

    if (digits[0] == 10) {
      useFiveDigits = false;
      digits[0] = 0;
    }
  } else {
    digits[3]++;

    for (int i = 3; i > 0; --i) {
      if (digits[i] == 10) {
        digits[i] = 0;
        digits[i - 1]++;
      }
    }

    if (digits[0] == 10) {
      useFiveDigits = true;
      for (int i = 0; i < 5; ++i) {
        digits[i] = 0;
      }
    }
  }
}
