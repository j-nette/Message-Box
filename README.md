# Message-Box
A desktop message box with a handy light and other neat functions.

# Project Features
- A toggleable slow-glow LED
- A dial-controlled menu

# In this repo:
- [enclosure](https://github.com/DistressedFish/Message-Box/tree/master/enclosure) contains Inventor and DWG files for building and prototyping the enclosure
- [code](https://github.com/DistressedFish/Message-Box/tree/master/code) contains Arduino code used in this project
- [circuit](https://github.com/DistressedFish/Message-Box/tree/master/circuit) contains a Frizing file of a one-sided circuit

# Pre-Requisites
As this project uses [Arduino's IOT Cloud](https://create.arduino.cc/iot), you'll need to have an account, your device, and a project set up. Follow this [guide](https://docs.arduino.cc/arduino-cloud/getting-started/iot-cloud-getting-started) to get started.

Please set up the following cloud variables:
- "cloud_light" 
  - Type: Light
  - Variable Permission: Read & Write
  - Send Values: On change
- "message"
  - Type: Character String
  - Variable Permission: Read & Write
  - Send Values: On Change
  
# Components
- Electronics:
  - 2/3 push buttons
  - Piezo buzzer (optional)
  - Slow-glow LED
  - Potentiometer 
  - NodeMCU microcontroller
- Enclosure:
  - I laser cut MDF and glued the pieces together for this project. Feel free to use other materials or even 3D print yours! 
- Circuit:
  - I etched my own circuits for this project. You may also order your own from external sources if you would like. 

# To-Do
- Receive messages from external sources
- Clock, alarm, and timer functions
- Scheduled on/off light
