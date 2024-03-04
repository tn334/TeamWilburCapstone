//Make sure that when uploading this code the board (Arduino nano 33iot) and port match what you are using.

#include <Servo.h>
#include <ArduinoBLE.h>

//Servo Declarations

Servo C1M;
Servo C2M;
Servo C3M;

//Service definations for bluetooth

#define BLE_UUID_TEST_SERVICE               "9A48ECBA-2E92-082F-C079-9E75AAE428B1"
#define BLE_UUID_FILE_NAME                  "2D2F88C4-F244-5A80-21F1-EE0224E80658"

String valveName = "";

//Switch Pin Declarations

const int C1Switch = 2;
const int C2Switch = 3;
const int C3Switch = 4;

//Servo Control pin declarations--these are PWM pins on the arduino

const int C1Mpin = 9; //brown orange red servo cable
const int C2Mpin = 6; //blue yellow green servo cable
const int C3Mpin = 5; //purple gray white servo cable

//Linear Actuator control pins these are not PWM but function as they should turning the motor on or off. 
//If you wanted PWM control that would allow you to change the speed of the linear actuator (but only slower)

const int LinExtendPin = 7;
const int LinRetractPin = 8;

//Sensor Pin declarations

const int linPosSwitch = A7;
const int LinPosSensor = A6;
const int PressTransducer = A5;

//Variable values for switches indexes and sensor values

int C1State = 0; //these variables store the reading from the toggle switches on the remote
int C2State = 0;
int C3State = 0;
int LinSwitchState = 0; //this stores the reading from the rotary switch on the remote
int meanCurrentPos = 0; //this stores the average value of the last X number of readings from the potentiometer
int i = 0; //these are a couple index variables used in the linear potentiometer smoothing
int iA = 0;
const int numRead = 5; //this variable sets the number of readings to store and average. Larger numbers give a smoother output, but it can delay the signal and cause unexpected movements, I found 5 was a good number
int CurrentLinPos[numRead]; //this variable stores the last X number of linear potentiometer values to average. this helps smooth out the signal so the actuator is not jittering around.
int PressTransValue = 0;

//Linear potentiometer set position values. These are set manually and cannot be changed by other variables in the code the range is 0--1023.
//The fully closed position is 0 and the fully open position is 1023.
//You can use the serial monitor to read the pressure transducer and decide what you want the different position levels to be.

const int PressOffPos = 450;
const int PressLowPos = 300;
const int PressMedPos = 150;
const int PressHighPos = 0;

int CommandLinPos = 0;  //stores the selected value of the linear potentiometer based on the position of the rotary switch and the previously set values
int deadband = 10;  //this sets a range of values plus or minus your target to stop the actuator so it doesn't yo-yo around your set position. making it larger makes the actuator
                    //less likely to jitter but also reduces the resolution of pressures you can deliver to the nipple.

BLEService testService( BLE_UUID_TEST_SERVICE );
BLEStringCharacteristic valveNameCharacteristic( BLE_UUID_FILE_NAME, BLERead | BLEWrite, 20 );



// void bluetoothSetup(){
//   Serial.begin(9600);
//   SerialBT.begin("Wilbur");
// }

// void sendData(char sendChar)
// {
//  if (Serial.available()) {
//     Serial.print("Sending: ");
//     Serial.println(sendChar); // Print the byte being sent to the serial monitor
//     SerialBT.write(sendChar); // Send the byte to the built-in Bluetooth module
//   }
// }

// char[] recieveData() //character encoding for each part to change
// {
//   char[2] receivedChar;
//   if (SerialBT.available()) {
//     receivedChar[0] = SerialBT.read(); // Read the incoming byte (type)
//     Serial.print("Received: ");
//     Serial.println(receivedChar); // Print the received byte to the serial monitor
//     receivedChar[1] = SerialBT.read(); // Read the incoming byte (value)
//     Serial.print("Received: ");
//     Serial.println(receivedChar); // Print the received byte to the serial monitor
//   }
//   return receivedChar;
// }

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  //the next three lines set up the switch pins to read the toggle switches
  pinMode(C1Switch,INPUT_PULLUP);
  pinMode(C2Switch,INPUT_PULLUP);
  pinMode(C3Switch,INPUT_PULLUP);

  //the next four lines set up the linear actuator drive pins

  pinMode(LinExtendPin, OUTPUT);
  digitalWrite(LinExtendPin, LOW);
  pinMode(LinRetractPin, OUTPUT);
  digitalWrite(LinRetractPin, LOW);

  //the next three lines attach the motor pins to their servo objects

  C1M.attach(C1Mpin);
  C2M.attach(C2Mpin);
  C3M.attach(C3Mpin);

  //the next three lines set all motors to 45 degrees

  C1M.write(45);
  C2M.write(45);
  C3M.write(45);

  //this loop pre-reads the linear potentiometer so the actuator can start using the average position right away

  for(i=0;i<numRead;i++){
    CurrentLinPos[i] = analogRead(LinPosSensor);
    delay(5);
  }



  //begin doing bluetooth operations
  BLE.begin();
  
  // set advertised local name and service UUID:
  BLE.setDeviceName( "Arduino Nano 33 BLE" );
  BLE.setLocalName( "Arduino Nano 33 BLE" );
  BLE.setAdvertisedService( testService );

  // BLE add characteristics
  testService.addCharacteristic( valveNameCharacteristic );

  // add service
  BLE.addService( testService );

  // set the initial value for the characeristic:
  valveNameCharacteristic.writeValue( valveName );

  // start advertising
  BLE.advertise();


}

