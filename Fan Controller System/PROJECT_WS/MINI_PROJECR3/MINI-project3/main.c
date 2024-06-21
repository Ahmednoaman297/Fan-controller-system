
#include"LM35_SENSOR.h"
#include "LCD.h"
#include "ADC.h"
#include"DC_motor.h"
int main(void)
{
	uint8 temp;
	DcMotor_Init();
	LCD_INIT(); /* initialize LCD driver */
	ADC_ConfigType ADC_ConfigTypes = {INTERNALVREF,DIV_FACT8};
	ADC_INIT(&ADC_ConfigTypes); /* initialize ADC driver */
	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_MoveCursor(0,1);
	LCD_Displaystring("FAN IS   ");
	LCD_MoveCursor(1,1);
	LCD_Displaystring("Temp =    C");

	while(1)
	{
		temp = LM35_getTemperature();
		/* Display the temperature value every time at same position */
		LCD_MoveCursor(1,7);
		if(temp >= 100)
		{
			LCD_IntegerToString(temp);
		}
		else
		{
			LCD_IntegerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_DisplayCharacter(' ');
		}
		 if(temp>=0&&temp<30)
		{
			DcMotor_Rotate(STOP,0);
			LCD_MoveCursor(0,7);
			LCD_Displaystring(" OFF ");
		}
		else if(temp>=30&&temp<60)
		{
			DcMotor_Rotate(CW,25);
			LCD_MoveCursor(0,7);
			LCD_Displaystring(" ON ");

		}
		else if(temp>=60&&temp<90)
		{
			DcMotor_Rotate(CW,50);
			LCD_MoveCursor(0,7);
			LCD_Displaystring(" ON ");
		}
		else if(temp>=90&&temp<120)
		{
			DcMotor_Rotate(CW,75);
			LCD_MoveCursor(0,7);
			LCD_Displaystring(" ON ");
		}
		else if(temp>=120&&temp<=150)
		{
			DcMotor_Rotate(CW,100);
			LCD_MoveCursor(0,7);
			LCD_Displaystring(" ON ");
		}

	}

}
