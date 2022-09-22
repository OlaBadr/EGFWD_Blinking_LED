#ifndef STD_TYPE_H
#define STD_TYPE_H


/************************************************************************************
*                                   FILE DESCRIPTION                                *
* ----------------------------------------------------------------------------------*
* File Name : Std_Types.h                                                           *
* Brief     : Standard data types for any embedded project                          *
* Author    : Ola Badr                                                              *
* MC        : Portable                                                              *
*************************************************************************************/

/* Boolean Data Type */
typedef unsigned char bool;

/* Boolean Values */

#define FALSE       (0u)

#define TRUE        (1u)

#define HIGH        (1u)

#define LOW         (0u)

#define NULL_PTR    ((void*)0xFF)

typedef unsigned char         uint_8;          /*           0 .. 255              */
typedef signed char           sint_8;          /*        -128 .. +127             */
typedef unsigned short        uint_16;         /*           0 .. 65535            */
typedef signed short          sint_16;         /*      -32768 .. +32767           */
typedef unsigned int         uint_32;         /*           0 .. 4294967295       */
typedef signed int           sint_32;         /* -2147483648 .. +2147483647      */
/*typedef unsigned long long    uint_64;                0 .. 18446744073709551615 
typedef signed long long      sint_64;         -9223372036854775808 .. 9223372036854775807 */
typedef float                 f_32;
typedef double                f_64;

#endif /* STD_TYPE_H */
