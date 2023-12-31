// check the switch 

#include<Arduino.h>

const int switch_one = 15;


void setup(){
    Serial.begin(9600);

    pinMode(switch_one , INPUT);

}

void loop(){
    int switch_check = analogRead(switch_one);

    // print on the serial monitor
    Serial.print("switch one = ");
    Serial.println(switch_check);
    delay(100);
}