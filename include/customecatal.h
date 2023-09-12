/*
 * Licensed under the GNU General Public License version 2 with exceptions. See
 * LICENSE file in the project root for full license information
 */

/** \file
 * \brief
 * Headerfile for customecatal.c
 */

#ifndef _CUSTOM_ECAT_AL
#define _CUSTOM_ECAT_AL

#include <stdint.h>

#define ADAPTER_NAME        "enp86s0"
#define EXPECTED_SLAVE      3

void EcatInit();
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
struct xEcatCommand
{
    uint8_t Motor0_cmd; /* Subindex1 - motor0_cmd */
    uint8_t Motor1_cmd; /* Subindex2 - motor1_cmd */
    uint8_t Motor2_cmd; /* Subindex3 - motor2_cmd */
    uint8_t Motor3_cmd; /* Subindex4 - motor3_cmd */
    FormatBytes Motor0; /* Subindex5 - motor0 */
    FormatBytes Motor1; /* Subindex6 - motor1 */
    FormatBytes Motor2; /* Subindex7 - motor2 */
    FormatBytes Motor3; /* Subindex8 - motor3 */

};

/*!
 * Data received from xEcat board
 */
struct xEcatData
{
    uint8_t Motor0_cmd; /* Subindex1 - motor0_cmd */
    uint8_t Motor1_cmd; /* Subindex2 - motor1_cmd */
    uint8_t Motor2_cmd; /* Subindex3 - motor2_cmd */
    uint8_t Motor3_cmd; /* Subindex4 - motor3_cmd */
    FormatBytes Motor0; /* Subindex5 - motor0 */
    FormatBytes Motor1; /* Subindex6 - motor1 */
    FormatBytes Motor2; /* Subindex7 - motor2 */
    FormatBytes Motor3; /* Subindex8 - motor3 */
};

void getDataEcat(xEcatData* data);
void setCommandEcat(xEcatCommand* command);

#endif /* _CUSTOM_ECAT_AL */
