#ifndef _OLED_DISTANCE_
#define _OLED_DISTANCE_
#include "..\mybsp\oled\\u8g2_csrc\u8g2.h"

void oled_key(char key[]);
void oled_display();
void oled_init(void);
extern u8g2_t u8g2;
#endif