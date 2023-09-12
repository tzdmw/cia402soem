#include "customecatal.h"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("CustomEcatAL(Custom EtherCAT Application Layer)\n");

    EcatInit();

    xEcatCommand command;
    xEcatData data;

    command.Motor3_cmd = 0x87;
    command.Motor3.float32[0] = 0.0f;
    command.Motor3.float32[1] = 10.0f;

    while (1) {
        EcatRun();

        setCommandEcat(&command);
        getDataEcat(&data);

        command.Motor3.float32[0] += 1;

        printf(" %2.2f, %2.2f | %2.2f, %2.2f", command.Motor3.float32[0], data.Motor3.float32[0], command.Motor3.float32[1], data.Motor3.float32[1]);
        printf("\r");
        fflush(stdout);

        usleep(500);
    }  

    return 0;
}