<!-- PROJECT Tittle and description -->
<div align="center">
 <h1 align="center">Solar-Tracking-Panel
</h1>
  <h3 align="center">The solar tracker panel is a project in which a solar panel is moved automatically with the help of LightDependent Resistor (LDR) sensors and to ensure maximum efficiency. This is a group project for subject Embedded System Development. </h3>
</div>

## Built With

[![Arduino][Arduino.js]][Arduino-url] [![Thingspeak][Thingspeak.js]][Thingspeak-url]

## Component
- Arduino Uno
- NodeMCU
- DHT11
- Servo Motor x2
- Breadboard
- LDR x4
- Mini Solar Panel
- Resistor 220 Ohm x4
- Resistor 10k Ohm

## Circuit Diagram
![alt text](https://github.com/hkmiyj/Solar-Tracking-Panel/blob/master/Image/CircuitDiagram.png)

## Prototype 
The early prototype we use only recycle item such as shoebox, straw and tape. In future we hope that we can design a 3D Model which can be print by 3D printer.

![alt text](https://github.com/hkmiyj/Solar-Tracking-Panel/blob/master/Image/prototype.png)

## Dashboard
For the dashboard we use thingspeak because its free and easy to use. However they are 15 second delay to update the new data.

![alt text](https://github.com/hkmiyj/Solar-Tracking-Panel/blob/master/Image/dashboard_1.png)

## Summary
Based on the findings above, this IoT-Based Solar Tracking Panel will be very useful to collect data and increase the efficiency of the Solar Panel. The proposed idea will help the user to monitor the data from the system and display it in real-time using the dashboard feature inside the ThingSpeak IoT platform. For this project, the expected results for the IoT-Based Solar Tracking Panel is different from the actual results. We had some technical issues on the IoT connection part where we were unable to send the readings of each LDR sensor and the angle of rotation for both of the servo-motors. This issue might occur due to usage of two microcontrollers which are Arduino UNO and NodeMCU or even due to some coding errors. Even though we still could not figure out the root causes of these issues, we still manage to monitor the readings of the LDR and angle of rotation for the servo-motor using a serial monitor in Arduino IDE.


## Demonstration 
Demo 1 <br/>
![alt text](https://github.com/hkmiyj/Solar-Tracking-Panel/blob/master/Image/Part1.gif)
<br/>Demo 2 <br/>
![alt text](https://github.com/hkmiyj/Solar-Tracking-Panel/blob/master/Image/Part2.gif)

<!-- MARKDOWN LINKS & IMAGES -->
[Thingspeak.js]: https://img.shields.io/badge/ThingSpeak-4ddbff?style=for-the-badge&logo=thingspeak&logoColor=white
[Thingspeak-url]: https://thingspeak.com/
[Arduino.js]: https://img.shields.io/badge/Arduino-00b3b3?style=for-the-badge&logo=arduino&logoColor=white
[Arduino-url]: https://firebase.google.com/
