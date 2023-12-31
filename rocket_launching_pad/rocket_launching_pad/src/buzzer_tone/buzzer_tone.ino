// lets check the different buzzer tone 


#include<Arduino.h>

const int buzzer = 5;

void setup(){
    pinMode(buzzer , OUTPUT);

     int frequency[] = {400,800,1200,1600,2000,2400,2800,3200,3600,4000};

     for (int  i = 0; i <= 10; i++)
     {
        tone(buzzer , frequency[i] , 100 );
        delay(50);
     }
}

void loop(){

}