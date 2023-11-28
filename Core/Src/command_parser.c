/*
 * command_parser.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#include "command_parser.h"

void command_parser_fsm() {
	if (parser_state == START_COMMAND){
		if (temp == '!'){
			parser_state = END_COMMAND;
			command_index = 0;
		}
	}
	else if (parser_state == END_COMMAND){
		if (temp == '#'){
			parser_state = START_COMMAND;
			command[command_index] = '\0';
			command_flag = 1;
		}
		else {
			if (temp == '!'){
				command_index = 0;
			}
			else{
				command[command_index++] = temp;
				if (command_index == MAX_BUFFER_SIZE) command_index = 0;
			}
		}
	}
}
