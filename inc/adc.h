#ifndef ADC_H
#define ADC_H

#include <stdint.h>

void adc_init(uint8_t channel);
uint16_t adc_read(void);

#endif
