# Instrument_cluster
This project involves the implementation of an instrument cluster as the second DES (Distributed Embedded Systems) project in the SEA:ME curriculum.

## Overview
An instrument cluster, also known as a dashboard cluster or gauge cluster, is a critical component of a vehicle’s dashboard. It provides the driver with essential information about the vehicle’s status and performance through various gauges, indicators, and warning lights. Here, we implement an instrument cluster showing real-time speed data on a screen with GUI.

## Theoratical Background
[CAN bus protocol](https://github.com/SEA-ME-DES-01-Instrument-Cluster/Instrument_cluster/wiki/About-CAN-bus-protocol)

[Speed sensor](https://github.com/SEA-ME-DES-01-Instrument-Cluster/Instrument_cluster/wiki/Specifications-and-usage-of-speed-sensors-compatible-with-Arduino)

[Qt framework its tools for GUI](https://github.com/SEA-ME-DES-01-Instrument-Cluster/Instrument_cluster/wiki/Basics-of-the-Qt-framework-and-its-tools-for-developing-embedded-GUIs)

[What is Bare Metal?](https://github.com/SEA-ME-DES-01-Instrument-Cluster/Instrument_cluster/wiki/What-is-Bare-Metal%3F#what-is-bare-metal)

## System Architecture

## Software Design

## Configuration
### Display - WaveShare 7.9inch SDI LCD
After we have written RaspberryPi OS (Debian Bookwarm, 64bit) to a sd card, we have added lines below to 'config.txt' at the root of the sd card file system. And ejected the sd card and boot up our Raspberry Pi, and we were able to see the display working as expected.
```
(...)
# WaveShare 7.9inch LCD
dtoverlay=vc4-kms-v3d
dtoverlay=vc4-kms-dsi-waveshare-panel,7_9_inch
```

## Result

## Conclusion

## Contributors
