#ifndef GPIOCTRL_TYPES_H
#define GPIOCTRL_TYPES_H


/************************************************************************************
*                                   FILE DESCRIPTION                                *
* ----------------------------------------------------------------------------------*
* File Name : GpioCtrl_Types.h                                                      *
* Brief     : Data types used in GPIO                                               *
* Author    : Ola Badr                                                              *
* MC        : TM4C123GH6PM                                                          *
*************************************************************************************/


/************************************************************************************
*                                    INCLUDES                                       *
************************************************************************************/
#include "Std_Types.h"


/************************************************************************************
*                          GLOBAL DATA TYPES AND STRUCTURES                         *
************************************************************************************/ 



typedef     uint_8     GPIO_ChannelType  ;
typedef     uint_8     GPIO_PortType     ;
typedef     uint_8     GPIO_LevelType    ;
typedef     uint_32    GPIO_PortLevelType;


typedef struct
{
	uint_8 Port           ;
	uint_8 Pin            ;
	uint_8 Mode           ;
	uint_8 Direction      ;
	uint_8 Internal_Attach;
	
}Port_ConfigType;

/************************************************************************************
*                               END OF FILE: filename.h                             *
************************************************************************************/

#endif /* GPIOCTRL_TYPES_H */







