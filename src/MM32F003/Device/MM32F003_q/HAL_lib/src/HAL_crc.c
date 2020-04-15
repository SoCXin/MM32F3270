/**
******************************************************************************
* @file     HAL_crc.c
* @author   AE Team
* @version  V1.0.8
* @date     10/04/2019
* @brief    This file provides all the CRC firmware functions.
******************************************************************************
* @copy
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, MindMotion SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* <h2><center>&copy; COPYRIGHT 2019 MindMotion</center></h2>
*/

/* Includes ------------------------------------------------------------------*/
#include "HAL_crc.h"

/** @addtogroup StdPeriph_Driver
* @{
*/

/** @defgroup CRC
* @brief CRC driver modules
* @{
*/

/** @defgroup CRC_Private_TypesDefinitions
* @{
*/

/**
* @}
*/

/** @defgroup CRC_Private_Defines
* @{
*/

/* CR register bit mask */

#define CR_RESET_Set ((uint32_t)0x00000001)

/**
* @}
*/

/** @defgroup CRC_Private_Macros
* @{
*/

/**
* @}
*/

/** @defgroup CRC_Private_Variables
* @{
*/

/**
* @}
*/

/** @defgroup CRC_Private_FunctionPrototypes
* @{
*/

/**
* @}
*/

/** @defgroup CRC_Private_Functions
* @{
*/

/**
* @brief  Resets the CRC Data register (DR).
* @param  None
* @retval : None
*/
void CRC_ResetDR(void)
{
    /* Reset CRC generator */
    CRC->CR = CR_RESET_Set;
}

/**
* @brief  Computes the 32-bit CRC of a given data word(32-bit).
* @param Data: data word(32-bit) to compute its CRC
* @retval : 32-bit CRC
*/
uint32_t CRC_CalcCRC(uint32_t Data)
{
    int i = 2;

    CRC->DR = Data;
    while (i--);
    return (CRC->DR);
}

/**
* @brief  Computes the 32-bit CRC of a given buffer of data word(32-bit).
* @param pBuffer: pointer to the buffer containing the data to be
*   computed
* @param BufferLength: length of the buffer to be computed
* @retval : 32-bit CRC
*/
uint32_t CRC_CalcBlockCRC(uint32_t pBuffer[], uint32_t BufferLength)
{
    uint32_t index = 0;

    for (index = 0; index < BufferLength; index++) {
        CRC->DR = pBuffer[index];
    }
    return (CRC->DR);
}

/**
* @brief  Returns the current CRC value.
* @param  None
* @retval : 32-bit CRC
*/
uint32_t CRC_GetCRC(void)
{
    return (CRC->DR);
}

/**
* @brief  Stores a 8-bit data in the Independent Data(ID) register.
* @param IDValue: 8-bit value to be stored in the ID register
* @retval : None
*/
void CRC_SetIDRegister(uint8_t IDValue)
{
    CRC->IDR = IDValue;
}

/**
* @brief  Returns the 8-bit data stored in the Independent Data(ID) register
* @param  None
* @retval : 8-bit value of the ID register
*/
uint8_t CRC_GetIDRegister(void)
{
    return (CRC->IDR);
}

/**
* @}
*/

/**
* @}
*/

/**
* @}
*/

/*-------------------------(C) COPYRIGHT 2019 MindMotion ----------------------*/

