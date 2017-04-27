#include <string>
//#include "canreceive.cpp"
std::string can_fault_code_fsm(canfd_frame message){
  
std::string fault;
 
if(message.data[0] & 0b00000001)
  fault = "Hardware Gate/Desaturation Fault";
 else if(message.data[0] & 0b00000010)
   fault = "HW Over-current Fault";
 else if(message.data[0] & 0b00000100)
   fault = "Accelerator Shorted";
 else if(message.data[0] & 0b00001000)
   fault = "Accelerator Open";
 else if(message.data[0] & 0b00010000)
   fault = "Current Sensor Low";
 else if(message.data[0] & 0b00100000)
   fault = "Current Sensor High";
 else if(message.data[0] & 0b01000000)
   fault = "Module Tempature Low";
 else if(message.data[0] & 0b10000000)
   fault = "Module Tempature High";

 else if(message.data[1] & 0b00000001)
   fault = "Control PCB Temperature Low";
 else if(message.data[1] & 0b00000010)
     fault = "Control PCB Temperature High";
 else if(message.data[1] & 0b00000100)
     fault = "Gate Drive PCB Tempature Low";
 else if(message.data[1] & 0b00001000)
     fault = "Gate Drive PCB Tempature High";
 else if(message.data[1] & 0b00010000)
   fault = "5V Sense Voltage Low";
 else if(message.data[1] & 0b00100000)
   fault = "5V Sense Voltage High";
 else if(message.data[1] & 0b01000000)
   fault = "12V Sense Voltage Low";
 else if(message.data[1] & 0b10000000)
   fault = "12V Sense Voltage High";

 else if(message.data[2] & 0b00000001)
   fault = "2.5V Sense Voltage Low";
 else if(message.data[2] & 0b00000010)
   fault = "2.5V Sense Voltage High";
 else if(message.data[2] & 0b00000100)
   fault = "1.5V Sense Voltage Low";
 else if(message.data[2] & 0b00001000)
   fault = "1.5V Sense Voltage High";
 else if(message.data[2] & 0b00010000)
   fault = "DC Bus Voltage High";
 else if(message.data[2] & 0b00100000)
   fault = "DC Bus Voltage Low";
 else if(message.data[2] & 0b01000000)
   fault = "Pre-charge Timeout";
 else if(message.data[2] & 0b10000000)
   fault = "Pre-charge Voltage Failure";

 else if(message.data[3] & 0b00000001)
   fault = "EEPROM Checksum Invalid";
 else if(message.data[3] & 0b00000010)
   fault = "EEPROM Data Out of Range";
 else if(message.data[3] & 0b00000100)
   fault = "EEPROM Update Required";
 else if(message.data[3] & 0b00001000)
   fault = "Reserved";
 else if(message.data[3] & 0b00010000)
   fault = "Reserved";
 else if(message.data[3] & 0b00100000)
   fault = "Reserved";
 else if(message.data[3] & 0b01000000)
   fault = "Brake Shorted";
 else if(message.data[3] & 0b10000000)
   fault = "Brake Open";

 else if(message.data[4] & 0b00000001)
   fault = "Motor Over-speed Fault";
 else if(message.data[4] & 0b00000010)
   fault = "Over-current Fault";
 else if(message.data[4] & 0b00000100)
   fault = "Over-voltage Fault";
 else if(message.data[4] & 0b00001000)
   fault = "Inverter Over-temperature Fault";
 else if(message.data[4] & 0b00010000)
   fault = "Accelerator Input Shorted Fault";
 else if(message.data[4] & 0b00100000)
   fault = "Accelerator Input Open Fault";
 else if(message.data[4] & 0b01000000)
   fault = "Direction Command Fault";
 else if(message.data[4] & 0b10000000)
   fault = "Inverter Response Time-out Fault";

 else if(message.data[5] & 0b00000001)
   fault = "Hardware Gate/Desaturation Fault";
 else if(message.data[5] & 0b00000010)
   fault = "Hardware OVer-current Fault";
 else if(message.data[5] & 0b00000100)
   fault = "Under-voltage Fault";
 else if(message.data[5] & 0b00001000)
   fault = "CAN Command Message Lost Fault";
 else if(message.data[5] & 0b00010000)
   fault = "Motor Over-tempature Fault";
 else if(message.data[5] & 0b00100000)
   fault = "Reserved";
 else if(message.data[5] & 0b01000000)
   fault = "Reserved";
 else if(message.data[5] & 0b10000000)
   fault = "Reserved";

 else if(message.data[6] & 0b00000001)
   fault = "Brake Input Shorted Fault";
 else if(message.data[6] & 0b00000010)
   fault = "Brake Input Open Fault";
 else if(message.data[6] & 0b00000100)
   fault = "Module A Over-tempature Fault";
 else if(message.data[6] & 0b00001000)
   fault = "Module B Over-tempature Fault";
 else if(message.data[6] & 0b00010000)
   fault = "Module C Over-tempature Fault";
 else if(message.data[6] & 0b00100000)
   fault = "PCB Over-temperature Fault";
 else if(message.data[6] & 0b01000000)
   fault = "Gate Drive Board 1 Over-temperature Fault";
 else if(message.data[6] & 0b10000000)
   fault = "Gate Drive Board 2 Over-temperature Fault";

 else if(message.data[7] & 0b00000001)
   fault = "Gate Drive Board 3 Over-temperature Fault";
 else if(message.data[7] & 0b00000010)
   fault = "Current Sensor Fault";
 else if(message.data[7] & 0b00000100)
   fault = "Reserved";
 else if(message.data[7] & 0b00001000)
   fault = "Reserved";
 else if(message.data[7] & 0b00010000)
   fault = "Reserved";
 else if(message.data[7] & 0b00100000)
   fault = "Reserved";
 else if(message.data[7] & 0b01000000)
   fault = "Resolver Not Connected";
 else if(message.data[7] & 0b10000000)
  fault = "Inverter Discharge Active";

 else
   fault = "Unrecoreded Fault: check manual";
 return fault;
}
