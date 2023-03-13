#include <PCA9685.h>

#define LED0_ON_L 0x06
#define LED0_ON_H 0x07
#define LED0_OFF_L 0x08
#define LED0_OFF_H 0x09

#define PRE_SCALE_ADDRESS 0xFE

uint8_t devId = 0x80;
uint8_t TxBuffer[0];



void pca9685_enable(int8_t state){
	if(state){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
		printf("pca9685 was turned on\r\n");
	}
	else{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
		printf("pca9685 was turned off\r\n");
	}
}

void pca9685_sleep(int8_t state){
	if(state){
	  TxBuffer[0] = 0x00;
	  TxBuffer[1] = 0x11;
	  HAL_I2C_Master_Transmit(&hi2c1, devId, (uint8_t*) &TxBuffer, 2, 1000);
	}
	else{
	  TxBuffer[0] = 0x00;
	  TxBuffer[1] = 0x01;
	  HAL_I2C_Master_Transmit(&hi2c1, devId, (uint8_t*) &TxBuffer, 2, 1000);
	}
}

void pca9685_frequency(uint16_t freq){ // 24...1526
	if(freq > 1526){
		freq = 1526;
	}
	else if (freq < 24){
		freq = 24;
	}
	uint8_t PRE_SCALE = ((25000000 / 4096) / freq) - 1;
	pca9685_sleep(1);
	TxBuffer[0] = PRE_SCALE_ADDRESS;
	TxBuffer[1] = PRE_SCALE;
	HAL_I2C_Master_Transmit(&hi2c1, devId, (uint8_t*) &TxBuffer, 2, 1000);
	pca9685_sleep(0);
	printf("Frequency was set: %d Hz\r\n", freq);

}

void pca9685_setChannelPWM(uint8_t channelNum, int8_t duty){ //channelNum = 0...15, duty = 0...100

	if(duty > 100){
		duty = 100;
	}
	else if (duty < 0){
		duty = 0;
	}

	if(channelNum > 15){
		channelNum = 15;
	}
	else if (channelNum < 0){
		channelNum = 0;
	}

	uint8_t LEDn_ON_L = LED0_ON_L + (channelNum * 4);
	uint8_t LEDn_ON_H = LED0_ON_H + (channelNum * 4);
	uint8_t LEDn_OFF_L = LED0_OFF_L + (channelNum * 4);
	uint8_t LEDn_OFF_H = LED0_OFF_H + (channelNum * 4);

	uint16_t valueOFF = (duty * 4095) / 100;
	uint8_t highByteOFF = (valueOFF >> 8) & 0xFF;
	uint8_t lowByteOFF = valueOFF & 0xFF;

	TxBuffer[0] = LEDn_ON_L;
	TxBuffer[1] = 0x00;
	HAL_I2C_Master_Transmit(&hi2c1, devId, (uint8_t*) &TxBuffer, 2, 1000);

	TxBuffer[0] = LEDn_ON_H;
	TxBuffer[1] = 0x00;
	HAL_I2C_Master_Transmit(&hi2c1, devId, (uint8_t*) &TxBuffer, 2, 1000);

	TxBuffer[0] = LEDn_OFF_L;
	TxBuffer[1] = lowByteOFF;
	HAL_I2C_Master_Transmit(&hi2c1, devId, (uint8_t*) &TxBuffer, 2, 1000);

	TxBuffer[0] = LEDn_OFF_H;
	TxBuffer[1] = highByteOFF;
	HAL_I2C_Master_Transmit(&hi2c1, devId, (uint8_t*) &TxBuffer, 2, 1000);

	printf("PWM was set on channel %d with duty %d %\r\n", channelNum, duty);
}
