
# About project
This project involves creating a portable EKG (Electrocardiogram) system using Arduino. The system uses ECG sensors to capture the electrical activity of the heart and displays the real-time readings on a 128x64 display. The primary components of this project include an Arduino board, ECG sensor, and a 128x64 display.
# Hardware and Materials Used
#### - Arduino Mega
#### -  ST7920 128x64 display
#### - ECG AD8232 Sensor
#### - BreadBoard
#### - Wires

# Instructions
Prepare all the materials and connect them as follows:
![Project Scheme](https://github.com/Nix0712/EKG-Arduino-Project/blob/main/Scheme/EkgPhoto.png?raw=true)

- After connecting all the components, open the Arduino IDE and load the **EKG_Project.ino** file.
- Next, install the **U8g2lib** library. For guidance on installing libraries, refer to the [official tutorial](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/ "official tutorial").
- The final step is to compile the code and upload it to your Arduino.

### How to connect ECG sensord?
This ECG sensor is 3 lead single-channel ECG module. Other ECG sensor types available are 5 lead and 10 lead. Visit this link for more details about ECG positioning: https://litfl.com/ECG-lead-positioning/

For a 3-lead system, there are two placements that are used:

<div align="center">

| Electrode Name  | Electrode colour | Location |
| ------------- | ------------- | ------------- |
| RA  | Red  | Right Arm  |
| LA  | Yellow  | Left Arm |
| RL  | Green  | Right Leg |

</div>
<p align="center">
<img src="https://circuitdigest.com/sites/default/files/inlineimages/u3/ECG-Electrodes-Placement.png">
</p>



