// include the SoftwareSerial library so we can use it to talk to the Emic 2 module
#include <SoftwareSerial.h>

#define rxPin   10  // Serial input (connects to Emic 2's SOUT pin)
#define txPin   11  // Serial output (connects to Emic 2's SIN pin)
#define ledPin  13  // Most Arduino boards have an on-board LED on this pin

// set up a new serial port
SoftwareSerial emicSerial =  SoftwareSerial(rxPin, txPin);

void setup() {

  // -- SETTING UP EMIC2
  // define pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  
  // set the data rate for the SoftwareSerial port
  emicSerial.begin(9600);

  digitalWrite(ledPin, LOW);  // turn LED off
  
  /*
    When the Emic 2 powers on, it takes about 3 seconds for it to successfully
    initialize. It then sends a ":" character to indicate it's ready to accept
    commands. If the Emic 2 is already initialized, a CR will also cause it
    to send a ":"
  */
  emicSerial.print('\n');             // Send a CR in case the system is already up
  while (emicSerial.read() != ':');   // When the Emic 2 has initialized and is ready, it will send a single ':' character, so wait here until we receive it
  delay(10);                          // Short delay
  emicSerial.flush();                 // Flush the receive buffer

  // -- SETTING UP SERIAL CONNECTION TO PI
  Serial.begin(9600);
}
void loop() {

  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');

    emicSerial.print('S');
    emicSerial.print(data);
    emicSerial.print('\n');
    digitalWrite(ledPin, HIGH);         // Turn on LED while Emic is outputting audio
    while (emicSerial.read() != ':');   // Wait here until the Emic 2 responds with a ":" indicating it's ready to accept the next command
    digitalWrite(ledPin, LOW);
      
    delay(500);    // 1/2 second delay
    
  }

  
  
}