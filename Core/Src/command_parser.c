/*
 * command_parser.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#include "command_parser.h"

void command_parser_fsm() {
	if (status_parser == 0){
		if (temp == '!'){
			status_parser = 1;
			command_index = 0;
		}
	}
	else if (status_parser == 1){
		if (temp == '#'){
			status_parser = 0;
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
