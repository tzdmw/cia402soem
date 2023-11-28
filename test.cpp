#include "customecatal.h"
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("CustomEcatAL(Custom EtherCAT Application Layer)\n");


        EcatInit(ADAPTER_NAME);
        xEcatCommand command;
        xEcatData data;

        command.PositionTargetValue=0;
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
        command.PositionTargetValue=data.PositionActualUserValue;//如果不初始化就会失控出错，重启才行
        while (1) {
            EcatRun();
            command.PositionTargetValue+=1;//加到1000就寄了
            setCommandEcat(&command);
            getDataEcat(&data);
            if(data.ErrorCode!=0)
            printf("error value:%d\n",data.ErrorCode);
            usleep(1000);//延时太短容易寄
        }  
    }
