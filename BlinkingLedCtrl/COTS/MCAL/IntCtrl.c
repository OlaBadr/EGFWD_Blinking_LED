/************************************************************************************
*                                   FILE DESCRIPTION                                *
* ----------------------------------------------------------------------------------*
* File Name : IntrCtrl.c                                                            *
* Brief     : Source file for Enable/Disable Interrupts                             *
* Author    : Ola Badr                                                              *
* MC        : TM4C123GH6PM                                                          *
*************************************************************************************/


/************************************************************************************
*                                    INCLUDES                                       *
************************************************************************************/
#include "Std_Types.h"
#include "MCU_HW.h"
#include "CommonMacros.h"
#include "IntCtrl.h"


/************************************************************************************
*                                   GLOBAL FUNCTIONS                                *
************************************************************************************/

/*----------------------------------------------------------------------------------
-                                Functions Description                             -
------------------------------------------------------------------------------------
- FUNCTION_DESCRIPTION : Enable - Disable - Set Pending - Unpending                -
- SYNC/ASYNC           : Synchoronous                                              -
- REENTRANCY           : Non Reentrant                                             -
- IN PRAMETERS         : Interrupt ID                                              -
- OUT PRAMETERS        : None                                                      -
- RETURN VALUE         : None                                                      -
-----------------------------------------------------------------------------------*/

/*Init Interrupt*/
void NVIC_InterruptInit(void)
{
	APINT |=  0x4 << PRIGROUP ; /*Priority Group*/

}


/*Enable Specific Interrupt*/
void NVIC_InterruptEn(Interrupt_Type  InterruptID)
{
	if (InterruptID <= 31)
	     {
		     SET_CHANNEL(NVIC_EN0, InterruptID);
		 }
}




/*Disable Specific Interrupt*/
void NVIC_InterruptDis(Interrupt_Type InterruptID)
{
	if (InterruptID <= 31)
	     {
		     SET_CHANNEL(NVIC_DIS0, InterruptID);
		 }
}


/*Set Pending*/
void NVIC_InterruptPend(Interrupt_Type InterruptID)
{
	if (InterruptID <= 31)
	     {
		     SET_CHANNEL(NVIC_PEND0, InterruptID);
		 }
}


/*UnPending*/ 
void NVIC_InterruptUnpend(Interrupt_Type InterruptID)
{
	if (InterruptID <= 31)
	     {
		     SET_CHANNEL(NVIC_UNPEND0, InterruptID);
		 }
}







/************************************************************************************
*                               END OF FILE: filename.c                             *
************************************************************************************/



