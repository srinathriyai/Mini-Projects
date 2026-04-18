# LabVIEW ESP32 Test Bench

A mini project I built over one week to get hands-on experience with LabVIEW for hardware test, firmware validation, and data acquisition. 

I'm working toward entry-level roles in hardware test and firmware validation, with a long-term goal of R&D in medical devices.
LabVIEW is used heavily in medtech for test automation and V&V, so I wanted real hands-on experience building something
from scratch rather than just following tutorials.

This project took about 1.5 weeks total, around 2 hours of work on weekdays; longer than planned but I built 
everything step by step to actually understand how it works.

## What I built

A working test bench system that streams live sensor data from an ESP32 microcontroller into LabVIEW over USB serial, processes it in real time, 
validates it against configurable limits, and logs everything to a CSV file.

## What I learned

- **Data acquisition** : reading serial CSV data from ESP32 using VISA in LabVIEW, parsing it into separate channels
- **Real-time processing** : Timed Loop at 100ms, moving average filter using Mean PtByPt, rolling statistics buffer
- **Test validation** : configurable hi/lo limits per channel, Boolean pass/fail logic, LED indicators on the front panel
- **Data logging** : timestamped CSV export using Write Delimited Spreadsheet, append mode so every reading is captured
- **SubVIs** : built a reusable statistics SubVI that computes min, max, mean, and standard deviation from an array

## Tools and hardware

- LabVIEW 2025 Q3 Community Edition (32-bit)
- Freenove ESP32-WROOM dev board
- Arduino IDE 2.x for firmware
- Channels: capacitive touch pin, simulated hall sensor, ADC millivolts

## Project structure

labview-esp32-testbench/
- firmware/
  - esp32_testbench.ino
- labview/
  - Day1_SineWave.vi
  - Day2_SerialRead.vi
  - Day3_RealTimeLoop.vi
  - Day4_Statistics.vi
  - Stats_SubVI.vi
  - Day5_Validation.vi
  - Day6_Logging.vi
  - Day7_Dashboard.vi























