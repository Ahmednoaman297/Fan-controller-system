/*
 * DC_motor.h
 *
 *  Created on: Oct 14, 2023
 *      Author: Ahmedmohamed
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#define EN1_PORT_ID  PORTB_ID
#define EN1_PIN_ID  PIN3_ID

#define IN1_PORT_ID  PORTB_ID
#define IN1_PIN_ID   PIN0_ID

#define IN2_PORT_ID  PORTB_ID
#define IN2_PIN_ID   PIN1_ID

typedef enum{
	STOP,CW,CCW
}DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);
void PWM_Timer0_Init(unsigned char set_duty_cycle);




#endif /* DC_MOTOR_H_ */
