#include "stm32f1xx_hal.h" // 根据你的芯片系列修改，如 stm32f4xx_hal.h
#include <stdint.h>
#include "bsp_usart.h"
#include "usart.h"   /* CubeMX 生成的 huart1 声明在这里 */
#include <stm32f103xb.h>

/* 如果 usart.h 里没有 extern huart1，请保留下面这行 */
/* extern UART_HandleTypeDef huart1; */

static uint8_t            rx_byte = 0;      /* 单字节接收缓存 */
static volatile uint8_t   rx_cmd  = CMD_NONE; /* 解析出的命令 */

/* 启动一次中断接收（每次只收 1 字节） */
void BSP_USART_Init(void)
{
    rx_cmd = CMD_NONE;
    HAL_UART_Receive_IT(&huart1, &rx_byte, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        switch (rx_byte)
        {
            case '1': rx_cmd = CMD_1; break;
            case '2': rx_cmd = CMD_2; break;
            case '3': rx_cmd = CMD_3; break;
            default:  break; 
        }

        HAL_UART_Receive_IT(&huart1, &rx_byte, 1);
    }
}

uint8_t BSP_USART_GetCommand(void)
{
    return rx_cmd;
}

void BSP_USART_ClearCommand(void)
{
    rx_cmd = CMD_NONE;
}