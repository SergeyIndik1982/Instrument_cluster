
This project involves the implementation of an instrument cluster as the second DES (Distributed Embedded Systems) project in the SEA:ME curriculum.

## Overview
An instrument cluster, also known as a dashboard cluster or gauge cluster, is a critical component of a vehicle’s dashboard. It provides the driver with essential information about the vehicle’s status and performance through various gauges, indicators, and warning lights. Here, we implement an instrument cluster showing real-time speed data on a screen with GUI.

## Theoratical Background
- [CAN bus protocol](https://github.com/SEA-ME-DES-01-Instrument-Cluster/Instrument_cluster/wiki/About-CAN-bus-protocol)
- [Speed sensor](https://github.com/SEA-ME-DES-01-Instrument-Cluster/Instrument_cluster/wiki/Specifications-and-usage-of-speed-sensors-compatible-with-Arduino)
- [Qt framework its tools for GUI](https://github.com/SEA-ME-DES-01-Instrument-Cluster/Instrument_cluster/wiki/Basics-of-the-Qt-framework-and-its-tools-for-developing-embedded-GUIs)
- [What is Bare Metal?](https://github.com/SEA-ME-DES-01-Instrument-Cluster/Instrument_cluster/wiki/What-is-Bare-Metal%3F#what-is-bare-metal)

You can also find those topics on our Wiki.

## System Architecture
![diagram](https://github.com/user-attachments/assets/8ae8d5d4-0fb4-49fa-a1e7-920512416694)# Instrument_cluster


## Components and Environment
### Hardware
- [WaveShare JetRacer AI Kit)](https://www.waveshare.com/wiki/JetRacer_AI_Kit)
- [MH Infrared Speed Sensor Module (FC-03)](https://einstronic.com/product/infrared-speed-sensor-module/)
- [Arduino Nano](https://docs.arduino.cc/hardware/nano/)
- [MCP2515 CAN BUS Module](https://ww1.microchip.com/downloads/aemDocuments/documents/APID/ProductDocuments/DataSheets/MCP2515-Family-Data-Sheet-DS20001801K.pdf)
- [SeeedStudio 2-CH CAN FD HAT](https://wiki.seeedstudio.com/2-Channel-CAN-BUS-FD-Shield-for-Raspberry-Pi/)
- [Raspberry Pi 4B](https://www.raspberrypi.com/products/raspberry-pi-4-model-b/)
- [WaveShare 7.9inch DSI LCD](https://www.waveshare.com/wiki/7.9inch_DSI_LCD)

![1732800781849](https://github.com/user-attachments/assets/3d28ee5e-4d9a-4bea-acec-6a306ba6de0f)
![1732800781113](https://github.com/user-attachments/assets/de8b899a-3bb0-457d-a913-de6557af1614)
![1732800781309](https://github.com/user-attachments/assets/a9b81989-b963-4a2e-ac2b-aeb1d4c27ae5)

### Software
- Main application: C++(Qt framework)
- Firmware(for Arduino): C
- Host OS(for development): Ubuntu 20.04
- Raspberry Pi: Rasbian Desktop 64bit
- IDE: Qt Creator, Arduino IDE
- Version control: Git

## Configuration
### Display - WaveShare 7.9inch DSI LCD
After we have written RaspberryPi OS (Debian Bookwarm, 64bit) to a sd card, we have added lines below to 'config.txt' at the root of the sd card file system. And ejected the sd card and boot up our Raspberry Pi, and we were able to see the display working as expected.
```
(...)
# WaveShare 7.9inch LCD
dtoverlay=vc4-kms-v3d
dtoverlay=vc4-kms-dsi-waveshare-panel,7_9_inch
```

### SeeedStudio 2-CH CAN HAT for Raspberry Pi
[Followed instructions on here](https://wiki.seeedstudio.com/2-Channel-CAN-BUS-FD-Shield-for-Raspberry-Pi/)
To activate CAN protocol on Raspberry Pi, you need to run:
```
sudo ip link set can1 up type can bitrate 500000
```

### Auto start Instrument Cluster at booting
```
# /etc/xdg/autostart/InstrumentCluster.desktop

[Desktop Entry]
Type=Application
Exec=/home/pi/InstrumentCluster
Hidden=false
NoDisplay=false
X-GNOME-Autostart-enabled=true
Name[en_US]=InstrumentCluster
Name=InstrumentCluster
Comment[en_US]=Start Instrument Cluster at startup
Comment=Start Instrument Cluster at startup
```
## Result
We tested the prototype both on the stand and on the track, as a result all data is displayed correctly, both speed and battery charge
<img width="1278" height="399" alt="380765989-d907358c-8378-414e-980e-308d59534e3e" src="https://github.com/user-attachments/assets/4b7f9cc1-55bc-48b1-b525-859e323fe372" />
![1732800781657](https://github.com/user-attachments/assets/b777f154-d483-421c-bcd0-4d8319991da8)
![1732800781187](https://github.com/user-attachments/assets/6c531da4-a5ff-458f-9b56-0bcb2c2dd2f9)

## Conclusion
The project is very important for understanding the interaction of sensors with the controller and computer, as well as data transmission via the CAN system, and processing this data for display on the screen
## Contributors
https://github.com/isragogreen
https://github.com/Clearsu
https://github.com/SergeyIndik1982
