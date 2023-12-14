/* 
 * File:   mcal_std_types.h
 * Author: Mo'men Ahmed
 *
 * Created on July 26, 2023, 8:39 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/*************************************** Include section ******************************************************/
#include "std_libraries.h"
#include "compiler.h"
/************************************** End of Include section ************************************************/

/*************************************** Standard Data types section ******************************************/
/*************************************/
#define CPU_TYPE (CPU_TYPE_8)
/*************************************/
#if (CPU_TYPE == CPU_TYPE_8)

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef float float32;


#elif (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_16)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_64)

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#endif
/************************************ End Standard Data types section ******************************************/

/************************************** User Defined Data types Section ****************************************/

typedef uint8 Std_ReturnType;

/*Macro Declarations :*/

#define STD_HIGH   (0X01)
#define STD_LOW    (0X00)

#define STD_ON     (0X01)
#define STD_OFF    (0X00)

#define STD_ACTIVE (0X01)
#define STD_IDLE   (0X00)

#define E_OK       ((Std_ReturnType)0X01)
#define E_NOT_OK   ((Std_ReturnType)0X00)

/*End of Macro Declarations*/


/*********************************** End of User Defined Data types Section ************************************/
#endif	/* MCAL_STD_TYPES_H */

