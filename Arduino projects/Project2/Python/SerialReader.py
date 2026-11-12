import serial
import time
from pynput.keyboard import Key, Controller
ser = serial.Serial('COM10', 9600)  

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        for char in line:
            keyboard = Controller()
            keyboard.press(char)
            keyboard.release(char)

    time.sleep(0.1)
