/*
 * @File : Common Macros.h
 * @Author: Mo'men Elhoseiny
 * @Brief: Contains definition for commonly used macros
 * @Creation Date: 26 July 2023
 */
#ifndef COMMONMACROS_H
#define	COMMONMACROS_H

/************************** Macro Functions section ***************************/
#define SET_BIT(REG,BIT)      (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT)    (REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)   (REG^=(1<<BIT))
#define READ_BIT(REG,BIT)     ((REG >> BIT) & 1)
/******************************************************************************/

#endif	/* COMMONMACROS_H */

