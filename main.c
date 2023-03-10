#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lib.h"
#include <stdlib.h>
#include <stdbool.h>
	
int main(void)
{
	PWM_init(1000);
	//mode change 
	//0 -> 
	//1 -> steady
	//2 -> blink
	int mode = 0;
	//variable to increase_PWM function -> setting the start PWM value [%]
	int PWM_start = 20;
	//variable used in increase_PWM function
	bool condition = true;
	//variable used in increase_PWM function
	int i;
	//variable used in increase_PWM function -> min PWM value
	int PWM_min = 20;
	//variable used in increase_PWM function -> min PWM value
	int PWM_max = 40;
	//variable used in increase_PWM function -> delay
	int ms_delay = 50;
	//setting the initial value of the var condition and i
	if (PWM_start > PWM_max) {
		condition = false;
		i = (255 * PWM_start)/100;
	}
	else {
		condition = true;
		i = (255 * PWM_start)/100;
	}
	//main infinite loop
	while (1) {
		switch (mode) {
			case 0: {
				OCR0A = increase_PWM(&condition, &i, PWM_min, PWM_max, ms_delay);
				break;
			}
			case 1: {
				OCR0A = set_PWM(40);
				break;
			}
			case 2: {
				OCR0A = blink(OCR0A, 30, 500);
				break;
			}
			default: {
				OCR0A = set_PWM(0);
				break;
			}
		}
	}
}

