#ifndef _AY_3_8910_H_
#define _AY_3_8910_H_

#include <Arduino.h>
#include "notes_index.h"

/* 周波数に関するレジスタ */
#define CH_A_R0 0
#define CH_A_R1 1
#define CH_B_R0 2
#define CH_B_R1 3
#define CH_C_R0 4
#define CH_C_R1 5

/* チャンネルに関するレジスタ */
#define REG_VOL_A  8
#define REG_VOL_B  9
#define REG_VOL_C 10

#define A 'A'
#define B 'B'
#define C 'C'

struct tone_t {
  uint8_t ft;
  uint8_t ct : 4;
};

const tone_t tone_data[60] = {{119, 7}, { 11, 7}, {166, 6}, { 71, 6}, {236, 5}, {151, 5}, { 71, 5}, {251, 4}, {179, 4}, {112, 4}, { 48, 4}, {244, 3},
                              {187, 3}, {133, 3}, { 83, 3}, { 35, 3}, {246, 2}, {203, 2}, {163, 2}, {125, 2}, { 89, 2}, { 56, 2}, { 24, 2}, {250, 1},
                              {221, 1}, {194, 1}, {169, 1}, {145, 1}, {123, 1}, {101, 1}, { 81, 1}, { 62, 1}, { 44, 1}, { 28, 1}, { 12, 1}, {253, 0},
                              {238, 0}, {225, 0}, {212, 0}, {200, 0}, {189, 0}, {178, 0}, {168, 0}, {159, 0}, {150, 0}, {142, 0}, {134, 0}, {126, 0},
                              {119, 0}, {112, 0}, {106, 0}, {100, 0}, { 94, 0}, { 89, 0}, { 84, 0}, { 79, 0}, { 75, 0}, { 71, 0}, { 67, 0}, { 63, 0}};

const tone_t NOTE_MUTE = {0, 0};

class AY_3_8910 {
  public:
    AY_3_8910(uint8_t reset_pin, uint8_t bc1_pin, uint8_t bdir_pin);

    void init(void);
    void write(uint8_t reg_addr, uint8_t value);
    void set_volume(char ch, uint8_t volume);
    void tone_out(char ch, uint8_t tone);
    void tone_mute(char ch);

  private:
    uint8_t _reset_pin;
    uint8_t _bc1_pin;
    uint8_t _bdir_pin;
};

#endif
