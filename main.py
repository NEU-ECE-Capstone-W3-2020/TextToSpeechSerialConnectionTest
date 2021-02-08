from emic2 import Emic2

if __name__ == '__main__':
    # first make an emic2 instace
    emic = Emic2()
    # begin input loop
    while True:
        inputToSpeak = str(input("Enter the text to speak\n"))
        print("Sending to Arduino...")
        emic.sendText(inputToSpeak)
