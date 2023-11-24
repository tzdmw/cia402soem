/*
 * Licensed under the GNU General Public License version 2 with exceptions. See
 * LICENSE file in the project root for full license information
 */

/** \file
 * \brief
 * Headerfile for customecatal.cpp
 */

#ifndef _CUSTOM_ECAT_AL
#define _CUSTOM_ECAT_AL

#include <stdint.h>
#include "ethercat.h"
#define ADAPTER_NAME        "eno1"
#define EXPECTED_SLAVE      1

void EcatInit(char *ifname);
void EcatRun();


typedef union
{
    char      ch[12];
    float     float32[3];
    int16_t   int16[6];
    int32_t   int32[3];
    uint16_t  uint16[6];
    uint32_t  uint32[3];
} FormatBytes;

/*!
 * Command sent to xEcat board
 */
#pragma pack(show)
#pragma pack (1)
struct xEcatCommand
{
    uint16_t ControlWord;
    uint8_t ModeOperation;
    uint8_t padding;
    int32_t PositionTargetValue;
    int16_t VITargVelocity;//VM 模式的目标速度
    int16_t TargetTorque;//设置目标转矩
    int32_t s01_FstSetpoint;//设置插补目标位置
    int32_t TargetVelocity;//目标速度
    uint16_t DoStateCommSet;//通信给定 VDI 虚拟电平
};

/*!
 * Data received from xEcat board
 */
struct xEcatData
{
    uint16_t ErrorCode;
    uint16_t StatusWord;
    uint8_t ModesOfOperationDisplay;
    uint8_t padding;
    int32_t PositionActualUserValue;//电机当前的用户绝对位置反馈（用户单位）
    int32_t PositionActualEncoderValue;//电机当前的绝对位置反馈（编码器单位）
    int32_t VelocitySensorActualValue;//速度传感器的反馈值
    int32_t VelocityActualValue;//当前的实际速度反馈值
    int16_t TorqueActualValue ;//扭矩反馈值
    int16_t CurrentActualValue;//电流反馈值
    uint16_t MonitoredDiStates;//实体端子对应的实际电平状态
};
#pragma pack ()
void getDataEcat(xEcatData* data);
void setCommandEcat(xEcatCommand* command);

#endif /* _CUSTOM_ECAT_AL */
