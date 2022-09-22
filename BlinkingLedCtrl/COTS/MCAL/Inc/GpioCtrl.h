#ifndef GPIOCTRL_H
#define GPIOCTRL_H


/************************************************************************************
*                                   FILE DESCRIPTION                                *
* ----------------------------------------------------------------------------------*
* File Name : GpioCtrl.h                                                            *
* Brief     : Header file for GPIO Driver                                           *
* Author    : Ola Badr                                                              *
* MC        : TM4C123GH6PM                                                          *
*************************************************************************************/


/************************************************************************************
*                                    INCLUDES                                       *
************************************************************************************/
#include "Std_Types.h"
#include "GpioCtrl_Types.h"

/************************************************************************************
*                         LOCAL MACROS CONSTANT/FUNCTION                            *
************************************************************************************/ 

/*Port ID*/
#define PORTA                  0
#define PORTB                  1
#define PORTC                  2
#define PORTD                  3
#define PORTE                  4
#define PORTF                  5

/*CHANNEL ID*/
#define CHANNEL0               0
#define CHANNEL1               1
#define CHANNEL2               2
#define CHANNEL3               3
#define CHANNEL4               4
#define CHANNEL5               5
#define CHANNEL6               6
#define CHANNEL7               7

/*Internal Attach*/
#define PULL_UP                0
#define PULL_DOWN              1
#define OPEN_DRAIN             2

/*Channel Mode*/
#define GPIO                   0       

/*Direction*/
#define INPUT                  0 
#define OUTPUT                 1


/************************************************************************************
*                               LOCAL FUNCTION PROTOTYPES                           *
************************************************************************************/

/*to get correct port address*/
uint_32 portadd(uint_8 portID);



/************************************************************************************
*                               GLOBAL FUNCTION PROTOTYPES                          *
************************************************************************************/


/*Initialize GPIO Module*/
void Port_Init(const Port_ConfigType* ConfigPtr);

/*Read one bit/channel from port*/
GPIO_LevelType GPIO_ReadChannel ( GPIO_PortType portID, GPIO_ChannelType channelID);

/*Write a value of one bit/channel from port*/
void GPIO_WriteChannel (GPIO_PortType portID, GPIO_ChannelType channelID ,GPIO_LevelType level);

/*Read a value from port*/
GPIO_PortLevelType GPIO_ReadPort(GPIO_PortType portID);

/*Write a value to port*/
void GPIO_WritePort(GPIO_PortType portID , GPIO_PortLevelType level);

/*Toggle channel/bit */
void GPIO_FlipChannel(GPIO_PortType portID, GPIO_ChannelType channelID);


/************************************************************************************
*                               END OF FILE: filename.h                             *
************************************************************************************/

#endif /* GPIOCTRL_H */






