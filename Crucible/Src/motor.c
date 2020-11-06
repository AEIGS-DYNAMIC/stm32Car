#include "motor.h"

static uint32_t PWM=3000;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
/***********ע��Ҫ��ÿ���ٶ��µ�PWM�ģ�鱾��ȱ��*****/
void move_forward(void)
{
	HAL_GPIO_WritePin(LF_MOTOR_IN1_GPIO_Port,LF_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LF_MOTOR_IN2_GPIO_Port,LF_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LB_MOTOR_IN1_GPIO_Port,LB_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LB_MOTOR_IN2_GPIO_Port,LB_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RF_MOTOR_IN1_GPIO_Port,RF_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RF_MOTOR_IN2_GPIO_Port,RF_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RB_MOTOR_IN1_GPIO_Port,RB_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RB_MOTOR_IN2_GPIO_Port,RB_MOTOR_IN2_Pin,GPIO_PIN_RESET);
}

void move_backward(void)
{
	HAL_GPIO_WritePin(LF_MOTOR_IN1_GPIO_Port,LF_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LF_MOTOR_IN2_GPIO_Port,LF_MOTOR_IN2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LB_MOTOR_IN1_GPIO_Port,LB_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LB_MOTOR_IN2_GPIO_Port,LB_MOTOR_IN2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RF_MOTOR_IN1_GPIO_Port,RF_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RF_MOTOR_IN2_GPIO_Port,RF_MOTOR_IN2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RB_MOTOR_IN1_GPIO_Port,RB_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RB_MOTOR_IN2_GPIO_Port,RB_MOTOR_IN2_Pin,GPIO_PIN_SET);
}

void stop(void)
{
	HAL_GPIO_WritePin(LF_MOTOR_IN1_GPIO_Port,LF_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LF_MOTOR_IN2_GPIO_Port,LF_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LB_MOTOR_IN1_GPIO_Port,LB_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LB_MOTOR_IN2_GPIO_Port,LB_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RF_MOTOR_IN1_GPIO_Port,RF_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RF_MOTOR_IN2_GPIO_Port,RF_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RB_MOTOR_IN1_GPIO_Port,RB_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RB_MOTOR_IN2_GPIO_Port,RB_MOTOR_IN2_Pin,GPIO_PIN_RESET);
}

void move_right(void)
{
	HAL_GPIO_WritePin(LF_MOTOR_IN1_GPIO_Port,LF_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LF_MOTOR_IN2_GPIO_Port,LF_MOTOR_IN2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LB_MOTOR_IN1_GPIO_Port,LB_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LB_MOTOR_IN2_GPIO_Port,LB_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RF_MOTOR_IN1_GPIO_Port,RF_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RF_MOTOR_IN2_GPIO_Port,RF_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RB_MOTOR_IN1_GPIO_Port,RB_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RB_MOTOR_IN2_GPIO_Port,RB_MOTOR_IN2_Pin,GPIO_PIN_SET);
}

void move_left(void)
{
	HAL_GPIO_WritePin(LF_MOTOR_IN1_GPIO_Port,LF_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LF_MOTOR_IN2_GPIO_Port,LF_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LB_MOTOR_IN1_GPIO_Port,LB_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LB_MOTOR_IN2_GPIO_Port,LB_MOTOR_IN2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RF_MOTOR_IN1_GPIO_Port,RF_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RF_MOTOR_IN2_GPIO_Port,RF_MOTOR_IN2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RB_MOTOR_IN1_GPIO_Port,RB_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RB_MOTOR_IN2_GPIO_Port,RB_MOTOR_IN2_Pin,GPIO_PIN_RESET);
}

void move_Ncircle(void)
{
	HAL_GPIO_WritePin(LF_MOTOR_IN1_GPIO_Port,LF_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LF_MOTOR_IN2_GPIO_Port,LF_MOTOR_IN2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LB_MOTOR_IN1_GPIO_Port,LB_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LB_MOTOR_IN2_GPIO_Port,LB_MOTOR_IN2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RF_MOTOR_IN1_GPIO_Port,RF_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RF_MOTOR_IN2_GPIO_Port,RF_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RB_MOTOR_IN1_GPIO_Port,RB_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RB_MOTOR_IN2_GPIO_Port,RB_MOTOR_IN2_Pin,GPIO_PIN_RESET);
}

void move_Scircle(void)
{
	HAL_GPIO_WritePin(LF_MOTOR_IN1_GPIO_Port,LF_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LF_MOTOR_IN2_GPIO_Port,LF_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LB_MOTOR_IN1_GPIO_Port,LB_MOTOR_IN1_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LB_MOTOR_IN2_GPIO_Port,LB_MOTOR_IN2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RF_MOTOR_IN1_GPIO_Port,RF_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RF_MOTOR_IN2_GPIO_Port,RF_MOTOR_IN2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(RB_MOTOR_IN1_GPIO_Port,RB_MOTOR_IN1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RB_MOTOR_IN2_GPIO_Port,RB_MOTOR_IN2_Pin,GPIO_PIN_SET);
}

void speed_up(void)
{
	if(PWM<=4000)
	{
		PWM+=1000;
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_ALL,PWM);
	}
}

void speed_down(void)
{
	if(PWM>=1000)
	{
		PWM-=1000;
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_ALL,PWM);
	}
}