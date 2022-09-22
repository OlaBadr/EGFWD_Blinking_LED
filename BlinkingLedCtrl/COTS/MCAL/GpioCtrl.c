/************************************************************************************
*                                   FILE DESCRIPTION                                *
* ----------------------------------------------------------------------------------*
* File Name : GpioCtrl.c                                                            *
* Brief     : Source code for GPIO Module                                           *
* Author    : Ola Badr                                                              *
* MC        : TM4C123GH6PM                                                          *
*************************************************************************************/


/************************************************************************************
*                                    INCLUDES                                       *
************************************************************************************/
#include "Std_Types.h"
#include "GpioCtrl.h"
#include "GpioCtrl_Types.h"
#include "MCU_HW.h"
#include "CommonMacros.h"


/************************************************************************************
*                                   LOCAL FUNCTIONS                                 *
************************************************************************************/

uint_32 portadd(uint_8 portID)
{
	uint_32 localport;
	
	switch (portID)
	{
		case PORTA: 
			localport = GPIO_PORTA_ADD;
			break;
		case PORTB: 
			localport = GPIO_PORTB_ADD;
			break;
		case PORTC: 
			localport = GPIO_PORTC_ADD;
			break;
		case PORTD: 
			localport = GPIO_PORTD_ADD;
			break;
		case PORTE: 
			localport = GPIO_PORTE_ADD;
			break;		
		case PORTF: 
			localport = GPIO_PORTF_ADD;
			break;
		default:
			localport= 0;
			break;
	}

	return localport;
}




/************************************************************************************
*                                   GLOBAL FUNCTIONS                                *
************************************************************************************/

/*----------------------------------------------------------------------------------
-                                Function Description                              -
------------------------------------------------------------------------------------
- FUNCTION_DESCRIPTION : Initialize GPIO Module                                    -
- SYNC/ASYNC           : Synchoronous                                              -
- REENTRANCY           : Non Reentrant                                             -
- IN PRAMETERS         : pointer to struct of GPIO Config                          -
- OUT PRAMETERS        : None                                                      -
- RETURN VALUE         : None                                                      -
-----------------------------------------------------------------------------------*/

void Port_Init(const Port_ConfigType* ConfigPtr)
{
	
  uint_32	localport = portadd(ConfigPtr->Port);
	
	RCGCGPIO |= (1 << (4*ConfigPtr->Port)) ; /*start clock for given port*/
	
	/*to unlock GPIOCR*/
	GPIO_REG( localport , GPIOLOCK) = 0x4C4F434B;
	
	/*to enable changes to other registers*/
	GPIO_REG( localport , GPIOCR) |= ( 1 << ConfigPtr->Pin);

	/*set direction of a channel*/
	if (ConfigPtr->Direction != 0)
	{
	GPIO_REG( localport , GPIODIR) |= ( 1 << (ConfigPtr->Pin) );
	}
	else 
	GPIO_REG( localport , GPIODIR) &=  ~( 1 << (ConfigPtr->Pin) );

    
	/*Configure mode (default GPIO)*/ 
	GPIO_REG( localport , GPIOAFSEL) |= ConfigPtr->Mode;

	/*Enable digital I/O */
	GPIO_REG( localport , GPIODEN) |= (1 << ConfigPtr->Port);
	
	/*Set internal Attach*/
	if (ConfigPtr->Internal_Attach == PULL_UP)
	{
		GPIO_REG( localport, GPIOPUR) |= ( 1 << ConfigPtr->Pin);
		GPIO_REG( localport , GPIOPDR) &= ~( 1 << ConfigPtr->Pin);
	}
	else if (ConfigPtr->Internal_Attach == PULL_DOWN)
	{
		GPIO_REG( localport , GPIOPDR) |= ( 1 << ConfigPtr->Pin);
		GPIO_REG( localport , GPIOPUR) &= ~( 1 << ConfigPtr->Pin);

	}


}

/*----------------------------------------------------------------------------------
-                                Function Description                              -
------------------------------------------------------------------------------------
- FUNCTION_DESCRIPTION : Read a certain bit value                                  -
- SYNC/ASYNC           : Synchoronous                                              -
- REENTRANCY           : Non Reentrant                                             -
- IN PRAMETERS         : portID & channelID                                        -
- OUT PRAMETERS        : None                                                      -
- RETURN VALUE         :  GPIO_LevelType                                           -
-----------------------------------------------------------------------------------*/

GPIO_LevelType GPIO_ReadChannel ( GPIO_PortType portID, GPIO_ChannelType channelID)
{
  uint_32	localport = portadd(portID);

	
if ( ( (1 << (channelID+2) ) | GPIO_REG( localport + 0x3FC ,GPIODATA)) & ( 1 << channelID) )
	return 1;

else 
	return 0;

}


/*----------------------------------------------------------------------------------
-                                Function Description                              -
------------------------------------------------------------------------------------
- FUNCTION_DESCRIPTION : Read a certain bit value                                  -
- SYNC/ASYNC           : Synchoronous                                              -
- REENTRANCY           : Non Reentrant                                             -
- IN PRAMETERS         : channelID & port new value                                -
- OUT PRAMETERS        : None                                                      -
- RETURN VALUE         : None                                                      -
-----------------------------------------------------------------------------------*/

void GPIO_WriteChannel (GPIO_PortType portID, GPIO_ChannelType channelID ,GPIO_LevelType level)
{
  uint_32	localport = portadd(portID);

	if (level == HIGH)
	{
		GPIO_REG( localport + 0x3FC ,GPIODATA) |= 1<<channelID ;
	}

	else if(level == LOW)
	{
			GPIO_REG( localport + 0x3FC ,GPIODATA) &= ~(1<<channelID) ;

	}
}


/*----------------------------------------------------------------------------------
-                                Function Description                              -
------------------------------------------------------------------------------------
- FUNCTION_DESCRIPTION : Read Port Value                                           -
- SYNC/ASYNC           : Synchoronous                                              -
- REENTRANCY           : Non Reentrant                                             -
- IN PRAMETERS         : parameterName Parameter Describtion                       -
-----------------------------------------------------------------------------------*/

GPIO_PortLevelType GPIO_ReadPort(GPIO_PortType portID)
{
  uint_32	localport = portadd(portID);

	return GPIO_REG( localport + 0x3FC ,GPIODATA);
}


/*----------------------------------------------------------------------------------
-                                Function Description                              -
------------------------------------------------------------------------------------
- FUNCTION_DESCRIPTION : Write a value on port                                     -
- SYNC/ASYNC           : Synchoronous                                              -
- REENTRANCY           : Non Reentrant                                             -
-----------------------------------------------------------------------------------*/

void GPIO_WritePort(GPIO_PortType portID , GPIO_PortLevelType level)
{
	
  uint_32	localport = portadd(portID);

	 GPIO_REG( localport + 0x3FC ,GPIODATA) = level;

}

/*----------------------------------------------------------------------------------
-                                Function Description                              -
------------------------------------------------------------------------------------
- FUNCTION_DESCRIPTION : Flip channel                                              -
- SYNC/ASYNC           : Synchoronous                                              -
- REENTRANCY           : Non Reentrant                                             -
-----------------------------------------------------------------------------------*/

void GPIO_FlipChannel(GPIO_PortType portID, GPIO_ChannelType channelID)
{
	  uint_32	localport = portadd(portID);


	GPIO_REG( localport + 0x3FC ,GPIODATA) ^= ( 1 << channelID) ;

}


/************************************************************************************
*                               END OF FILE: filename.c                             *
************************************************************************************/



