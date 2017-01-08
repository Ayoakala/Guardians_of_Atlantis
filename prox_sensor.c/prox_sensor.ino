#include <SoftwareSerial.h>// import the serial library bluetooth cmmunication

SoftwareSerial deca(10, 11); // RX, TX  (RX of Arduino attaches to TX of Bluetooth module, TX of Arduino attaches to RX of Bluetooth)

int BluetoothData; // the data given from Computer
int ledpin = 9; 

// Ultrasonic Sensor
int trigPin = 5;    //Trig - green Jumper
int echoPin = 12;    //Echo - yellow Jumper
int ledPin  = 2;
int ledPinII = 3;
long duration, cm, inches;
int BluetoothDataInt = 0;

void setup() {
  // put your setup code here, to run once:
  deca.begin(9600);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledPin,OUTPUT);
}

void loop() {
   digitalWrite(trigPin, LOW);
   delayMicroseconds(5);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   cm = (duration/2) / 29.1;
   
  if (deca.available()){
   BluetoothData = deca.read();
   //BluetoothData = BluetoothData.toInt();
     if((BluetoothData == -1) || (BluetoothData > 15)){
        BluetoothDataInt = 15;
     }else{
        BluetoothDataInt = BluetoothData;
     }
   }
   
   if (cm <= BluetoothDataInt){
    digitalWrite(ledPin, HIGH);
    Serial.println("trigger"); 
   }
   else
   {
   digitalWrite(ledPin, LOW);
   }

   
   
//   if (deca.available()){
//      BluetoothData=deca.read();
//        if(BluetoothData=='1' || BluetoothData == '2'){  
//           digitalWrite(ledpin,HIGH); // led turns on 
//           Serial.println("LED ON ! "); // message sent to the serial monitor
//           }
//        if(BluetoothData=='0'){
//          digitalWrite(ledpin,0);
//           Serial.println("LED Off ! "); // message sent to the serial monitor
//           
//           }
//
//    }

delay(100);// prepare for next data ...

}
