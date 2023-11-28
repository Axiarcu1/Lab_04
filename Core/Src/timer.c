/*
 * timer.c
 *
 *  Created on: Nov 27, 2023
 *      Author: Admin
 */

#include "timer.h"

int timer1_counter = 0;
int timer2_counter = 0;

int timer1_flag = 0;
int timer2_flag = 0;

int TIMER_CYCLE = 10;

void setTimer1(int duration){	//set timer interrupt for every second counts decrease
	timer1_counter = duration / TIMER_CYCLE;
	timer1_flag = 0;
}

void setTimer2(int duration){	//set timer interrupt for switching between state
	timer2_counter = duration / TIMER_CYCLE;
	timer2_flag = 0;
}

void clearTimer1(){
	timer1_counter = 0;
	timer1_flag = 0;
}

void clearTimer2(){
	timer2_counter = 0;
	timer2_flag = 0;
}

void timer_run(){
	if (timer1_counter > 0){
		timer1_counter--;
		if (timer1_counter == 0){
			timer1_flag = 1;
		}
	}
	if (timer2_counter > 0){
		timer2_counter--;
		if (timer2_counter == 0){
			timer2_flag = 1;
		}
	}
}
