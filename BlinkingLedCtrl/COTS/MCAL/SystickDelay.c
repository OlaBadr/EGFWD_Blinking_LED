/************************************************************************************
*                                   FILE DESCRIPTION                                *
* ----------------------------------------------------------------------------------*
* File Name : SystickDelay.c                                                        *
* Brief     : Source code to use systick with overflow mode as a delay function     *
* Author    : Ola Badr                                                              *
* MC        : TM4C123GH6PM                                                          *
*************************************************************************************/


/************************************************************************************
*                                    INCLUDES                                       *
************************************************************************************/
#include "Std_Types.h"
#include "MCU_HW.h"
#include "CommonMacros.h"
#include "SystickDelay.h"



/************************************************************************************
*                                   GLOBAL FUNCTIONS                                *
************************************************************************************/

/*----------------------------------------------------------------------------------
-                                Function Description                              -
------------------------------------------------------------------------------------
- FUNCTION_DESCRIPTION : Initialize Systick to count 1 second                      -
- SYNC/ASYNC           : Synchoronous                                              -
- REENTRANCY           : Non Reentrant                                             -
- IN PRAMETERS         : None                                                      -
- OUT PRAMETERS        : None                                                      -
- RETURN VALUE         : None                                                      -
-----------------------------------------------------------------------------------*/

void SYSTICK_Init(void)
{
	STCTRL ^= (1<<STCTRL_INTEN); /*Disable Interrupt*/
	SET_CHANNEL(STCTRL, STCTRL_ENABLE); /*operate in multi-shot*/
	STRELOAD = 11999999 ; /*to count a second*/
	STCURRENT = 0x000000; /*Clear current value in systick*/
	SET_CHANNEL(STCTRL, STCTRL_CLK_SRC); /*Enable System Clock*/
	SET_CHANNEL(STCTRL, STCTRL_INTEN); /*Enable Interrupt*/ 
	
}


/************************************************************************************
*                               END OF FILE: filename.c                             *
************************************************************************************/

