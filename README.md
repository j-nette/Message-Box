# Message-Box
A desktop message box with a handy light and other neat functions

# Features
- A toggleable slow-glow LED
- A dial-controlled menu

# Pre-Requisites
As this project uses [Arduino's IOT Cloud](https://create.arduino.cc/iot), you'll need to have an account, your device, and a project set up. Follow this [guide](https://docs.arduino.cc/arduino-cloud/getting-started/iot-cloud-getting-started) to get started!

Please set up the following cloud variables:
- cloud_light 
  - Type: Light
  - Variable Permission: Read & Write
  - Send Values: On change
- message
  - Type: Character String
  - Variable Permission: Read & Write
  - Send Values: On Change
  
# Components
- 2/3 pushbuttons
- Piezo buzzer (optional)
- Slow-glow LED
- Potentiometer 
- NodeMCU microcontroller

# To-Do
- Receive messages from external sources
- Clock, alarm, and timer functions
- Scheduled on/off light