void loop() {


  BLEDevice central = BLE.central();

  if ( central )
  {
    Serial.print( "Connected to central: " );
    Serial.println( central.address() );

    while ( central.connected() )
    {
      if ( valveNameCharacteristic.written() )
      {
        valveName = valveNameCharacteristic.value();
        Serial.print( "New Value recieved: " );
        Serial.println( valveName );
        
      }
    }

    Serial.print( F( "Disconnected from central: " ) );
    Serial.println( central.address() );
  }


  // these 3 lines read the positions of the toggle switches and save their current values
  C1State = digitalRead(C1Switch);
  C2State = digitalRead(C2Switch);
  C3State = digitalRead(C3Switch);


  //these next three if-else statements set the position of the servo based on the switch state
  if(C1State == 0){
    C1M.write(1);
  }
  else{
    C1M.write(60);
  }

  if(C2State == 0){
    C2M.write(1);
  }
  else{
    C2M.write(60);
  }

  if(C3State == 0){
    C3M.write(1);
  }
  else if(C3State == 1){
    C3M.write(60);
  }

  LinSwitchState = analogRead(linPosSwitch); //reads the position of the rotary switch on the remote

  PressTransValue = analogRead(PressTransducer); //reads the value of the pressure transducer

  //the following if/elseif/else statment converts the position of the rotary switch to one of the four pressure states based on the values you selected
  if(LinSwitchState<220){
    CommandLinPos = PressOffPos;
  }
  else if(LinSwitchState>220 && LinSwitchState<440){
    CommandLinPos = PressLowPos;
  }
  else if (LinSwitchState>440 && LinSwitchState<880){
    CommandLinPos = PressMedPos;
  }
  else{
    CommandLinPos = PressHighPos;
  }

  //the indexing variable i allows us to count interations across loops but needs to be reset to zero when it exceeds the number of readings
  if(i==numRead){
    i=0;
  }
  CurrentLinPos[i] = analogRead(LinPosSensor); //this line reads and stores the current linear position variable in the array that will be averaged
  i++; //increases the value of i

  meanCurrentPos = 0; //resets the value of the mean every loop
  for(iA=0;iA<numRead;iA++){
    meanCurrentPos = meanCurrentPos+CurrentLinPos[iA]; //sums all the values currently in the linear position storage array
  }

  meanCurrentPos = meanCurrentPos/numRead; //calculates the mean of the linear position storage array this is what smooths out the linear position values and helps prevent the linear actuator from jittering

  //these if/elseif/else statements set the state of the linear actuator drive pins to be extending or retracting, based on the linear actuators onboard position sensor value
  //it includes the deadband value to help the linear actuator hold a given position
  
  if((meanCurrentPos <= CommandLinPos+deadband) && (meanCurrentPos >= CommandLinPos-deadband)){
    digitalWrite(LinExtendPin, LOW);
    digitalWrite(LinRetractPin, LOW);
  }
  else if(meanCurrentPos > CommandLinPos+deadband){
    digitalWrite(LinExtendPin, LOW);
    digitalWrite(LinRetractPin, HIGH);
  }
  else if(meanCurrentPos < CommandLinPos-deadband){
    digitalWrite(LinExtendPin, HIGH);
    digitalWrite(LinRetractPin, LOW);
  }


//These lines when commented or uncommented will have the code print various values to the serial monitor for you to review and verify that everything is working correctly
  // Serial.print("Channel 1 State : ");
  // Serial.print(C1State);
  // Serial.print("  Channel 2 State : ");
  // Serial.print(C2State);
  // Serial.print("  Channel 3 State : ");
  // Serial.println(C3State);
  // Serial.print("  SyringePumpState : ");
  // Serial.print(CommandLinPos);
  Serial.print("  LinearActuatorPosition : ");
  Serial.print(meanCurrentPos);  
  Serial.print("  Transducer value : ");
  Serial.println(PressTransValue);
  Serial.println();
  // for(int j=0;j<numRead;j++){
  //   Serial.print(CurrentLinPos[j]);
  //   Serial.print(" , ");
  // }
  Serial.println();
  delay(25);

}
