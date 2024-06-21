/*
 * ADC.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Ahmedmohamed
 */
#include"ADC.h"
#include"common_macros.h"
#include<avr/io.h>
void ADC_INIT(const ADC_ConfigType* Config_Ptr)
{

	//INTERNAL 2.56 VOLT
ADMUX|=(Config_Ptr->ref_volt<<6);
	//PRESCALE 8
ADCSRA|=(Config_Ptr->prescaler);
	//ADC ENABLE
	SET_BIT(ADCSRA,ADEN);//ADEN
}
uint16 ADC_Read_CHANNEL(uint8 ch_num)
{
	ADMUX=(ADMUX&0xE0)|(ch_num);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;//READ DATA
}



