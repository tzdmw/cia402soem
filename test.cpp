#include "customecatal.h"
#include <unistd.h>
#include <stdio.h>
#include "simple_can.h"

int main(int argc, char *argv[])
{
    printf("CustomEcatAL(Custom EtherCAT Application Layer)\n");

    if (argc > 1) {
        EcatInit(argv[1]);

        xEcatCommand command;
        xEcatData data;

        CAN_TxHeaderTypeDef tx;
        CAN_TxHeaderTypeDef tx_2;
        CAN_RxHeaderTypeDef rx;
        CAN_RxHeaderTypeDef rx_2;

        tx.info.sinfo.FF = 0;
        tx.info.sinfo.DLC = 0;
        // tx.info.info =  0x08;
        tx.data[0] = 0x01;
        tx.data[1] = 0x02;
        tx.data[2] = 0x03;
        tx.data[3] = 0x04;
        tx.data[4] = 0x05;
        tx.data[5] = 0x06;
        tx.data[6] = 0x07;
        tx.data[7] = 0x08;
        tx.Id = 0xffffffff;

        command.Motor3_cmd = 0x87;
        command.Motor3.float32[0] = 0.0f;
        command.Motor3.float32[1] = 10.0f;

        while (1) {
            EcatRun();

            setCommandEcat(&command);
            getDataEcat(&data);

            command.Motor3.float32[0] += 1;

            // printf(" %2.2f, %2.2f | %2.2f, %2.2f", command.Motor3.float32[0], data.Motor3.float32[0], command.Motor3.float32[1], data.Motor3.float32[1]);
            // printf("\r");
            // fflush(stdout);


            CAN_AddTxMessage(CAN_ID::CAN1, tx, command);
            CAN_GetRxMessage(CAN_ID::CAN1, rx, data);
            CAN_AddTxMessage(CAN_ID::CAN2, tx_2, command);
            CAN_GetRxMessage(CAN_ID::CAN2, rx_2, data);

            tx.info.sinfo.DLC += 1;
            if (tx.info.sinfo.DLC > 8) {
                tx.info.sinfo.DLC = 0;
                tx.info.sinfo.FF = ~tx.info.sinfo.FF;
            }
            tx.Id += 1;
            tx_2 = tx;

            printf(" CAN1:// %x, %x | %x, %x, %x, %x, %x, %x, %x, %x |--|", rx.info.info, rx.Id, rx.data[0], rx.data[1], rx.data[2], rx.data[3], rx.data[4], rx.data[5], rx.data[6], rx.data[7]);
            printf(" CAN2:// %x, %x | %x, %x, %x, %x, %x, %x, %x, %x", rx_2.info.info, rx_2.Id, rx_2.data[0], rx_2.data[1], rx_2.data[2], rx_2.data[3], rx_2.data[4], rx_2.data[5], rx_2.data[6], rx_2.data[7]);
            printf("\r");
            // printf("\n");
            fflush(stdout);

            usleep(200);
        }  
    } else {
        printf("Usage: CustomEcatAL ifname1\nifname = enp86s0 for example\n");
    }
    return 0;
}