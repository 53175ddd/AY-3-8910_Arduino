#include "AY-3-8910.h"

const int RESET_PIN =  8;
const int BC1_PIN   = A5;
const int BDIR_PIN  = A4;

AY_3_8910 PSG(RESET_PIN, BC1_PIN, BDIR_PIN);

void setup() {
  PSG.init();
  PSG.set_volume(A, 0b1111);
  PSG.set_volume(B, 0b1111);
  PSG.set_volume(C, 0b1111);
}

void loop() {
  /* ドレミファソラシド */
  PSG.tone_out(A, NOTE_C4);
  delay(500);
  PSG.tone_out(A, NOTE_D4);
  delay(500);
  PSG.tone_out(A, NOTE_E4);
  delay(500);
  PSG.tone_out(A, NOTE_F4);
  delay(500);
  PSG.tone_out(A, NOTE_G4);
  delay(500);
  PSG.tone_out(A, NOTE_A5);
  delay(500);
  PSG.tone_out(A, NOTE_B5);
  delay(500);
  PSG.tone_out(A, NOTE_C5);
  delay(500);
  PSG.tone_mute(A);

  delay(500);

  /* 和音サンプル */
  PSG.tone_out(A, NOTE_C4);
  delay(250);
  PSG.tone_out(B, NOTE_E4);
  delay(250);
  PSG.tone_out(C, NOTE_G4);
  delay(500);
  PSG.tone_mute(A);
  PSG.tone_mute(B);
  PSG.tone_mute(C);

  delay(500);

  PSG.tone_out(A, NOTE_C4);
  delay(250);
  PSG.tone_out(B, NOTE_F4);
  delay(250);
  PSG.tone_out(C, NOTE_A5);
  delay(500);
  PSG.tone_mute(A);
  PSG.tone_mute(B);
  PSG.tone_mute(C);

  while(true);
}
