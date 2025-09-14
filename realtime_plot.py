import serial
import matplotlib.pyplot as plt
import pandas as pd
from collections import deque

# Adjust to your ESP32 COM port
ser = serial.Serial('COM3', 9600)

voltages = deque(maxlen=50)
currents = deque(maxlen=50)
times = deque(maxlen=50)

plt.ion()
fig, ax = plt.subplots()

i = 0
while True:
    line = ser.readline().decode().strip()
    if "Voltage" in line:
        try:
            parts = line.split("|")
            v = float(parts[0].split(":")[1].strip().split()[0])
            c = float(parts[1].split(":")[1].strip().split()[0])

            voltages.append(v)
            currents.append(c)
            times.append(i)
            i += 1

            ax.clear()
            ax.plot(times, voltages, label="Voltage (V)")
            ax.plot(times, currents, label="Current (A)")
            ax.legend()
            ax.set_xlabel("Time (s)")
            ax.set_ylabel("Measurements")
            ax.set_title("Real-time Smart Grid Fault Monitoring")
            plt.pause(0.1)
        except:
            pass
