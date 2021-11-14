/*****************************************
*     CMPS12 I2C example for Arduino     *
*        By James Henderson, 2014        * 
*****************************************/

#include <Wire.h>

#define CMPS12_ADDRESS 0x60  // Address of CMPS12 shifted right one bit for arduino wire library
#define ANGLE_8  1           // Register to read 8bit angle from

//Registers for accelerometer data
#define ACC_X_HIGH  0xC
#define ACC_X_LOW   D
#define ACC_Y_HIGH  E
#define ACC_Y_LOW   F
#define ACC_Z_HIGH  10
#define ACC_Z_LOW   11

//Registers for gyroscope data
#define GYR_X_HIGH  12
#define GYR_X_LOW   13
#define GYR_Y_HIGH  14
#define GYR_Y_LOW   15
#define GYR_Z_HIGH  16
#define GYR_Z_LOW   17

unsigned char acc_x_h, acc_x_l, acc_y_h, acc_y_l, acc_z_h, acc_z_l;
//unsigned char gyr_x_h, gyr_x_l, gyr_y_h, gyr_y_l, gyr_z_h, gyr_z_l;
unsigned int acc_y;
unsigned char high_byte, low_byte, angle8;
char pitch, roll;
unsigned int angle16;
int sample_counter = 0;

void setup()
{
  Serial.begin(9600);  // Start serial port
  Wire.begin();
}

void loop()
{

  Wire.beginTransmission(CMPS12_ADDRESS);  //starts communication with CMPS12
  Wire.write(ACC_X_HIGH);                  //Sends the register we wish to start reading from
  Wire.endTransmission();
 
  // Request 5 bytes from the CMPS12
  // this will give us the 8 bit bearing, 
  // both bytes of the 16 bit bearing, pitch and roll
  Wire.requestFrom(CMPS12_ADDRESS, 6);       
  
  while(Wire.available() < 6);        // Wait for all bytes to come back

  acc_x_h = Wire.read();
  acc_x_l = Wire.read(); 
  acc_y_h = Wire.read();
  acc_y_l = Wire.read();
  acc_z_h = Wire.read();
  acc_z_l = Wire.read();

  acc_y = acc_y_l;
    //acc_x = acc_z_l;
  
//  gyr_x_h = Wire.read();
//  gyr_x_l = Wire.read();
//  gyr_y_h = Wire.read();
//  gyr_y_l = Wire.read();
//  gyr_z_h = Wire.read();
//  gyr_z_l = Wire.read();

//  Serial.print(sample_counter);
//  Serial.print("\t");
  //Serial.print("acc_x_h: ");
  Serial.println(acc_y);
//  Serial.print("\t");
  //Serial.print("\t\tacc_x_l: ");
//  Serial.print(acc_x_l);
//  Serial.print("\t");
//  //Serial.print("\t\tacc_y_h: ");
//  Serial.print(acc_y_h);
//  Serial.print("\t");
  //Serial.print("\t\tacc_y_l: ");
//  Serial.println(acc_y_l);
//  Serial.print("\t");
//  //Serial.print("\t\tacc_z_h: ");
//  Serial.print(acc_z_h);
//  Serial.print("\t");
//  //Serial.print("\t\tacc_z_l: ");
//  Serial.println(acc_z_l);
//  Serial.print("\t");

//  //Serial.print("\t\tgyr_x_h: ");
//  Serial.print(gyr_x_h);
//  Serial.print("\t");
//  //Serial.print("\t\tgyr_x_l: ");
//  Serial.print(gyr_x_l);
//  Serial.print("\t");
//  //Serial.print("\t\tgyr_y_h: ");
//  Serial.print(gyr_y_h);
//  Serial.print("\t");
//  //Serial.print("\t\tgyr_y_l: ");
//  Serial.print(gyr_y_l);
//  Serial.print("\t");
//  //Serial.print("\t\tgyr_z_h: ");
//  Serial.print(gyr_z_h);
//  Serial.print("\t");
//  //Serial.print("\t\tgyr_z_l: ");
//  Serial.println(gyr_z_l);
//  Serial.print("\t");

  sample_counter++;
  
  //delay(100);

  //Serial.println(acc_x_l);
  //delay(5);
}
