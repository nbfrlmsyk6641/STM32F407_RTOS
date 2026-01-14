#ifndef __STM32F4XX_OLED_H
#define __STM32F4XX_OLED_H

#include "main.h" // 必须包含，以获取 HAL 库定义

#define OLED_ADDR       0x78 // 默认地址

void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t x, uint8_t y, char chr);
void OLED_ShowString(uint8_t x, uint8_t y, char *chr);

#endif


