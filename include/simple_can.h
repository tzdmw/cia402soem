/*
 * Licensed under the GNU General Public License version 2 with exceptions. See
 * LICENSE file in the project root for full license information
 */

/** \file
 * \brief
 * Headerfile for simple_can.cpp
 */

#ifndef _SIMPLE_CAN
#define _SIMPLE_CAN

#include <stdint.h>
#include "customecatal.h"

  typedef  struct
  {
    uint8_t DLC:4;
    uint8_t null:2;
    uint8_t RTR:1;
    uint8_t FF:1;
  } sFrameInfo;

typedef union simple_can
{
  sFrameInfo sinfo;
  uint8_t info;
} uFrameInfo;


/**
  * @brief  CAN Tx message header structure definition
  */
typedef struct
{
  uint32_t Id;    /*!< Specifies the standard identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF. */
                        /*!< Specifies the extended identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFF. */
  uFrameInfo info;
  uint8_t data[8];

} CAN_TxHeaderTypeDef;

/**
  * @brief  CAN Rx message header structure definition
  */
typedef struct
{
  uint32_t Id;    /*!< Specifies the standard identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF. */
                        /*!< Specifies the extended identifier.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFF. */
  uFrameInfo info;
  uint8_t data[8];

} CAN_RxHeaderTypeDef;

enum class CAN_ID
{
    CAN_ALL,
    CAN1,
    CAN2
} ;

void CAN_AddTxMessage(CAN_ID can_id, const CAN_TxHeaderTypeDef &pHeader, xEcatCommand &command);
void CAN_GetRxMessage(CAN_ID can_id, CAN_RxHeaderTypeDef &pHeader, xEcatData &data);

#endif /* _SIMPLE_CAN */
