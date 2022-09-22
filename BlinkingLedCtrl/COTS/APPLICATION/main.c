/************************************************************************************
*                                   FILE DESCRIPTION                                *
* ----------------------------------------------------------------------------------*
* File Name : main.c                                                                *
* Brief     : main application to control a blinking led                            *
* Author    : Ola Badr                                                              *
* MC        :  TM4C123GH6PM                                                         *
*************************************************************************************/


/************************************************************************************
*                                    INCLUDES                                       *
************************************************************************************/
#include "Std_Types.h"
#include "GpioCtrl.h"
#include "IntCtrl.h"
#include "SystickDelay.h"
#include "MCU_HW.h"



/************************************************************************************
*                                    USER MACRO                                     *
************************************************************************************/
#define ON_TIME               3
#define OFF_TIME              1
#define PORT_ID               PORTB_ID
#define PIN                   CHANNEL7


/************************************************************************************
*                                    GLOBAL DATA                                    *
************************************************************************************/


static uint_8 counts = 0 ;

/************************************************************************************
*                                   MAIN FUNCTION                                   *
************************************************************************************/


int main ()
{

	/*configure pin*/
	Port_ConfigType Config;
	Config.Port = PORT_ID;
	Config.Pin = PIN;
	Config.Mode = GPIO;
	Config.Direction = OUTPUT;
	Config.Internal_Attach = PULL_UP;

	Port_Init(&Config); /*Initialaize Configuration*/

	GPIO_WriteChannel (PORT_ID, PIN , LOW);

	SYSTICK_Init();

while (1)
{
	GPIO_WriteChannel (PORT_ID, PIN , HIGH);
	while (counts != ON_TIME);
	counts=0;
	
	GPIO_WriteChannel (PORT_ID, PIN , LOW);
	while (counts != OFF_TIME);
	counts=0;


}



}

/************************************************************************************
 *                            INTERRUPT SERVICE ROUTINES                            *
 ************************************************************************************/
 
SysTick_Handler()
{
	
	counts++;
	STCTRL ^= (1<<STCTRL_COUNT); /*Clear bit*/
}




/************************************************************************************
*                               END OF FILE: filename.c                             *
************************************************************************************/

