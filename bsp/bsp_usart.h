#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "stm32f1xx_hal.h"

/* 命令枚举 */
#define CMD_NONE   0x00
#define CMD_1      0x01
#define CMD_2      0x02
#define CMD_3      0x03

void    BSP_USART_Init(void);
uint8_t BSP_USART_GetCommand(void);
void    BSP_USART_ClearCommand(void);

#endif