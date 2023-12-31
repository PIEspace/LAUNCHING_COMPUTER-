

#include<Arduino.h>

const int buzzer = 5;

void setup(){
    pinMode(buzzer , OUTPUT);
}

void loop(){
      // Mavic Pro drone sound frequencies
  int frequencies[] = {400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000};

  for (int i = 0; i < 9 ; i++) {
    tone(buzzer, frequencies[i], 200); // Play each frequency for 100 milliseconds
    delay(50); // Add a small delay between tones for a more realistic sound

  }

  noTone(buzzer); // Stop the buzzer after playing the sound
  delay(500); // Add a pause between each play for a more natural feel

  // hard tone
  for(int loud_buzzer = 0 ; loud_buzzer <= 4 ; loud_buzzer++)
  {
  digitalWrite(buzzer , HIGH);
  delay(100); //DELAY FOR 100 MILLISECOND 
  digitalWrite(buzzer , LOW);
  delay(100); //DELAY FOR 100 MILLISECOND 
  }
}