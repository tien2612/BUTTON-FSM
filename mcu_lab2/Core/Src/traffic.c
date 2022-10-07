/*
 * traffic.c
 *
 *  Created on: Sep 30, 2022
 *      Author: nguye
 */

#include "traffic.h"
#include "main.h"

int mode = 0;
void traffic_lights(int mode) {
	switch(mode) {
		case RED:
			if (timer1_flag == 1) {
				HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 0); // RED
				HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
			}
			if (timer2_flag == 1) {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1); // GREEN
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
			}
			break;
		case GREEN:
			if (timer1_flag == 1) {
				HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 1); // RED
				HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
			}
			if (timer2_flag == 1) {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0); // GREEN
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
			}
			break;
		case YELLOW1:
			if (timer1_flag == 1) {
				HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
			}

			break;
		case YELLOW2:
			if (timer2_flag == 1) {
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
			}
			break;
		default:
			break;

	}
}
