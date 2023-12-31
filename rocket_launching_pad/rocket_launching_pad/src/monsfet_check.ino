// check the dual mons

#include<Arduino.h>

const int first_mon = 16;
const int second_mon = 17;


void setup(){
    pinMode(first_mon , OUTPUT);
    pinMode(second_mon , OUTPUT);

}

void loop(){
    digitalWrite(first_mon , HIGH);
    digitalWrite(second_mon , HIGH);
    delay(1000);

    digitalWrite(first_mon , LOW);
    digitalWrite(second_mon , LOW);
    delay(1000);
}