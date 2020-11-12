#include "motor_D.h"
#include "other_functions.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;


static uint16_t i;

void catch_fk(void)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,L_PWM_CLOSE);
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,R_PWM_CLOSE);
}

void open_door(void)
{
	for(;i<D_PWM_OPEN;i++)
	{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,i);
	delay_us(200);
	}
}

void open_front_door(void)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,FL_PWM_OPEN);
	delay_us(10);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,FR_PWM_OPEN);
}

void release_fk(void)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,L_PWM_OPEN);
	delay_us(10);
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,R_PWM_OPEN);
}

void close_door(void)
{
	for(;i>D_PWM_CLOSE;i--)
	{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,i);
	delay_us(200);
	}
}

void close_front_door(void)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,FL_PWM_CLOSE);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,FR_PWM_CLOSE);
}