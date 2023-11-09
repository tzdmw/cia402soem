/*
 * Licensed under the GNU General Public License version 2 with exceptions. See
 * LICENSE file in the project root for full license information
 */

/** \file
 * \brief
 * CanInit() and some useful fuc
 */

#include "simple_can.h"

void CAN_AddTxMessage(CAN_ID can_id, const CAN_TxHeaderTypeDef &pHeader, xEcatCommand &command)
{
    // uint8_t index = 0;
    // if (can_id == CAN_ID::CAN1) {
    //     index = 0;
    // }  else if (can_id == CAN_ID::CAN2) {
    //      index = 2;
    // } else {
    //     return;
    // }

    if (can_id == CAN_ID::CAN1) {
        command.Motor0_cmd = pHeader.info.info;
        command.Motor0.uint32[0] = pHeader.Id;
        for (int i = 0; i < 4; i++) {
            command.Motor0.ch[7-i] = pHeader.data[i];
        }
        for (int i = 4; i < 8; i++) {
            command.Motor0.ch[15-i] = pHeader.data[i];
        }
        // command.Motor0.ch[7] = pHeader.data[0];
        // command.Motor0.ch[6] = pHeader.data[1];
        // command.Motor0.ch[5] = pHeader.data[2];
        // command.Motor0.ch[4] = pHeader.data[3];
        // command.Motor0.ch[11] = pHeader.data[4];
        // command.Motor0.ch[10] = pHeader.data[5];
        // command.Motor0.ch[9] = pHeader.data[6];
        // command.Motor0.ch[8] = pHeader.data[7];
    }  else if (can_id == CAN_ID::CAN2) {
        command.Motor2_cmd = pHeader.info.info;
        command.Motor2.uint32[0] = pHeader.Id;
        for (int i = 0; i < 4; i++) {
            command.Motor2.ch[7-i] = pHeader.data[i];
        }
        for (int i = 4; i < 8; i++) {
            command.Motor2.ch[15-i] = pHeader.data[i];
        }
    } 

}

void CAN_GetRxMessage(CAN_ID can_id, CAN_RxHeaderTypeDef &pHeader, xEcatData &data)
{
    // uint8_t index = 0;
    // if (can_id == CAN_ID::CAN1) {
    //     index = 0;
    // }  else if (can_id == CAN_ID::CAN2) {
    //      index = 2;
    // } else {
    //     return;
    // }

    if (can_id == CAN_ID::CAN1) {
        pHeader.info.info = data.Motor0_cmd;
        pHeader.Id = data.Motor0.uint32[0];
        for (int i = 0; i < 4; i++) {
            pHeader.data[i] = data.Motor0.ch[7-i];
        }
        for (int i = 4; i < 8; i++) {
            pHeader.data[i] = data.Motor0.ch[15-i];
        }
    }  else if (can_id == CAN_ID::CAN2) {
        pHeader.info.info = data.Motor2_cmd;
        pHeader.Id = data.Motor2.uint32[0];
        for (int i = 0; i < 4; i++) {
            pHeader.data[i] = data.Motor2.ch[7-i];
        }
        for (int i = 4; i < 8; i++) {
            pHeader.data[i] = data.Motor2.ch[15-i];
        }
    } 

}




