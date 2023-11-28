/*
 * global.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define START_COMMAND 0
#define END_COMMAND 1

#define RST 10
#define SEND_ADC 11
#define OK 12

#define MAX_BUFFER_SIZE 30

extern int parser_state;
extern int uart_state;

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint8_t command_flag;
extern uint8_t command[MAX_BUFFER_SIZE];
extern uint8_t command_index;

extern char str[50];

extern uint32_t ADC_value;

#endif /* INC_GLOBAL_H_ */
