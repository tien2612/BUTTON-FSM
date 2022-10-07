/*
 * fsm_manual.c
 *
 *  Created on: Oct 7, 2022
 *      Author: nguye
 */
#include "fsm_manual.h"

void fsm_manual_run() {
	switch(status) {
		case MAN_RED:
			if (timer1_flag == 1) {
				status = AUTO_RED;
				setTimer1(RED_TIME);
			}
			if (button1_flag == 1) {
				button1_flag = 0;
				clearTimer1();
				setTimer1(MAN_GREEN_TIME);
				status = MAN_GREEN;
			}
			break;
		case MAN_GREEN:
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
			if (timer1_flag == 1) {
				status = AUTO_GREEN;
				setTimer1(GREEN_TIME);
			}
			if (button1_flag == 1) {
				button1_flag = 0;
				clearTimer1();
				setTimer1(MAN_YELLOW_TIME);
				status = MAN_YELLOW;
			}
			break;
		case MAN_YELLOW:
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
			if (timer1_flag == 1) {
				status = AUTO_YELLOW;
				setTimer1(YELLOW_TIME);
			}
			if (button1_flag == 1) {
				button1_flag = 0;
				clearTimer1();
				setTimer1(RED_TIME);
				status = INIT;
			}
			break;
		default:
			break;
	}
}

