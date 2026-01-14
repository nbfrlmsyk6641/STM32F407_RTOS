#ifndef __STM32F4XX_OLED_H
#define __STM32F4XX_OLED_H

#include "main.h" 

#define OLED_ADDR       0x78 // OLED默认地址

void OLED_Init(void);
uint32_t OLED_Pow(uint8_t m, uint8_t n);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t x, uint8_t y, char chr);
void OLED_ShowString(uint8_t x, uint8_t y, char *chr);
void OLED_ShowHex(uint8_t x, uint8_t y, uint32_t num, uint8_t mode);
void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len);
void OLED_ShowSignedNum(uint8_t x, uint8_t y, int32_t num);
void OLED_Task(void);

#endif


