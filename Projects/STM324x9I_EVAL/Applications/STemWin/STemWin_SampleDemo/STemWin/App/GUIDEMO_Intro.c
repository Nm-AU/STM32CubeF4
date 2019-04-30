/*********************************************************************
*          Portions COPYRIGHT(c) 2016 STMicroelectronics                *
*          Portions SEGGER Microcontroller GmbH & Co. KG             *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2015  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.28 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The  software has  been licensed  to STMicroelectronics International
N.V. a Dutch company with a Swiss branch and its headquarters in Plan-
les-Ouates, Geneva, 39 Chemin du Champ des Filles, Switzerland for the
purposes of creating libraries for ARM Cortex-M-based 32-bit microcon_
troller products commercialized by Licensee only, sublicensed and dis_
tributed under the terms and conditions of the End User License Agree_
ment supplied by STMicroelectronics International N.V.
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : GUIDEMO_Intro.c
Purpose     : Introduction for emWin generic demo
              (This is also a good file to demo and explain basic
              emWin features by setting breakpoints)
----------------------------------------------------------------------
*/

/**
  ******************************************************************************
  * @file    GUIDEMO_Intro.c
  * @author  MCD Application Team
  * @brief   Introduction for emWin generic demo
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

#include <string.h>

#include "GUIDEMO.h"

/*********************************************************************
*
*       Defines
*/
#define SCREEN_DIV          6 // 2^6 = 64

#define FACTOR_EMWIN        4
#define FACTOR_DESC        11
#define FACTOR_ANY_COMP    22
#define FACTOR_VERSION     31
#define FACTOR_LOGO        38
#define FACTOR_WWW         56

#define DIST_ANY_COMP      18

/*********************************************************************
*
*       GUIDEMO_Intro
*
**********************************************************************
*/
void GUIDEMO_Intro(void) {
  char acVersion[30] = "Version of STemWin: ";
  int  xCenter, xSize, ySize;

  xSize   = LCD_GetXSize();
  ySize   = LCD_GetYSize();
  xCenter = xSize >> 1;

  GUIDEMO_DrawBk(0);
  GUI_SetTextMode(GUI_TM_TRANS);
  //
  // emWin
  //
  GUI_SetColor(GUI_WHITE);
  GUI_SetFont(&GUI_FontRounded22);
  GUI_DispStringHCenterAt("STemWin", xCenter, (FACTOR_EMWIN * ySize) >> SCREEN_DIV);
  //
  // emWin description
  //
  GUI_SetFont(&GUI_Font16_ASCII);
  GUI_DispStringHCenterAt("Universal graphic software\nfor embedded applications", xCenter, (FACTOR_DESC * ySize) >> SCREEN_DIV);
  //
  // Any text
  //
  GUI_SetColor(0x2288ff);
  GUI_DispStringHCenterAt("For STM32 MCU Products - Cortex M3 - Cortex M4", xCenter, (FACTOR_ANY_COMP * ySize) >> SCREEN_DIV);
  //
  // Compiled
  //
  GUI_SetFont(&GUI_Font10S_ASCII);
  GUI_DispStringHCenterAt("Compiled " __DATE__ " "__TIME__,          xCenter, ((FACTOR_ANY_COMP * ySize) >> SCREEN_DIV) + DIST_ANY_COMP);
  //
  // Version
  //
  GUI_SetColor(GUI_WHITE);
  GUI_SetFont(&GUI_Font16_ASCII);
  strcat(acVersion, GUI_GetVersionString());
  GUI_DispStringHCenterAt(acVersion, xCenter,  (FACTOR_VERSION * ySize) >> SCREEN_DIV);
  //
  // Logo
  //
  GUI_DrawBitmap(&bmSTLogo, (xSize - bmSeggerLogo.XSize) >> 1, (FACTOR_LOGO * ySize) >> SCREEN_DIV);
  //
  // www.segger.com
  //
  GUI_SetColor(GUI_WHITE);
  GUI_SetFont(&GUI_FontRounded22);
  GUI_DispStringHCenterAt("www.st.com/stm32", xCenter, (FACTOR_WWW * ySize) >> SCREEN_DIV);
  GUIDEMO_Delay(5000);
}

/*************************** End of file ****************************/