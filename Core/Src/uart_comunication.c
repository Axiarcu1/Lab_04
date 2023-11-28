/*
 * uart_comunication.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#include "uart_comunication.h"

void uart_communiation_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2) {
	if (status_uart == 0){
		if (command_flag == 1) {
			command_flag = 0;
			if (command[0] == 'R' && command[1] == 'S' && command[2] == 'T') {
				// Get ADC value
				HAL_ADC_Start(&hadc1);
				ADC_value = HAL_ADC_GetValue(&hadc1);
				HAL_ADC_Stop(&hadc1);
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
				status_uart = 1;
				setTimer2(3000);
			}
		}
	}
	else if (status_uart == 1){
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!ADC=%lu#\r\n", ADC_value), 1000);
		status_uart = 2;
	}
	else if (status_uart == 2){
		if (command_flag == 1) {
			command_flag = 0;
			if (command[0] == 'O' && command[1] == 'K') {
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
				status_uart = 0;
				clearTimer2();
			}
		}
		if(timer2_flag == 1) {
			status_uart = 1;
			setTimer2(3000);
		}
	}
}
