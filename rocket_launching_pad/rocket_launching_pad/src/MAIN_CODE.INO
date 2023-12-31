// so lets write the main code of our launching computer

/*

*/

#include <Arduino.h>
#include <Servo.h>
#include <FastLED.h>

// define the servo
Servo First_Servo;
Servo Second_Servo;
Servo Third_Servo;
Servo Four_Servo;
Servo Five_Servo;
Servo Six_Servo;

// define the buzzer
const int buzzer = 5;

// define the monsFate
const int first_monFate = 16;
const int second_monFate = 17;

// define the switch
const int switch_one = 15;

// define the fast led
#define LED_PIN 4 // Change this to the pin where your data line is connected
#define NUM_LED 1 // Change this to the number of LEDs in your strip

CRGB led[NUM_LED];

// lets define the switch variable
int ButtonState = LOW;
int LastButtonState = LOW;
int ButtonPressCount = 0;

// DEFINE THE MILLIS FUNCTION
unsigned long previousMillis = 0;
const long interval = 100; // Blink interval in milliseconds

// define the timer for pyro channel
unsigned long previousTime = 0;
const long delay_time = 5000; // 5 second

// lets blink the inBuild led in teensy lc
// pin number 13
const int led_pin_number_inBuild = 13;
unsigned PreviousMillis = 0;
const long delay_interval = 500; // delay interval in millisecond
int led_InBuild_value = LOW;

// create a function all servo move 0 to 180 degree
void servo_angle()
{
    for (int i = 0; i <= 90; i++)
    {
        First_Servo.write(i);
        Second_Servo.write(i);
        Third_Servo.write(i);
        Four_Servo.write(i);
        Five_Servo.write(i);
        Six_Servo.write(i);
    }
    for (int i = 90; i >= 0; i--)
    {
        First_Servo.write(i);
        Second_Servo.write(i);
        Third_Servo.write(i);
        Four_Servo.write(i);
        Five_Servo.write(i);
        Six_Servo.write(i);
    }
}

void buzzer_first_tone()
{
    // Mavic Pro drone sound frequencies
    int frequencies[] = {200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000};

    for (int i = 0; i < 10; i++)
    {
        tone(buzzer, frequencies[i], 200); // Play each frequency for 100 milliseconds
        delay(50);                         // Add a small delay between tones for a more realistic sound
    }

    noTone(buzzer); // Stop the buzzer after playing the sound
    delay(500);     // Add a pause between each play for a more natural feel

    // hard tone
    for (int loud_buzzer = 0; loud_buzzer <= 4; loud_buzzer++)
    {
        digitalWrite(buzzer, HIGH);
        delay(100); // DELAY FOR 100 MILLISECOND
        digitalWrite(buzzer, LOW);
        delay(100); // DELAY FOR 100 MILLISECOND
    }

    Serial.println("CHECK BUZZER TONE");
}

void led_indicate()
{
    for (int i = 0; i <= 5; i++)
    {
        // Fill the entire strip with a color (red in this case)
        fill_solid(led, NUM_LED, CRGB::Red);
        FastLED.show();
        delay(100); // Pause for 100 milliseconds

        // Fill the entire strip with another color (green in this case)
        fill_solid(led, NUM_LED, CRGB::Green);
        FastLED.show();
        delay(100); // Pause for 100 milliseconds

        // Fill the entire strip with another color (blue in this case)
        fill_solid(led, NUM_LED, CRGB::Blue);
        FastLED.show();
        delay(100); // Pause for 100 milliseconds

        // Fill the entire strip with another color (orange in this case)
        fill_solid(led, NUM_LED, CRGB::Orange);
        FastLED.show();
        delay(100); // Pause for 100 milliseconds

        // Fill the entire strip with another color (skyBlue in this case)
        fill_solid(led, NUM_LED, CRGB::SkyBlue);
        FastLED.show();
        delay(100); // Pause for 100 milliseconds

        //    now turn off the led
        fill_solid(led, NUM_LED, CRGB::Black);
        FastLED.show();
    }

    Serial.println("CHECK LED INDICATE DONE ");
}

void final_buzzer_check()
{
    int second_frequency[] = {300, 600, 900, 1200, 1500, 1800, 2100, 2400, 2700, 3000};

    for (int a = 0; a < 10; a++)
    {
        tone(buzzer, second_frequency[a], 200);
        delay(50);
    }
}

void setup()
{
    Serial.begin(9600);

    // first define the buzzer
    pinMode(buzzer, OUTPUT);
    // define the monsFet
    pinMode(first_monFate, OUTPUT);
    pinMode(second_monFate, OUTPUT);
    // DEFINE THE SWITCH
    pinMode(switch_one, INPUT);
    // define the fastLED
    FastLED.addLeds<WS2812, LED_PIN, GRB>(led, NUM_LED);
    // define the servo motor
    First_Servo.attach(18);
    Second_Servo.attach(19);
    Third_Servo.attach(20);
    Four_Servo.attach(21);
    Five_Servo.attach(22);
    Six_Servo.attach(23);

    pinMode(led_pin_number_inBuild, OUTPUT);

    Serial.println("Servo check ");
    servo_angle();
    Serial.println("Done");
    delay(1000);

    Serial.println("led check  ");
    led_indicate();
    Serial.println("Done");

    Serial.println("buzzer_check");
    buzzer_first_tone();
    Serial.println("Done");
    final_buzzer_check();
}

