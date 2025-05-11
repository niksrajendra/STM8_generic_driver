/* MAIN.C file
 *
 * Copyright (c) 2002-2005 STMicroelectronics
 */

//#include "STM8S003F3P.h"
#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include <stm8s003.h>
#include <RegisterBits.h>
#include <uart.h>
#include <adc.h>
#include <timer.h>

extern void adc1_isr(void) __interrupt(ADC1_ISR);
extern void tim4_isr(void) __interrupt(TIM4_ISR);

uint16_t globalCounter = 0x0000u;

void myDelay(void);
void hse_enable(void);
//int putch( str);

int putchar(int str)
{
	uart_write(str);
	return 0;
}

void myDelay(void)
{
	int i,j;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<500;j++)
		{
		}
	}
}

void hse_enable(void) {
    /* Enable HSE crystal oscillator */
    //CLK_ECKRbits.HSEEN = 1u;
    CLK_ECKR |= 0x01;
    while (!(CLK_ECKR & 0x02));
    /* Switch master clock to HSE */
    CLK_SWR = 0xB4;
    while (!(CLK_SWCR & (1 << 3)));
    CLK_SWCR |= (1 << 1);
}

void main(void)
{
	uint16_t result = 0;
	PC_DDR |= 0x08;
    PC_CR1 |= 0x08;
    PC_CR2 |= 0x08;
	hse_enable();
	uart_init(115200, DATA_8_BIT_STOP_1_BIT);
	enable_interrupts();
	adc_init(2);
	//printf("global counter value is %d\n",globalCounter);
	//timer4_init();
	while (1)
	{
		PC_ODR |=1<<3;
		//uart_write(0x55);
		//uart_write(0xAA);
		//result = adc_read();
		printf("global counter value is %d\n",globalCounter);
		myDelay();
		PC_ODR &=~(1<<3);
		myDelay();
	}
}
