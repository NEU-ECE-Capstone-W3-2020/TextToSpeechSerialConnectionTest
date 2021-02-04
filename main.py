import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.flush()

    while True:
        inputToSpeak = input("Enter the text to speak\n")
        print("Sending to Arduino...")
        ser.write(bytes(inputToSpeak, 'utf-8'))
