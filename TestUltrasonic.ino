/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

int latchPin = 4;
int clkPin = 5;
int dataPin = 2;
int sroePin = 3;

int echoPin = 8;
int trigPin = 7;

/*
int sonicPulse(int angle) {
    digitalWrite(PIN_UltrasonicTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(PIN_UltrasonicTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_UltrasonicTrig, LOW);

    int duration = pulseIn(PIN_UltrasonicEcho, HIGH);
    //Serial.print(millis());
    //Serial.print(" ");
    //Serial.print(duration);
    //Serial.println("D ");
    int distance = duration / 29 / 2;

    return distance;
}*/


// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(9600);
    Serial.println("Init");
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(sroePin, OUTPUT);
    pinMode(clkPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
bool light = 1;
void loop() {
    digitalWrite(13, light = !light); 

    for (int i = 0; i <= 6; i++) {
        int mask = 1 << i;
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clkPin, MSBFIRST, mask);
        digitalWrite(latchPin, HIGH);
        digitalWrite(sroePin, 0);

        digitalWrite(trigPin, 1);
        delayMicroseconds(10);
        digitalWrite(trigPin, 0);

        //Serial.print("echo");
        //Serial.println(digitalRead(echoPin));
        digitalWrite(sroePin, 1);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clkPin, MSBFIRST, 0);
        digitalWrite(latchPin, HIGH);

        int duration = pulseIn(echoPin, HIGH);
        //Serial.print("echo");
        //Serial.print(digitalRead(echoPin));
        //Serial.println(duration);
        int distance = duration / 29 / 2;
        Serial.print(mask);
        Serial.print(" -> ");
        Serial.print(distance);
        //Serial.print(" (");
        //Serial.print(duration);
        //Serial.println(")");
        Serial.println();
        delay(40);
    }


    delay(500);
            // wait for a second
}
