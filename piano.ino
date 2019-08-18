/*
 * Info: keys range from 21 to 108. Mapping from left to right:
 * 0: 21 - 35 (sheild pins 0-14)
 * 1: 36 - 50 (sheild pins 0-14)
 * 2: 51 - 65 (sheild pins 0-14)
 * 3: 66 - 80 (sheild pins 0-14)
 * 4: 81 - 95 (sheild pins 0-14)
 * 5: 96 - 108 (sheild pins 0-12)
 */

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// sheild controllers from left to right
Adafruit_PWMServoDriver pwm[] = {
  Adafruit_PWMServoDriver(&Wire, 0x40),
  Adafruit_PWMServoDriver(&Wire, 0x41),
  Adafruit_PWMServoDriver(&Wire, 0x42),
  Adafruit_PWMServoDriver(&Wire, 0x43),
  Adafruit_PWMServoDriver(&Wire, 0x44),
  Adafruit_PWMServoDriver(&Wire, 0x45)
};

// stores the MIDI key values of sharps and flats
int blackKeys[] = {22, 25, 27, 30, 32, 34, 37, 39, 42, 44, 46, 49, 
  51, 54, 56, 58, 61, 63, 66, 68, 70, 73, 75, 78, 80, 82, 85, 87, 
  90, 92, 94, 97, 99, 102, 104, 106};

// 1 if key is pressed, 0 otherwise
int keyPosition[88];

// Servo controls
#define SERVOMIN  300 // min pulse length for white keys
#define SERVOMAX  450 // max pulse length for white keys
#define BLACKMIN  400 // min pulse length for black keys
#define BLACKMAX  550 // max pulse length for black keys

void toggleBlackKey(int keyNum, Adafruit_PWMServoDriver driver, int num) {
  if (keyPosition[keyNum-21] == 0) {
    driver.setPWM(num, 0, BLACKMIN);
    keyPosition[keyNum-21] = 1;
  } else {
    driver.setPWM(num, 0, BLACKMAX);
    keyPosition[keyNum-21] = 0;
  }
}

void toggleWhiteKey(int keyNum, Adafruit_PWMServoDriver driver, int num) {
  if (keyPosition[keyNum-21] == 0) {
    driver.setPWM(num, 0, SERVOMIN);
    keyPosition[keyNum-21] = 1;
  } else {
    driver.setPWM(num, 0, SERVOMAX);
    keyPosition[keyNum-21] = 0;
  }
}

void toggleKey(int key) {
  boolean pressed = false;
  
  // check if key is in driver 0 range
    if (key >= 21 && key <= 35) {
      for (int i = 0; i < 36; i++) {
        if (blackKeys[i] == key) {
          toggleBlackKey(key, pwm[0], key - 21);
          pressed = true;
          break;
        }
      }
      if (!pressed) {
        toggleWhiteKey(key, pwm[0], key - 21);
      }
      
    // check if key is in driver 1 range
    } else if (key >= 36 && key <= 50) {
      for (int i = 0; i < 36; i++) {
        if (blackKeys[i] == key) {
          toggleBlackKey(key, pwm[1], key - 36);
          pressed = true;
          break;
        }
      }
      if (!pressed) {
        toggleWhiteKey(key, pwm[1], key - 36);
      }

    // check if key is in driver 2 range
    } else if (key >= 51 && key <= 65) {
      for (int i = 0; i < 36; i++) {
        if (blackKeys[i] == key) {
          toggleBlackKey(key, pwm[2], key - 51);
          pressed = true;
          break;
        }
      }
      if (!pressed) {
        toggleWhiteKey(key, pwm[2], key - 51);
      }

    // check if key is in driver 3 range
    } else if (key >= 66 && key <= 80) {
      for (int i = 0; i < 36; i++) {
        if (blackKeys[i] == key) {
          toggleBlackKey(key, pwm[3], key - 66);
          pressed = true;
          break;
        }
      }
      if (!pressed) {
        toggleWhiteKey(key, pwm[3], key - 66);
      }

    // check if key is in driver 4 range
    } else if (key >= 81 && key <= 95) {
      for (int i = 0; i < 36; i++) {
        if (blackKeys[i] == key) {
          toggleBlackKey(key, pwm[4], key - 81);
          pressed = true;
          break;
        }
      }
      if (!pressed) {
        toggleWhiteKey(key, pwm[4], key - 81);
      }

    // check if key is in driver 5 range
    } else if (key >= 96 && key <= 108) {
      for (int i = 0; i < 36; i++) {
        if (blackKeys[i] == key) {
          toggleBlackKey(key, pwm[5], key - 96);
          pressed = true;
          break;
        }
      }
      if (!pressed) {
        toggleWhiteKey(key, pwm[5], key - 96);
      }
    }
}

void setup() {
  Serial1.begin(9600); // setup serial 1 rx and tx

  // setup servos
  for (int i = 0; i < 6; i++) {
    pwm[i].begin();
    pwm[i].setPWMFreq(60); // servos at 60 Hz update
  }
  delay(10);
  for (int i = 0; i < 88; i++) {
    keyPosition[i] = 1;
  }

  for (int i = 21; i <= 108; i++) {
    toggleKey(i);
  }
}

void loop() {
  if (Serial1.available()) {
    int key = Serial1.parseInt();
    toggleKey(key);
  }
}
