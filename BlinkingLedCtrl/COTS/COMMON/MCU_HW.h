#ifndef MCU_HW_H
#define MCU_HW_H


/************************************************************************************
*                                   FILE DESCRIPTION                                *
* ----------------------------------------------------------------------------------*
* File Name : MCU_HW.h                                                              *
* Brief     : Hardware Registers' definitions                                       *
* Author    : Ola Badr                                                              *
* MC        : TM4C123GH6PM                                                          *
*************************************************************************************/

/************************************************************************************
*                                 INCLUDES                                          *
*********************************************************************************** */
#include "Std_Types.h"

/************************************************************************************
*                               SYSTEM CONTROL                                      *
*********************************************************************************** */

#define SYSCTL_BASE_ADDRESS              0x400FE000
#define RCGCTIMER                        ( *((volatile uint_32 *)(SYSCTL_BASE_ADDRESS + 0x604)) )
#define RCGCGPIO                         ( *((volatile uint_32 *)(SYSCTL_BASE_ADDRESS + 0x608)) )

/************************************************************************************
*                                   GPIO REG                                        *
*********************************************************************************** */
#define GPIO_BASE_ADDRESS

#define GPIO_PORTA_ADD                       0x40058000
#define GPIO_PORTB_ADD                       0x40059000
#define GPIO_PORTC_ADD                       0x4005A000
#define GPIO_PORTD_ADD                       0x4005B000
#define GPIO_PORTE_ADD                       0x4005C000
#define GPIO_PORTF_ADD                       0x4005D000

#define PORTA_ID                        0
#define PORTB_ID                        1
#define PORTC_ID                        2
#define PORTD_ID                        3
#define PORTF_ID                        4
#define PORTE_ID                        5

#define  GPIODATA   0x000   /*GPIO Data*/
#define  GPIODIR    0x400   /*GPIO Direction*/
#define  GPIOAFSEL  0x420   /*GPIO Alternate Function Select*/
#define  GPIOPUR    0x510   /*GPIO Pull-Up Select*/
#define  GPIOPDR    0x514   /*GPIO Pull-Down Select*/
#define  GPIODEN    0x51C   /*GPIO Digital Enable*/
#define  GPIOLOCK   0x520   /*GPIO Lock*/
#define  GPIOCR     0x524   /*GPIO Commit*/
#define  GPIOPCTL   0x52C   /*GPIO Port Control*/

#define GPIO_REG(Port_Macro,Reg_Macro)      (*((volatile uint_32 *)(Port_Macro + Reg_Macro)))

/************************************************************************************
*                                     NVIC/SCB                                      *
*********************************************************************************** */
#define CORE_PERIPHERAL_BASE_ADDRESS               0xE000E000


#define INTCTRL               (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0xD04)))
#define APINT                 (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0xD0C)))
#define PRIGROUP               8

#define NVIC_EN0              (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x100)))
#define NVIC_EN1              (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x104)))
#define NVIC_EN2              (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x108)))
#define NVIC_EN3              (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x10C)))
#define NVIC_EN4              (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x110)))

#define NVIC_DIS0             (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x180)))
#define NVIC_DIS1             (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x184)))
#define NVIC_DIS2             (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x188)))
#define NVIC_DIS3             (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x18C)))
#define NVIC_DIS4             (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x190)))

#define NVIC_PEND0            (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x200)))
#define NVIC_PEND1            (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x204)))
#define NVIC_PEND2            (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x208)))
#define NVIC_PEND3            (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x20C)))
#define NVIC_PEND4            (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x210)))

#define NVIC_UNPEND0          (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x280)))
#define NVIC_UNPEND1          (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x284)))
#define NVIC_UNPEND2          (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x288)))
#define NVIC_UNPEND3          (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x28C)))
#define NVIC_UNPEND4          (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x290)))

#define NVIC_PRI0             (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x400)))

/************************************************************************************
*                                    SYSTICK                                        *
*********************************************************************************** */

#define STCTRL                (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x010)))
#define STRELOAD              (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x014)))
#define STCURRENT             (*((volatile uint_32 *)(CORE_PERIPHERAL_BASE_ADDRESS + 0x018)))

#define STCTRL_ENABLE                0
#define STCTRL_INTEN                 1
#define STCTRL_CLK_SRC               2
#define STCTRL_COUNT                 16

/************************************************************************************
*                                     TIMER0                                        *
*********************************************************************************** */


#endif  /* MCU_HW_H */
