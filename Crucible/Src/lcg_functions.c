#include "lcg_functions.h"
// ��ʼ��
void car_init(void);
// һ��ץȡ����_1  ץȡǰ�漸��
void catch_1(void);
// һ��ץȡ����_2  ץȡ���һ��
void catch_2(void);
// һ���ͷ�1_���õ�ƽ̨
void release_1(void);
// һ���ͷ�2_���ø�ƽ̨
void release_2(void);





void catch_1(void)
{
	// У׼����
	jiaozhun();
	// �����
	release_fk();
	// ˿�˵�
		// ���÷��� CCW ��ʱ�룬CW˳ʱ�� �ݶ�CCWΪ˿���½�
		MSD_StepCounter("CCW");
		// ��������ɺܸ��½������ 10cm �����
		MOTER_MOVE();
	// �����
	catch_fk();
	// ˿��  ��-->�ܸ�
		// CW
		MSD_StepCounter("CW");
		MOTER_MOVE();
}

void catch_2(void)
{
	// У׼����
	jiaozhun();
	// �����
	release_fk();
	// ˿�˵�
		// ���÷��� CCW ��ʱ�룬CW˳ʱ�� �ݶ�CCWΪ˿���½�
		MSD_StepCounter("CCW");
		// ��������ɺܸ��½������ 10cm �����
		MOTER_MOVE();
	// �����
	catch_fk();
	// ˿��  ��-->��
		// CW
		MSD_StepCounter("CW");
		MOTER_MOVE();
}

void release_1(void)
{
	release_fk();
	open_door();
	
	// ��������ƶ�
	move_backward();
	
	close_door();
	// ˿�� ��-->�ܸ�
	MSD_StepCounter("CW");
	MOTER_MOVE();
	catch_fk();
	
}

void release_2(void)
{
	release_fk();
	open_door();
	move_backward();
	close_door();
	catch_fk();
}