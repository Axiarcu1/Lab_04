/*
 * global.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#include "global.h"

int status_parser = 0;
int status_uart = 0;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t command[MAX_BUFFER_SIZE];
uint8_t command_index = 0;
uint8_t command_flag = 0;

char str[50];
uint32_t ADC_value = 0;
