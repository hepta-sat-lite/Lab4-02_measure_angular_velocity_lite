#include "mbed.h"
#include "LITE_EPS.h"
#include "LITE_SENSOR.h"
LITE_EPS eps(PA_0,PA_4);
LITE_SENSOR sensor(PA_7,PB_7,PB_6);
RawSerial pc(USBTX,USBRX,9600);
int main()
{   
    float gx,gy,gz;
    eps.turn_on_regulator(); //Turn on 3.3V converter
    sensor.set_up();
    for(int i=0;i<50;i++){
        sensor.sen_gyro(&gx,&gy,&gz);
        pc.printf("gyro: %f,%f,%f\r\n",gx,gy,gz);
        wait_ms(1000);
    }
}