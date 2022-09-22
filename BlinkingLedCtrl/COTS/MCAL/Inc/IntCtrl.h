#ifndef INTRCTRL_H
#define INTRCTRL_H


/************************************************************************************
*                                   FILE DESCRIPTION                                *
* ----------------------------------------------------------------------------------*
* File Name : IntrCtrl.h                                                            *
* Brief     : Header file for Enable/Disable Interrupts                             *
* Author    : Ola Badr                                                              *
* MC        : TM4C123GH6PM                                                          *
*************************************************************************************/


/************************************************************************************
*                                    INCLUDES                                       *
************************************************************************************/
#include "Std_Types.h"


/************************************************************************************
*                         LOCAL MACROS CONSTANT/FUNCTION                            *
************************************************************************************/ 

/*Interrupts IDs*/

#define  NVIC_GPIOA                                                 0
#define  NVIC_GPIOB                                                 1
#define  NVIC_GPIOC                                                 2
#define  NVIC_GPIOD                                                 3
#define  NVIC_GPIOE                                                 4

#define  NVIC_16_32_BIT_TIMER_0A                                    19
#define  NVIC_16_32_BIT_TIMER_0B                                    20

#define  NVIC_GPIOF                                                 30


/************************************************************************************
*                          GLOBAL DATA TYPES AND STRUCTURES                         *
************************************************************************************/ 
typedef       uint_8       Interrupt_Type ;


/************************************************************************************
*                               LOCAL FUNCTION PROTOTYPES                           *
************************************************************************************/
/*Init Interrupt*/
void NVIC_InterruptInit(void);

/*Enable Specific Interrupt*/
void NVIC_InterruptEn(Interrupt_Type  InterruptID);

/*Disable Specific Interrupt*/
void NVIC_InterruptDis(Interrupt_Type InterruptID);

/*Set Pending*/
void NVIC_InterruptPend(Interrupt_Type InterruptID);

/*UnPending*/ 
void NVIC_InterruptUnpend(Interrupt_Type InterruptID);


/************************************************************************************
*                               END OF FILE: filename.h                             *
************************************************************************************/

#endif /* INTRCTRL_H */






