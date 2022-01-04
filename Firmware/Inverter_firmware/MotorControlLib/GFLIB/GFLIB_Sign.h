/******************************************************************************
*
* (c) Copyright 2009, Freescale & STMicroelectronics
*
***************************************************************************//*!
*
* @file     GFLIB_Sign.h
*
* @author   B04459,R29302
* 
* @version  1.0.1.0
* 
* @date     Dec-6-2012
* 
* @brief    Header file for #GFLIB_Sign function.
*
*******************************************************************************
*
* Function implemented as ANSIC ISO/IEC 9899:1990, C90. 
*
******************************************************************************/
#ifndef GFLIB_SIGN_H_
#define GFLIB_SIGN_H_

#ifndef  _MATLAB_BAM_CREATE    
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_Inlines.h"
#endif

/******************************************************************************
* Defines and macros            (scope: module-local)
******************************************************************************/

/*!
  \def GFLIB_Sign
  Function alias for the #GFLIB_SignANSIC function.
*/
#define GFLIB_Sign(x) GFLIB_SignANSIC(x)

/******************************************************************************
* Typedefs and structures       (scope: module-local)
******************************************************************************/

/******************************************************************************
* Exported Variables
******************************************************************************/

/******************************************************************************
* Exported function prototypes
******************************************************************************/
/*! 
* @ingroup GFLIB_GROUP 
*/ 
extern Frac32 GFLIB_SignANSIC(Frac32 f32In);

/******************************************************************************
* Inline functions
******************************************************************************/ 

#endif /*GFLIB_SIGN_H_*/
