#ifndef INCFILE1_H_
#define INCFILE1_H_
#include <stdbool.h>
//
void delay_ms(int ms) ;
//
void PWM_init();
//
int set_PWM(int PWM);
//
int increase_PWM(bool *condition, int *i, int PWM_min, int PWM_max, int ms_delay);
//
int blink(int actual_val, int PWM, int ms_delay);
#endif /* INCFILE1_H_ */