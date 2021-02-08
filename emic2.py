import serial

class Emic2:
    def __init__(self):
        """ Create a new serial connection to emic2 through Arduino"""
        self.ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
        self.ser.flush()

    def sendText(self, message: str) -> bool:
        try:
            self.ser.write(bytes(message, 'utf-8'))
            return True
        except serial.SerialTimeoutException:
            return False



