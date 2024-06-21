/*
 * ADC.h
 *
 *  Created on: Oct 9, 2023
 *      Author: Ahmedmohamed
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
#define ADC_REF_VOLT_VALUE 2.56
#define ADC_MAXIMUM_VALUE 1023
typedef enum
{
	AREF,AVCC,RESERVED,INTERNALVREF
}ADC_ReferenceVolatge;
typedef enum{
	DIV_FACT2,DIV_FACT22,DIV_FACT4,DIV_FACT8,DIV_FACT16,DIV_FACT32,DIV_FACT64,DIV_FACT128

}ADC_Prescaler;
typedef struct
{
	 ADC_ReferenceVolatge ref_volt;
	 ADC_Prescaler prescaler;


}ADC_ConfigType;
void ADC_INIT(const ADC_ConfigType* Config_Ptr);
uint16 ADC_Read_CHANNEL(uint8 ch_num);


#endif /* ADC_H_ */
