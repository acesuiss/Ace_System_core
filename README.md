# Automated Electricity Consumption Analysis System with IoT features using Timers

## ABSTRACT :
			
 In this Modern World, Electricity is an essential source of energy in daily life. Different smart energy meters were already invented to check the electricity consumption, and they have been deployed all across the globe for many years. Further substantial and sustained growth is expected as utility companies seek more accurate, granular, and timely data to operate their businesses more efficiently.  By definition, a smart energy meter must be connected so it can transmit data and therefore connectivity is a mission-critical requirement. With a wide range of options available, the connectivity decision is increasingly based on the cost, security, coverage, power usage, and the potential throughput of the connectivity. Each of these can cause deployments to either succeed or fail and therefore must be carefully balanced against each other to create an optimal solution.
There is a need for a device or a system which is capable of Analyzing each device with a minimal amount of Hardware installation in existing buildings .this project is Focused to Implement a system that is capable of Analyzing each device of a home or a commercial building with live feedback, and bill generation .Entire process is designed by calculating the run time of each device. The Total power consumed and their monthly bill  will be calculated and  Displayed  on through the web dashboard or a mobile application. 
This system will create a great impact in the places where electricity bills play a vital role. By knowing the consumption history and by analysis a huge amount of electricity can be saved .Not only the huge consumption , also the minor consumption can be spotted out . 

## LITERATURE SURVEY :

The Focused scenario and the solution of this project is in the form of  innovation.Since,the Stream and the domain of this project is not so popular.the literature Survey has been through modern online platforms like Youtube (YT), websites (Web),Coursera,Kindle etc,..
 
### Firmware Development :
  VScode,
  Arduino IDE 
  Platform IO
  Microsoft and Arduino Forms 

### IoT Integration :
  
    Blynk IOT & Blynk Edgent
    IFTTT
    MQTT 

### Hardware and PCB :
  
    Altium Designer(OR any)
    Relay Module Circuits
    Power Supply Circuits
    Coursera ,Web,YT
  
### Calculation And Documentation :
  
    Power,units AND 
    EB slab Rate Calculations
    ISO,IEEE Standards & Publications &
    Tamil Nadu Electricity Corp

## SYSTEM MODEL DESCRIPTION:

The Architure of this Analysis system uses a wide range of peripherals and few third party Services. It is  complicated to construct  a working model from zero to cent percentage. This system also consists of both hardware and software as a part .For quick understanding And Robust purpose the overall workflow of this system is splitted into three major Segments. Each of the Segments will deal with their respective task to make the workflow crisp and clear .The segments are listed below 
     
     Sensing 
     Analysing 
     Broadcasting


 Each segment will be executed for every second to fulfill the pinpointed workflow of the Analysis System.

## Sensing :

This is where all the Hardware will be  placed to Detect the toggling of  On & Off state of the Devices.Here,the Relay is used to control the device indirectly through the Microcontroller by sending a DC Voltage . all the necessary hardware components that are needed to the process of Sensing will be designed in Printed Circuit Board under the Sensing segment.Mainly 5v Relays,Micro controller,connectors,ac to dc Convertors , connector for the DC switches are the components .To make the system  matured, a lithium ion battery and a battery management system is included .
## Analysing : 
About the Analysing segment, all the calculations required for the system to calculate the power consumption of each  device would be handled by this segment .All the Software components. The On / State of each Device is noted and based on that the  State of the relay will be changed by this segment . If the switch is in ON state, the Esp32 will activate the relay and the relay will switch on the respective Devices and vice versa for off state. Here the device is indirectly connected to the switch by the esp32 and the run timing would be noted.All the power calculation and Device power specification will be present in this segment.
## Broadcasting : 
All the IoT and Dashboard Features will be handled under the Broadcast part . The main highlight of the system design is the system IoT enabled , the system is capable of connections with  Virtual Assistant controlled APIs , live feedback of the devices etc . All the features are implemented through Blynk IoT.

To be Remembered, All the above segments will be executed for every second in a loop  to fulfill the pinpointed workflow of the Analysis System.
