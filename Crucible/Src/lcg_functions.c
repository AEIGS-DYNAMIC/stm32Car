#include "lcg_functions.h"
#include "vl53l0x.h"
#include "motor_B.h"
#include "motor_D.h"
#include "motor.h"
#include "ps2.h"
#include "other_functions.h"
#include "zbw_functions.h"


//第一次夹持
void catch_1(void)
{
// 校准函数
//	while(calibration_cube())
//	{
//		HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
//		HAL_Delay(10);
//	}
	// 舵机松
	release_fk();
	MOTER_MOVE(-44000, 1000, 1000, 1000);
	HAL_Delay(3600);
	catch_fk();
	MOTER_MOVE(44000, 1000, 1000, 1000);
}
//之后的夹持
void catch_2(void)
{
	// 校准函数
//	while(calibration_cube())
//	{
//		HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
//		HAL_Delay(10);
//	}
	release_fk();
	HAL_Delay(1);
	MOTER_MOVE(-44000,1000,1000,1000);
	HAL_Delay(3500);
	catch_fk();
	MOTER_MOVE(11000, 1000, 1000, 1000);
}

void release_1(void)
{
	MOTER_MOVE(33000, 1000, 1000, 1000);
	release_fk();
	open_door();
	
}

void release_2(void)
{
	MOTER_MOVE(-11000, 1000, 1000, 1000);
	release_fk();
	open_door();
}

