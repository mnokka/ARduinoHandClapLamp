//
// Arduino switches on / off table lamp using noise as a switch (hand clamping)
// Usign high voltage load requires knowledge what one is doing. 
// Battery powered lamp can be used instead
// 
//
// mika.nokka1@gmail.com 19.2.2022 based on Arduino web site ideas
//
// Relay low side is connected to Arduino (GND-->GND,VCC --> +5v, IN  pin --> Arduino pin 3)
// Relay high side is connected as series to lamp's one wire (COM and NO)
// More info : https://arduinogetstarted.com/tutorials/arduino-relay
//
// Microphone (just for noice detection) connection (GND->GND, VCC-> +5V, AUD -> Arduino A0)
// Potentiomenter (if in module) can be used to adjust H sensitivity
// More info: https://www.aranacorp.com/en/using-a-microphone-with-arduino/


const int RELAY_PIN = 3;  // relay control out pin
const int MICPIN  = A0;   // microphone input pin
const int DELAY=4000; // minimum delay between commands 
const int THRESHOLD=32; // SW noice threshold

int micValue = 0; // reset read noise for star 
int state =0; // set "lights off" mode for start
int delayCounter=0;
int swithcCounter=0;

// Boot routine
void setup() {
  // initialize pins for digital input / analog input
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(MICPIN, INPUT);
  Serial.begin(9600);
  Serial.println("\n\n..........................................................................");
  Serial.println("\n\nLAMP MASTER IS BOOTING UP.......");
  Serial.print("Delay value between accepted noise commands:"); Serial.println(DELAY);
  Serial.print("Software noice detection threshold:"); Serial.println(THRESHOLD);
  Serial.println("READY!");
  Serial.println("..........................................................................");

}

// main loop
void loop() {
   readMicrophone();
}



void readMicrophone( ) { 
  delayCounter++;

  if (delayCounter < DELAY) {
    return; 
  }
  
  micValue = analogRead(MICPIN);
  //Serial.print(F("Read microphone value:")); Serial.println(micVal);
  if (micValue > THRESHOLD && delayCounter >= DELAY ) {  // adjust noice vs. take action threshold
    Serial.print("Microphone noice detected. Value:"); Serial.println(micValue);
    Serial.print("Delay value:"); Serial.println(delayCounter);
    Serial.print("Detection threshold:"); Serial.println(THRESHOLD);

    if (state==0) {  // swithc lamp on
      state=1;
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("LIGHTS ON");
      swithcCounter++;
      delayCounter=0;
    }
    else if (state==1) { //switch lamp off
      state=0;
      digitalWrite(RELAY_PIN, LOW);
      Serial.println("LIGHTS OFF");
      swithcCounter++;
      delayCounter=0;
    }
    Serial.print(F("Switch number:")); Serial.println(swithcCounter);
    Serial.println("----------------------------------------");
  }
}
