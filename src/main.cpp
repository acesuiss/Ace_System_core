#include <Arduino.h>
#include <stdio.h>
/*******************************************************************************************
*                                                                                         *
              Project Title : Automated Billing , Base Code
              Date          : 13 Aug 2022                                                 *
              Author        : last edited by Sudharsan,27 NOV
              Board         : Esp8266
              Essentials    : Blynk_iot Accouct And blynk Libriaries
*                                                                                         *
*******************************************************************************************

*********** defining Required blynk iot Libraries ********** */


#define BLYNK_TEMPLATE_ID "TMPLB9mvZmsn"
#define BLYNK_TEMPLATE_NAME "Testing ACE esp8266 Mark7"
#define BLYNK_FIRMWARE_VERSION "0.1.1.3"                 // frimware version
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
#define APP_DEBUG
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"


/* ********** Defining the Required pins ********** */

#define Device1  16   //d0
#define Device2  5    //d1
#define Device3  4    //d2
#define Device4  0    //d3

#define switch1 2    //d4
#define switch2 14   //d5
#define switch3 12   //d6
#define switch4 15   //d7


/* ********** Function Prototype ********** */

void Collecte_Device_Timing (struct Device_Data * device);

void sense_the_Switch();
void Analyse_Each_Devices();
void calculate(struct Device_Data * str);
void Broadcast_the_Data();


/*const int slab_1[4]=[100,100,200,100];
const int rate_1[4]=[0,2.25,4.5,6];
const int slab_2[4]=[100,100,200,100];
float rate_2[4]=[0,2.25,4.5,6];*/

/* ********** Structure To Store the Active Time  ********** */
struct Device_Data {
  int sec =       0;
  int minute =     0;
  int hour =      0;
  int total_sec = 0;
  int power = 100;
  int units = 0 ;
  double total_amount = 0;
};

/* ********** Time Data for four devices ********** */

struct Device_Data Device1_Data, Device2_Data, Device3_Data, Device4_Data;


void setup()
{
  Serial.begin(115200);
  delay(100);
  /* ********** Setting the Relays as Outputs ********** */
  pinMode(Device1, OUTPUT);
  pinMode(Device2, OUTPUT);
  pinMode(Device3, OUTPUT);
  pinMode(Device4, OUTPUT);
  /* ********** Setting the Switches as Inputs ********** */
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);
  /* ********** Connecting to IoT Platform ********** */
  BlynkEdgent.begin();
}

void loop() {

  BlynkEdgent.run();
  sense_the_Switch();
  Analyse_Each_Devices();
  Broadcast_the_Data();
  delay(950);

}


/* ********** check function to check each switch and update the relay and the timing  ********** */

void sense_the_Switch() {
  //Serial.println("Entering the check function.  ");

  //Device1
  if (digitalRead(switch1) == HIGH)
  {
    digitalWrite(Device1, LOW);
    Collecte_Device_Timing(&Device1_Data);
  } else digitalWrite(Device1, HIGH);
  //Device2
  if (digitalRead(switch2) == HIGH)
  {
    digitalWrite(Device2, LOW);
    Collecte_Device_Timing(&Device2_Data);
  } else digitalWrite(Device2, HIGH);
  //Device3
  if (digitalRead(switch3) == HIGH)
  {
    digitalWrite(Device3, LOW);
    Collecte_Device_Timing(&Device3_Data);
  } else digitalWrite(Device3, HIGH);
  //Device4
  if (digitalRead(switch4) == HIGH)
  {
    digitalWrite(Device4, LOW);
    Collecte_Device_Timing(&Device4_Data);
  } else digitalWrite(Device1, HIGH);
}

void Analyse_Each_Devices() {
  calculate(&Device1_Data);
  calculate(&Device2_Data);
  calculate(&Device3_Data);
  calculate(&Device4_Data);
}



/* ********** To update the timing of each device in  hours minute sec total sec format for  calculation  ********** */

void Collecte_Device_Timing (struct Device_Data * device)
{
  device->sec++;
  device->total_sec++;
  if (device->sec > 59) {
    device->sec = 0;
    device->minute++;
    if (device->minute > 59) {
      device->minute = 0;
      device->hour++;
    }
  }
}

void calculate(struct Device_Data * str) {
  double timeinhour = str->total_sec / 3600 ;
  str->total_amount = str->power * timeinhour ;
  //unsigned int temp_units = str->units;
}

void Broadcast_the_Data() {

  Blynk.virtualWrite(V10, Device1_Data.units);     // virtual pin datas
  Blynk.virtualWrite(V11, Device2_Data.units);
  Blynk.virtualWrite(V12, Device3_Data.units);
  Blynk.virtualWrite(V13, Device4_Data.units);

  Blynk.virtualWrite(V14, Device1_Data.total_amount);
  Blynk.virtualWrite(V15, Device2_Data.total_amount);
  Blynk.virtualWrite(V16, Device3_Data.total_amount);
  Blynk.virtualWrite(V17, Device4_Data.total_amount);
}
