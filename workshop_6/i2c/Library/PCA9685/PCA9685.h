#pragma once

#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

void pca9685_enable(int8_t);
void pca9685_sleep(int8_t);
void pca9685_frequency(uint16_t);
void pca9685_setChannelPWM(uint8_t, int8_t);


