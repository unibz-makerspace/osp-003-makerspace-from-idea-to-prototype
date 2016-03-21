#include "Timer.h"
#include <notes.h>
#include <rtttl.h>

Timer<> timer;

RamPlayer player(12); // Speaker on pin 12.

const char *song = "tetris:d=4,o=5,b=160:e6,8b,8c6,8d6,16e6,16d6,8c6,8b,a,8a,8c6,e6,8d6,8c6,b,8b,8c6,d6,e6,c6,a,2a,8p,d6,8f6,a6,8g6,8f6,e6,8e6,8c6,e6,8d6,8c6,b,8b,8c6,d6,e6,c6,a,a";

void led9() {
  static byte pwm = 192;
  static byte step = 1;
  if(pwm == 255) {
    step = -1;
  }
  if(pwm == 0) {
    step = 1;
  }
  pwm = pwm + step;
  analogWrite(9, pwm);
}

void led5() {
  static byte pwm = 128;
  static byte step = 1;
  if(pwm == 255) {
    step = -1;
  }
  if(pwm == 0) {
    step = 1;
  }
  pwm = pwm + step;
  analogWrite(5, pwm);
}

void led6() {
  static byte pwm = 64;
  static byte step = 1;
  if(pwm == 255) {
    step = -1;
  }
  if(pwm == 0) {
    step = 1;
  }
  pwm = pwm + step;
  analogWrite(6, pwm);
}

void led13() {
  digitalWrite(13, !digitalRead(13));
}

void setup() {
  for(int i = 0; i < 19; i++) {
    pinMode(13, INPUT_PULLUP);
  }
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  timer.setInterval(led9, 1);
  timer.setInterval(led5, 2);
  timer.setInterval(led6, 3);
  timer.setInterval(led13, 500);
  player.setSong(song);
}

void loop() {
  timer.runTimer();
  player.pollSong();
}
