#define F_CPU 16000000UL
#include "lib.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdbool.h>
//
void delay_ms(int ms)
{
	for (int i = 0; i <= ms; i++)
	{
		_delay_ms(1);
	}
}
//
void PWM_init() {
	// 8 - bit PWM initialization
	DDRD |= (1 << 5);
	DDRD |= (1 << 6);
	TCCR0A |= (1 << COM0A1) | (1 << COM0A0) | (1 << COM0B1) | (1 << COM0B0) | (1 << WGM01) | (1 << WGM00);
	TCCR0B |= (1 << CS00);
	//PWM 0%
	OCR0A = 255;
	//delay_ms(ms_delay);
}
//set PWM [%]
int set_PWM(int PWM) {
	if (PWM > 100 || PWM < 0) {
		return 255 - (255 * (0)); //error - wrong value -> pwm 0%
	}
	else {
		return 255 - ((255 * PWM) / 100);
	}
}
//
int increase_PWM(bool *condition, int *i, int PWM_min, int PWM_max, int ms_delay) {
	int pwm = 255 - *i;
	
	if (((*i) <= (255 * PWM_max)/100) && *condition) {
		(*i)++;
		delay_ms(ms_delay);
		if((*i == (255 * PWM_max)/100) && *condition) {
			*condition = false;
		}
	}
		
	else if ((*i >= (255 * PWM_min)/100) && !*condition) {
		(*i)--;
		delay_ms(ms_delay);
		if((*i == (255 * PWM_min)/100) && !*condition) {
			*condition = true;
		}
	}
	return pwm;
}
//
int blink(int actual_val, int PWM, int ms_delay) {
	int pwm;
	if (actual_val < 255) {
		pwm = set_PWM(0);
		delay_ms(ms_delay);
	}
	else {
		pwm = set_PWM(PWM);
		delay_ms(ms_delay);	
	}
	return pwm;
}
