//Lab 3, Using ADC inputs
//Geoffrey Nielsen March 11th

#include "address_map_arm.h"

//Global variables etc.
volatile int * Switch_ptr = (int *)SW_BASE;//address for switch
volatile int * GPIO_ptr   = (int *)JP1_BASE;//address for gpios
volatile int * ADC_ptr    = (int *)ADC_BASE;//address for ADC inputs

volatile int PotValue = 0;
volatile float Value = 0.0;
const int in_min  = 0;    //min ADC value
const int in_max  = 4096; //max 12-bit ADC values
const int out_min = 0;    //min number of LEDs
const float out_max = 10.0;   //max number of LEDs

//Functions


//function to read ADC inputs and return a value
int ADC_Read(int selection){
  if (selection == 1){ //Use pot 0
    *(ADC_ptr) = 0x00;
    PotValue = * (ADC_ptr);
    return PotValue;
  }
  //change to output ADC 2
  else if (selection == 0){ //use pot 1
    *(ADC_ptr+1) = 0x00;
    PotValue = * (ADC_ptr+1);
    return PotValue;
  }
}
//function to read position of switch
int Switch_Read(void){
  int *sw;
  int p;
  sw = (int*)SW_BASE; //point to address of switch inputs
  p = *sw;
  return p&0x01; //return the value of the first switch
}

float Map(int x){
  return (x-in_min)*(out_max-out_min)/(in_max-in_min)+out_min;
}

int main(void){
  //configure
  *(GPIO_ptr + 1) = 0x3FF; //set pins 0-9 to outputs

  while(1){
    //Pass switch position to ADC, Pass ADC value to LED, Drive LEDs

    Value = Map(ADC_Read(Switch_Read()));
    if      (Value <= 1.0) {*(GPIO_ptr) = 0x1;}
    else if (Value <= 2.0) {*(GPIO_ptr) = 0x3;}
    else if (Value <= 3.0) {*(GPIO_ptr) = 0x7;}
    else if (Value <= 4.0) {*(GPIO_ptr) = 0xF;}
    else if (Value <= 5.0) {*(GPIO_ptr) = 0x1F;}
    else if (Value <= 6.0) {*(GPIO_ptr) = 0x3F;}
    else if (Value <= 7.0) {*(GPIO_ptr) = 0x7F;}
    else if (Value <= 8.0) {*(GPIO_ptr) = 0xFF;}
    else if (Value <= 9.0) {*(GPIO_ptr) = 0x1FF;}
    else                 {*(GPIO_ptr) = 0x3FF;}
  }


}
