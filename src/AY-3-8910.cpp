#include "AY-3-8910.h"

AY_3_8910::AY_3_8910(uint8_t reset_pin, uint8_t bc1_pin, uint8_t bdir_pin) {
  _reset_pin = reset_pin;
  _bc1_pin   = bc1_pin;
  _bdir_pin  = bdir_pin;
}

void AY_3_8910::init(void) {
  pinMode(_reset_pin, OUTPUT);
  pinMode(_bc1_pin  , OUTPUT);
  pinMode(_bdir_pin , OUTPUT);

  /* 9 番ピンから 2MHz のクロックを出力 */
  TCCR1A = bit(COM1A0);
  TCCR1B = bit(WGM12) | bit(CS10);
  OCR1A = 3;
  pinMode(9, OUTPUT);

  /* 使用する GPIO の初期化 */
  DDRD  = 0xFF;
  PORTD = 0x00;

  digitalWrite(_bc1_pin ,  LOW);
  digitalWrite(_bdir_pin,  LOW);

  digitalWrite(_reset_pin,  LOW);
  delay(5);
  digitalWrite(_reset_pin, HIGH);

  write( 7, 0b00111000);
}

void AY_3_8910::write(uint8_t reg_addr, uint8_t value) {
  digitalWrite(_bc1_pin , HIGH);
  digitalWrite(_bdir_pin, HIGH);

  PORTD = reg_addr;

  digitalWrite(_bc1_pin ,  LOW);
  digitalWrite(_bdir_pin,  LOW);

  delayMicroseconds(10);

  digitalWrite(_bdir_pin, HIGH);

  PORTD = value;

  digitalWrite(_bc1_pin ,  LOW);
  digitalWrite(_bdir_pin,  LOW);
}

void AY_3_8910::set_volume(char ch, uint8_t volume) {
  uint8_t vol = volume & 0b00001111;

  switch(ch) {
    case A:
      write(REG_VOL_A, vol);
      break;

    case B:
      write(REG_VOL_B, vol);
      break;

    case C:
      write(REG_VOL_C, vol);
      break;
  }
}

void AY_3_8910::tone_out(char ch, uint8_t tone) {
  tone_t note = tone_data[tone];

  switch(ch) {
    case A:
      write(CH_A_R0, note.ft);
      write(CH_A_R1, note.ct);
      break;

    case B:
      write(CH_B_R0, note.ft);
      write(CH_B_R1, note.ct);
      break;

    case C:
      write(CH_C_R0, note.ft);
      write(CH_C_R1, note.ct);
      break;
  }
}

void AY_3_8910::tone_mute(char ch) {
  switch(ch) {
    case A:
      write(CH_A_R0, 0);
      write(CH_A_R1, 0);
      break;

    case B:
      write(CH_B_R0, 0);
      write(CH_B_R1, 0);
      break;

    case C:
      write(CH_C_R0, 0);
      write(CH_C_R1, 0);
      break;
  }
}
