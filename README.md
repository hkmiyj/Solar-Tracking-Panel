# Solar-Tracking-Panel

## Description
The solar tracker panel is a project in which a solar panel is moved automatically with the help of LightDependent Resistor (LDR) sensors and to ensure maximum efficiency. This is a group project for subject Embedded System Development. 

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
The main goal of this project is to develop a solar tracking panel system that can track and follow the movement of the sun based on the received amount of light on the LDR as well as collect humidity and temperature data from DHT11 sensor. The IoT  Based Solar Tracking Panel system also has an internet connection, which allows for the monitoring of the sensor data on a dashboard. Everyone can check the condition of their surroundings at any moment using the dashboard function. Unfortunately there are some unexpected result while doing this project. Tthe complexity of connecting two microcontrollers which are NodeMCU and ArduinoUno, it is almost impossible to communicate with both of them because of a variety of factors. The system should be able to monitor the amount of power that is produced by the solar panel. Unfortunately, due to time constraint and cost limitation we are not able to get the solar panel in our hands. However, monitoring the amount of power is possible and easy to achieve if we have the solar panel.

## Video Demonstration 
Demo 1 <br/>
![alt text](https://github.com/hkmiyj/Solar-Tracking-Panel/blob/master/Image/Part1.gif)
<br/>Demo 2 <br/>
![alt text](https://github.com/hkmiyj/Solar-Tracking-Panel/blob/master/Image/Part2.gif)


