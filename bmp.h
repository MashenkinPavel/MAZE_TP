#include <avr/pgmspace.h>
#pragma once
extern const unsigned char PROGMEM instruction_screen_bitmap[], instruction_screen_mask[], instruction_screen_plus_mask[], instruction_screen_comp_w[], instruction_screen_comp_b[], instruction_screen_comp_a[];
extern const unsigned char PROGMEM zastavka_bitmap[], zastavka_mask[], zastavka_plus_mask[], zastavka_comp_w[], zastavka_comp_b[], zastavka_comp_a[];
extern const unsigned char PROGMEM player_bitmap[], player_mask[], player_plus_mask[], player_comp_w[], player_comp_b[], player_comp_a[];
extern const unsigned char PROGMEM simple_gameover_bitmap[], simple_gameover_mask[], simple_gameover_plus_mask[], simple_gameover_comp_w[], simple_gameover_comp_b[], simple_gameover_comp_a[];
extern const unsigned char PROGMEM endpoint_bitmap[], endpoint_mask[], endpoint_plus_mask[], endpoint_comp_w[], endpoint_comp_b[], endpoint_comp_a[];
extern const uint8_t introText[] PROGMEM;
extern const uint8_t LVL1_completed1[] PROGMEM;
extern const uint8_t LVL2_completed[] PROGMEM;
extern const uint8_t LVL3_completed[] PROGMEM;