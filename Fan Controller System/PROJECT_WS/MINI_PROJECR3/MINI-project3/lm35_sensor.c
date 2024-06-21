 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Ahmedmohamed
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include "ADC.h"

uint8 LM35_getTemperature(void)
{
	uint16 DIGITAL_value = 0;
	uint8 temp_value = 0;

	DIGITAL_value = ADC_Read_CHANNEL(SENSOR_CHANNEL_ID) ;

	temp_value = (uint8)(((uint32)DIGITAL_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value ;
}

