Sign Language to Text Converter
A Sign Language to Text Converter built using Arduino, developed as part of my coursework at Amrita Vishwa Vidyapeetham, Amrita School of AI. This project aims to bridge the communication gap for deaf and hard-of-hearing individuals by translating sign language gestures into readable text in real-time, using flex sensors mounted on a glove and an Arduino microcontroller.

Features:
Real-Time Translation: Converts hand gestures into text displayed on an LCD or serial monitor.
Flex Sensor Integration: Detects finger movements to identify sign language gestures.
Low-Cost Design: Uses affordable components like Arduino Uno and flex sensors for accessibility.
Customizable Mapping: Maps sensor data to alphabets or words, adaptable for different sign language gestures.
Portable Solution: Wearable glove-based system for practical use in communication.

Tech Stack:
Arduino Uno: Microcontroller for processing sensor inputs and generating text output.
Flex Sensors: Detect finger bending to capture sign language gestures.
Resistors (10kΩ): Stabilize sensor circuit for accurate readings.
Jumper Wires & Breadboard: Facilitate prototyping and connections.
Glove: Base for mounting flex sensors.
Optional: Bluetooth module (e.g., HC-05) for wireless communication with external devices.

Prerequisites:
To run this project, you need:
Arduino IDE (v2.0 or higher)
Hardware components:
Arduino Uno
Flex sensors (5, typically one per finger)
10kΩ resistors (5, one per sensor)
Jumper wires
Breadboard
Glove for mounting sensors
Optional: LCD (e.g., 16x2) or Bluetooth module (HC-05/HC-06)
A computer with USB for programming the Arduino
Optional: Android device with a Bluetooth app (e.g., MIT App Inventor) for wireless output

Installation:
Clone the repository:git clone https://github.com/your-username/sign-language-to-text.git
Navigate to the project directory:cd sign-language-to-text
Set up the hardware:
Attach flex sensors to the glove, one per finger.
Connect each sensor to the Arduino via a 10kΩ resistor on a breadboard (refer to docs/circuit_diagram.png for wiring, if included).
Connect the Arduino to your computer via USB.
Optional: Connect an LCD for text display or an HC-05/HC-06 module for Bluetooth output.
Open the Arduino code:
Load src/sign_language_converter.ino in the Arduino IDE.
Upload the code to the Arduino:
Select your board (Arduino Uno) and port in the Arduino IDE.
Click "Upload" to program the Arduino.

Test the system:
Wear the glove and perform sign language gestures.
View output on the serial monitor (Tools > Serial Monitor, 9600 baud) or LCD.
If using Bluetooth, pair the HC-05/HC-06 with an app (e.g., MIT App Inventor) to view text on a mobile device.

Usage:
Calibration: Adjust sensor thresholds in the Arduino code (src/sign_language_converter.ino) to match your flex sensors and glove fit.
Gesture Mapping: The code maps sensor values to specific gestures (e.g., 32 binary combinations for 5 sensors to words like "Hello" or "Water"). Modify the mapping in the code for custom gestures or alphabets.
Output: Text appears on the serial monitor, LCD, or a paired Bluetooth device.
Testing: Perform sign language gestures (e.g., American Sign Language letters) to verify accurate text conversion.

Project Structure:
src/: Contains the Arduino code (.ino files).
docs/: Optional diagrams (e.g., circuit diagram, if included).
README.md: This file.
LICENSE: MIT License for the project.

Motivation:
Developed at Amrita Vishwa Vidyapeetham, Amrita School of AI, this project reflects my commitment to creating inclusive technology. Inspired by the need to improve communication for deaf and hard-of-hearing individuals, I leveraged Arduino and sensor technology to build an affordable assistive device. I’m deeply grateful to my professors and peers at Amrita for their guidance and support, which fueled this project’s success.
Contributing

Contributions are welcome! To contribute:
Fork the repository.
Create a new branch (git checkout -b feature-branch).
Modify the Arduino code or hardware setup.
Test changes with the Arduino and glove setup.
Commit changes (git commit -m "Add feature").
Push to the branch (git push origin feature-branch).
Open a pull request.

Acknowledgments

Inspired by research on assistive technologies for sign language communication.
Special thanks to Amrita School of AI, Amrita Vishwa Vidyapeetham for providing an innovative learning environment.
References:
Patil et al., "Sign language interpreter for deaf and dumb people," IJRASET, 2019.
Samatha et al., "Sign language to text conversion using flex sensors."
Vismaya et al., "Smart glove using Arduino with sign language recognition system," IJARIIE, 2020.
