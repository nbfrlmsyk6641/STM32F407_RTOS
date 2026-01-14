#include "STM32F4xx_OLED.h"
#include "oled_font.h"
#include "i2c.h"

// 引用 I2C1 句柄
extern I2C_HandleTypeDef hi2c1;

// 写命令
void OLED_Write_Cmd(uint8_t cmd)
{
    HAL_I2C_Mem_Write(&hi2c1, OLED_ADDR, 0x00, 1, &cmd, 1, 100);
}

// 写数据
void OLED_Write_Data(uint8_t data)
{
    HAL_I2C_Mem_Write(&hi2c1, OLED_ADDR, 0x40, 1, &data, 1, 100);
}

// 设置光标
void OLED_Set_Pos(uint8_t x, uint8_t y)
{
    OLED_Write_Cmd(0xb0 + y);
    OLED_Write_Cmd(((x & 0xf0) >> 4) | 0x10);
    OLED_Write_Cmd(x & 0x0f);
}

// 清屏
void OLED_Clear(void)
{
    uint8_t i, n;
    for (i = 0; i < 8; i++)
    {
        OLED_Write_Cmd(0xb0 + i);
        OLED_Write_Cmd(0x00);
        OLED_Write_Cmd(0x10);
        for (n = 0; n < 128; n++)
        {
            OLED_Write_Data(0x00);
        }
    }
}

// 初始化
void OLED_Init(void)
{
    HAL_Delay(200); // 上电延时，确保屏幕内部电路稳定

    OLED_Write_Cmd(0xAE); // 关显示
    OLED_Write_Cmd(0x20); // 内存模式
    OLED_Write_Cmd(0x10); 
    OLED_Write_Cmd(0xB0); 
    OLED_Write_Cmd(0xC8); 
    OLED_Write_Cmd(0x00); 
    OLED_Write_Cmd(0x10); 
    OLED_Write_Cmd(0x40); 
    OLED_Write_Cmd(0x81); // 对比度
    OLED_Write_Cmd(0xFF);
    OLED_Write_Cmd(0xA1); 
    OLED_Write_Cmd(0xA6); 
    OLED_Write_Cmd(0xA8); 
    OLED_Write_Cmd(0x3F);
    OLED_Write_Cmd(0xA4); 
    OLED_Write_Cmd(0xD3); 
    OLED_Write_Cmd(0x00);
    OLED_Write_Cmd(0xD5); 
    OLED_Write_Cmd(0xF0);
    OLED_Write_Cmd(0xD9); 
    OLED_Write_Cmd(0x22);
    OLED_Write_Cmd(0xDA); 
    OLED_Write_Cmd(0x12);
    OLED_Write_Cmd(0xDB); 
    OLED_Write_Cmd(0x20);
    OLED_Write_Cmd(0x8D); // 电荷泵
    OLED_Write_Cmd(0x14); 
    OLED_Write_Cmd(0xAF); // 开显示

    OLED_Clear();
}

uint32_t OLED_Pow(uint8_t m, uint8_t n)
{
    uint32_t result = 1;
    while (n--) result *= m;
    return result;
}

// 显示字符
// 显示一个字符 (8x16)
// x: 0~120, y: 0~6 (页地址)
void OLED_ShowChar(uint8_t x, uint8_t y, char chr)
{
    unsigned char i = 0;
    
    // 边界保护：如果你尝试显示超过127的字符，防止数组越界
    if(chr >= 128) return; 

    // 1. 换行处理
    if (x > 120) { 
        x = 0; 
        y = y + 2; 
    }

    // 2. 显示上半部分 (前8个字节)
    OLED_Set_Pos(x, y);
    for (i = 0; i < 8; i++)
    {
        // 核心改动：直接用 [chr][i] 访问，不需要减 ' '
        OLED_Write_Data(ascii_font[(uint8_t)chr][i]); 
    }

    // 3. 显示下半部分 (后8个字节)
    OLED_Set_Pos(x, y + 1);
    for (i = 0; i < 8; i++)
    {
        // 核心改动：取后8个字节，即 [chr][i+8]
        OLED_Write_Data(ascii_font[(uint8_t)chr][i + 8]);
    }
}

// 显示字符串
void OLED_ShowString(uint8_t x, uint8_t y, char *chr)
{
    unsigned char j = 0;
    while (chr[j] != '\0')
    {
        OLED_ShowChar(x, y, chr[j]);
        x += 8;
        if (x > 120) { x = 0; y += 2; }
        j++;
    }
}

void OLED_ShowHex(uint8_t x, uint8_t y, uint32_t num, uint8_t mode)
{
    char buf[15];
    uint8_t i = 0;
    uint8_t j = 0;
    char temp[10];

    if (mode)
    {
        buf[i++] = '0';
        buf[i++] = 'x';
    }

    if (num == 0)
    {
        buf[i++] = '0';
    }
    else
    {
        while (num > 0)
        {
            uint8_t val = num % 16; // 取余数 (0~15)
            
            if (val < 10) 
            {
                temp[j++] = val + '0'; // 0~9 转 ASCII '0'~'9'
            }
            else 
            {
                temp[j++] = val - 10 + 'A'; // 10~15 转 ASCII 'A'~'F'
            }
            
            num /= 16; // 移位
        }

        while (j > 0)
        {
            buf[i++] = temp[--j];
        }
    }

    buf[i] = '\0';

    OLED_ShowString(x, y, buf);
}

void OLED_ShowSignedNum(uint8_t x, uint8_t y, int32_t num)
{
    char buf[15]; // 足够存下符号位 + 10位数字
    uint8_t i = 0;
    uint32_t num_abs;

    if (num < 0)
    {
        buf[i++] = '-';  // 添加负号
        num_abs = -num;  // 转为正数处理
    }
    else
    {
        num_abs = num;
    }

    char temp[12];
    uint8_t j = 0;
    
    if (num_abs == 0)
    {
        buf[i++] = '0';
    }
    else
    {
        while (num_abs > 0)
        {
            temp[j++] = (num_abs % 10) + '0';
            num_abs /= 10;
        }
        while (j > 0)
        {
            buf[i++] = temp[--j];
        }
    }
    
    buf[i] = '\0';
    
    OLED_ShowString(x, y, buf);
}

void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len)
{
    uint8_t t, temp;
    // uint8_t enshow = 0; 

    for (t = 0; t < len; t++)
    {
        temp = (num / OLED_Pow(10, len - t - 1)) % 10;
        
        OLED_ShowChar(x + (t * 8), y, temp + '0'); 
    }
}

void OLED_Task()
{
    static uint8_t i;

    OLED_ShowString(0, 0, "Hello, OLED!");
    OLED_ShowString(0, 2, "STM32F4 + RTOS");
    OLED_ShowNum(0, 4, i, 2);

    i ++;

    if (i > 60)
    {
        i = 0;
    }
    
}
