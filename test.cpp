#include "customecatal.h"
#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    printf("CustomEcatAL(Custom EtherCAT Application Layer)\n");


        EcatInit(ADAPTER_NAME);
        xEcatCommand command;
        xEcatData data;

        command.PositionTargetValue=174663907;
        command.ModeOperation=0x08;
        command.padding=0;
        command.ControlWord=0;
        command.DoStateCommSet=0;
        command.TargetTorque=0;
        command.VITargVelocity=0;
        command.s01_FstSetpoint=0;
        command.TargetVelocity=0;
        setCommandEcat(&command);
        EcatRun();
        getDataEcat(&data);
        usleep(20000);
        printf("status:%d,",data.StatusWord);

        while(data.StatusWord==608){
                command.ControlWord = 0x0006;
                setCommandEcat(&command);
                EcatRun();
                getDataEcat(&data);
                usleep(20000);
                printf("status:%d,", data.StatusWord);
            }


       while(data.StatusWord==561) {
           command.ControlWord = 0x0007;
           setCommandEcat(&command);
           EcatRun();
           getDataEcat(&data);
           usleep(20000);
           printf("status:%d,", data.StatusWord);
       }

      while(data.StatusWord==563) {
          command.ControlWord = 0x00f;
          setCommandEcat(&command);
          EcatRun();
          getDataEcat(&data);
          usleep(20000);
          printf("status:%d,", data.StatusWord);
      }
    command.PositionTargetValue=data.PositionActualUserValue;
        while (1) {
            EcatRun();
            command.PositionTargetValue+=100;
            setCommandEcat(&command);
            getDataEcat(&data);
//            printf("PositionActualUserValue=%d，PositionActualEncoderValue=%d",data.PositionActualUserValue,data.PositionActualEncoderValue);
//
//            printf("\r");
//            printf("\n");
//            fflush(stdout);

            usleep(1000);
        }  
    }
