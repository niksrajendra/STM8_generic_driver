#ifndef UART_H
#define UART_H

typedef enum
{
    DATA_8_BIT_STOP_1_BIT,
    DATA_8_BIT_STOP_2_BIT,
    DATA_8_BIT_STOP_1_5_BIT,
    DATA_9_BIT_STOP_1_BIT
}modeUART;

void uart_init(uint32_t baud_rate, modeUART mode);
void uart_write(uint8_t data);
uint8_t uart_read(void);

#endif
