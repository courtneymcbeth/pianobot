# PianoBot

PianoBot is a robot that plays the piano. The version that I have constructed is suitable for use on a standard piano with 88 keys. Music is converted from a MIDI file to commands that are transmitted from a computer to an Arduino (an Arduino Mega 2560 in my case; however, other models would also work) using serial communication over bluetooth.

# Bill of Materials

Item | Quantity | Notes
-----|----------|------
[Miuzei SG90 9g Servos](https://www.amazon.com/gp/product/B072V529YD/ref=ppx_yo_dt_b_asin_title_o08_s00?ie=UTF8&psc=1) | 88 | Any standard hobby servos should work
[HC-05 Bluetooth Module](https://www.amazon.com/gp/product/B00INWZRNC/ref=ppx_yo_dt_b_asin_title_o05_s00?ie=UTF8&psc=1) | 1 | Any compatible bluetooth module will work
[16-Channel 12-bit PWM/Servo Shield](https://www.adafruit.com/product/1411) | 6 | These make it possible to control all 88 servos with one Arduino
[Shield Stacking Headers](https://www.adafruit.com/product/85) | 5 | Necessary for using multiple shields
[Right Angle Male Headers](https://www.adafruit.com/product/816) | 5 | Necessary for using multiple shields
[Arduino Mega 2560 Rev3](https://store.arduino.cc/usa/mega-2560-r3) | 1 | Other models should be compatible as well

# System Design

![Image of Piano](/photos/piano_design.jpg)

The above photo shows the design used to create the robot. 
