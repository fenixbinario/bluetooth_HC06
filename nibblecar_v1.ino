#include <SoftwareSerial.h>

SoftwareSerial BT(9, 3); 
// creates a "virtual" serial port/UART
// connect BT module TX to D9
// connect BT module RX to D3
// connect BT Vcc to 5V, GND to GND

void setup()  
{
  // set digital pin to control as an output
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);

  // set the data rate for the SoftwareSerial port
  BT.begin(9600);

  // Send test message to other device
  BT.println("Hello from Arduino");
}

char a; // stores incoming character from other device

void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  {
    a=(BT.read());
    if (a=='1')
    {
      digitalWrite(13, HIGH);
      BT.println("LED on");
    }
    if (a=='2')
    {
      digitalWrite(13, LOW);
      BT.println("LED off");
    }
    if (a=='3')
    {
      digitalWrite(5, HIGH);
      BT.println("LED off");
    }
    if (a=='4')
    {
      digitalWrite(5, LOW);
      BT.println("LED off");
    }
    if (a=='?')
    {
      BT.println("Send '1' to turn LED on");
      BT.println("Send '2' to turn LED on");
    }   
    // you can add more "if" statements with other characters to add more commands
  }
}