void InBuild_led_blink()
{
    unsigned long currentMillis_time = millis();
    if (currentMillis_time - PreviousMillis >= delay_interval)
    {
        PreviousMillis = currentMillis_time; // save the current time
        if (digitalRead(led_pin_number_inBuild) == HIGH)
        {
            digitalWrite(led_pin_number_inBuild, LOW);
        }
        else
        {
            digitalWrite(led_pin_number_inBuild, HIGH);
        }
    }
}

void blinkMultipleColors()
{
    // Define an array of colors
    CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Purple, CRGB::OrangeRed, CRGB::LimeGreen, CRGB::OrangeRed, CRGB::HotPink};

    // Choose a random color from the array
    CRGB randomColor = colors[random(0, sizeof(colors) / sizeof(colors[0]))];

    // Turn off all LEDs
    FastLED.clear();

    // Set all LEDs to the random color
    fill_solid(led, NUM_LED, randomColor);

    // Show the colors on the LEDs
    FastLED.show();

    // Pause for a moment to display the color
    delay(100);

    // Turn off all LEDs
    FastLED.clear();

    // Show the colors on the LEDs
    FastLED.show();
}

void buzzer_first_pyro_channel_start()
{

    int buzzer_tone_frequency[] = {200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200, 3600, 4000};

    for (int buzzer_tone_value = 0; buzzer_tone_value < 11; buzzer_tone_value++)
    {
        tone(buzzer, buzzer_tone_frequency[buzzer_tone_value], 100);
        delay(50);
    }

    int buzzer_tone_frequncy_second[] = {600, 1200, 1800, 2400, 3000, 3600, 4200, 4800, 5400, 6000};

    for (int large_tone = 0; large_tone < 10; large_tone++)
    {
        tone(buzzer, buzzer_tone_frequncy_second[large_tone], 100);
        delay(150);
    }

    for (int beep_tone = 0; beep_tone < 3; beep_tone++)
    {

        tone(buzzer, 1800);
        delay(100);
        noTone(buzzer);

        tone(buzzer, 2400);
        delay(100);
        noTone(buzzer);

        tone(buzzer, 1200);
        delay(100);
        noTone(buzzer);

        digitalWrite(buzzer, LOW);
        delay(50);
    }
}

void loop()
{

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
        // Save the current time
        previousMillis = currentMillis;

        // Call the function to blink multiple colors
        blinkMultipleColors();
    }

    InBuild_led_blink();

    ButtonState = digitalRead(switch_one);

    if (ButtonState != LastButtonState)
    {

        if (ButtonState == HIGH)
        {

            ButtonPressCount++;
            Serial.println("Button Pressed ! ");
            Serial.println(ButtonPressCount);

            if (ButtonPressCount == 2 || ButtonPressCount == 4)
            {
                Serial.println(" Pyro channel will we activated ");
                Serial.println("First Pyro channel on 20 second ");
                Serial.println("Second Pyro channel on 60 second ");
                Serial.println(ButtonPressCount);
                delay(500); // delay for 5 second
                buzzer_first_pyro_channel_start();

                // start the timer for 20 second
                for (int buzzer_tone = 0; buzzer_tone <= 5; buzzer_tone++)
                {
                    tone(buzzer, 1800);

                    fill_solid(led, NUM_LED, CRGB::DarkGreen);
                    FastLED.show();

                    delay(1000); // delay for 1 second
                    noTone(buzzer);

                    // tone(buzzer , 600);
                    // delay(1000); //delay for 1 second
                    // noTone(buzzer);

                    digitalWrite(buzzer, LOW);
                    fill_solid(led, NUM_LED, CRGB::Black);
                    FastLED.show();
                    delay(1000);
                }

                // turn on all pyro channel for 5 second
                digitalWrite(first_monFate, HIGH);
                digitalWrite(second_monFate, HIGH);
                fill_solid(led, NUM_LED, CRGB::DarkRed);
                FastLED.show();
                delay(5000); // TURN ON FIRST PYRO CHANNEL FOR 5 SECOND

                digitalWrite(first_monFate, LOW);
                digitalWrite(second_monFate, LOW);
                fill_solid(led, NUM_LED, CRGB::Black);
            }

            if (ButtonPressCount >= 2 || ButtonPressCount >= 4)
            {
                Serial.println(" turn off all system !");
                buzzer_first_pyro_channel_start();

                ButtonPressCount = 0;
            }
        }
    }

    LastButtonState = ButtonState;
    delay(50);

    // Serial.print("switch = ");
    // Serial.println(first_button_state);
    // delay(15);
}
