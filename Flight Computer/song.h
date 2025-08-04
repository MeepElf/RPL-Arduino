// daisy_bell.h
#ifndef SONG_H
#define SONG_H

#include "notes.h"

const int QN = 250; // Quarter note duration in milliseconds daisay is 250

void playTone(int pin, double note, int duration) {
  tone(pin, note);
  delay(duration);
  noTone(pin);
}

void playDaisyBell(int buzzerPin) {
  playTone(buzzerPin, NOTE_C5, QN * 3);
  playTone(buzzerPin, NOTE_A4, QN * 3);
  playTone(buzzerPin, NOTE_F4, QN * 3);
  playTone(buzzerPin, NOTE_C4, QN * 3);
  playTone(buzzerPin, NOTE_D4, QN);
  playTone(buzzerPin, NOTE_E4, QN);
  playTone(buzzerPin, NOTE_F4, QN);
  playTone(buzzerPin, NOTE_D4, QN * 2);
  playTone(buzzerPin, NOTE_F4, QN);
  playTone(buzzerPin, NOTE_C4, QN * 3);
  delay(QN * 3);

  playTone(buzzerPin, NOTE_D4, QN * 3);
  playTone(buzzerPin, NOTE_A4, QN * 3);
  playTone(buzzerPin, NOTE_A4, QN * 3);
  playTone(buzzerPin, NOTE_F4, QN * 3);
  playTone(buzzerPin, NOTE_D4, QN);
  playTone(buzzerPin, NOTE_E4, QN);
  playTone(buzzerPin, NOTE_F4, QN);
  playTone(buzzerPin, NOTE_G4, QN * 2);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_G4, QN * 3);
  delay(QN * 3);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_G4, QN);
  playTone(buzzerPin, NOTE_C5, QN * 2);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_G4, QN);
  playTone(buzzerPin, NOTE_F4, QN * 4);
  playTone(buzzerPin, NOTE_G4, QN);
  playTone(buzzerPin, NOTE_A4, QN * 2);
  playTone(buzzerPin, NOTE_F4, QN);
  playTone(buzzerPin, NOTE_D4, QN * 2);
  playTone(buzzerPin, NOTE_F4, QN);
  playTone(buzzerPin, NOTE_D4, QN);
  playTone(buzzerPin, NOTE_C4, QN * 3);
  delay(QN);
  playTone(buzzerPin, NOTE_C4, QN);
  playTone(buzzerPin, NOTE_F4, QN * 2);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_G4, QN);
  delay(QN * 2);
  playTone(buzzerPin, NOTE_F4, QN * 2);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_G4, QN);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_A4, QN);
}

void playMegaloStrikesBack(int buzzerPin) {
   playTone(buzzerPin, NOTE_D5, QN);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_AS4, QN);
  playTone(buzzerPin, NOTE_G4, QN);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_D5, QN);
  playTone(buzzerPin, NOTE_A4, QN/2);
  playTone(buzzerPin, NOTE_G4, QN/2);
  playTone(buzzerPin, NOTE_F4, QN);
  playTone(buzzerPin, NOTE_E4, QN);

  playTone(buzzerPin, NOTE_E4, QN);
  playTone(buzzerPin, NOTE_G4, QN);
  playTone(buzzerPin, NOTE_F4, QN/2);
  playTone(buzzerPin, NOTE_E4, QN/2);
  playTone(buzzerPin, NOTE_CS4, QN);
  playTone(buzzerPin, NOTE_D4, QN);
  playTone(buzzerPin, NOTE_AS4, QN);
  playTone(buzzerPin, NOTE_A4, QN/2);
  playTone(buzzerPin, NOTE_G4, QN/2);
  playTone(buzzerPin, NOTE_A4, QN);

   playTone(buzzerPin, NOTE_E4, QN);
  playTone(buzzerPin, NOTE_CS4, QN);
  playTone(buzzerPin, NOTE_AS4, QN/2);
  playTone(buzzerPin, NOTE_A4, QN/2);
  playTone(buzzerPin, NOTE_G4, QN);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_D5, QN);
  playTone(buzzerPin, NOTE_F5, QN/2);
  playTone(buzzerPin, NOTE_E5, QN/2);
  playTone(buzzerPin, NOTE_D5, QN);

   playTone(buzzerPin, NOTE_F5, QN);
  playTone(buzzerPin, NOTE_D5, QN);
  playTone(buzzerPin, NOTE_AS4, QN/2);
  playTone(buzzerPin, NOTE_GS4, QN/2);
  playTone(buzzerPin, NOTE_E4, QN);
  playTone(buzzerPin, NOTE_A4, QN);
  playTone(buzzerPin, NOTE_AS4, QN);
  playTone(buzzerPin, NOTE_A4, QN*2);
}

#endif
