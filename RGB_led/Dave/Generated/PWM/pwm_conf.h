/*********************************************************************************************************************
* DAVE APP Name : PWM       APP Version: 4.1.10
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015-2016, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-16:
 *     - Initial version for DAVEv4.<BR>
 *
 * 2015-04-06:
 *     - Configuration structure modified of PWM_t.<BR>
 *     - Removed PWM_Dynamic_t,PWM_ConfigType_t.<BR>
 *     - Added New macros for Mixed usage.<BR>
 *     - Added New API PWM_SetPeriodMatchValue().<BR>
 *     - Modified enumeration PWM_InterruptType_t to PWM_INTERRUPT_t.<BR>
 *     - Modified enumeration PWM_OutputPassiveLevelType_t to PWM_OUTPUT_PASSIVE_LEVEL_t.<BR>
 *     - Modified enumeration PWM_TIMER_TYPE_t to PWM_TIMER_SLICE_t .<BR>
 *     - PWM_ClearEvent(), PWM_GetInterruptStatus() and PWM_SetPassiveLevel() API prototype modified for the
 *       new enum.<BR>
 *     - API name change PWM_AcknowledgeInterrupt to PWM_ClearEvent.<BR>
 *
 * 2015-07-09:
 *     - Documentation updated.<BR>
 *
 * 2015-09-01:
 *     - XMC14 device support added.<BR>
 *
 * 2015-10-08:
 *     - Added support for XMC4700/XMC4800 devices.<BR>
 *
 * 2015-12-16:
 *     - Added support for XMC4300 devices.<BR>
 *
 * 2016-07-28:
 *     - All event signals are made mandatory.<BR>
 *
 * @endcond
 *
 */

#ifndef PWMCONF_H
#define PWMCONF_H

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/


#include "GLOBAL_CCU4/global_ccu4.h"
		
/**********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/


#define PWM_0_KERNEL_PTR (XMC_CCU4_MODULE_t*)(void *)CCU40_BASE
#define PWM_0_SLICE_PTR  (XMC_CCU4_SLICE_t*)(void *)CCU40_CC42
/* PWM shadow transfer masks */
#define PWM_0_SLICE_SH_MSK  XMC_CCU4_SHADOW_TRANSFER_SLICE_2
#define PWM_0_PRESCALER_SH_MSK  XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_2


#define PWM_1_KERNEL_PTR (XMC_CCU4_MODULE_t*)(void *)CCU40_BASE
#define PWM_1_SLICE_PTR  (XMC_CCU4_SLICE_t*)(void *)CCU40_CC43
/* PWM shadow transfer masks */
#define PWM_1_SLICE_SH_MSK  XMC_CCU4_SHADOW_TRANSFER_SLICE_3
#define PWM_1_PRESCALER_SH_MSK  XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_3


#define PWM_2_KERNEL_PTR (XMC_CCU4_MODULE_t*)(void *)CCU40_BASE
#define PWM_2_SLICE_PTR  (XMC_CCU4_SLICE_t*)(void *)CCU40_CC40
/* PWM shadow transfer masks */
#define PWM_2_SLICE_SH_MSK  XMC_CCU4_SHADOW_TRANSFER_SLICE_0
#define PWM_2_PRESCALER_SH_MSK  XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_0
   
#define PWM_SLICE_USED_CCU4  1
		
#define PWM_MAJOR_VERSION (4) /**< Major version number of PWM APP*/
#define PWM_MINOR_VERSION (1) /**< Minor version number of PWM APP*/
#define PWM_PATCH_VERSION (10) /**< Patch version number of PWM APP*/


#endif

