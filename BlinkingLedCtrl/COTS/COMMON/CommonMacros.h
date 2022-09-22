#ifndef COMMONMACROS_H
#define COMMONMACROS_H


/************************************************************************************
*                                   FILE DESCRIPTION                                *
* ----------------------------------------------------------------------------------*
* File Name : CommonMacros.h                                                        *
* Brief     : important macros needed for essential registers operations            *
* Author    : Ola Badr                                                              *
* MC        : Portable                                                              *
*************************************************************************************/


/* Set a certain bit/channel in any register */
#define SET_CHANNEL(Register,channel) (Register|=(1<<channel))

/* Clear a certain bit/channel in any register */
#define CLR_CHANNEL(Register,channel) (Register&=(~(1<<channel)))

/* Toggle a certain bit/channel in any register */
#define TOGGLE_CHANNEL(Register,channel) (Register^=(1<<channel))

/* Check if a specific bit/channel is set in any register and return true or false */
#define CHANNEL_IS_SET(Register,channel) ( Register & (1<<channel) )

/* Check if a specific bit/channel is cleared in any register and return true or false*/
#define CHANNEL_IS_CLR(Register,channel) ( !(Register & (1<<channel)) )

#endif  /* COMMONMACROS_H */
