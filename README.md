# ArduinoHandClapLamp
Control logic SW for Arduino managed table lamp. Uses noice as switching command. Arduino Uno + relay and microphone modules required.


Info:

Using high voltage load requires knowledge what one is doing. 
Battery powered lamp can be used instead


HW info:

Relay low side is connected to Arduino (GND-->GND,VCC --> +5v, IN  pin --> Arduino pin 3)
Relay high side is connected as series to lamp's one wire (COM and NO)
More info : https://arduinogetstarted.com/tutorials/arduino-relay

Microphone (just for noice detection) connection (GND->GND, VCC-> +5V, AUD -> Arduino A0)
Potentiometer (if in module) can be used to adjust H sensitivity
More info: https://www.aranacorp.com/en/using-a-microphone-with-arduino/
