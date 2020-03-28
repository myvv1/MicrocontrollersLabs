//Lab 3, Using ADC inputs to set GPIO outputs
//Geoffrey Nielsen, March 11th 2020

#include "address_map_arm.h"

//Register mapping
volatile int * LED_ptr    = (int *)LED_BASE;
volatile int * Switch_ptr = (int *)SW_BASE;//address for switch
volatile int * GPIO_ptr   = (int *)JP1_BASE;//address for gpios
volatile int * Chan0      = (int *)ADC_BASE;
volatile int * Chan1      = ((int*)ADC_BASE)+1;
//Global variables etc.
volatile int PotValue = 0;
volatile int Value = 0;

//Function Prototype
int ADC_Read(int selection);//function to read ADC inputs and return a value
int Switch_Read(void);      //function to read position of switch


int main(void){
  //configure
  *(GPIO_ptr + 1) = 0x3FF; //set pins 0-9 to out puts

  while(1){
    //read switch and ADC
    Value = ADC_Read(Switch_Read());

    //Output to 10 GPIO pins
    /*
    if      (Value <= 372)  {*(GPIO_ptr) = 0x0;}
    else if (Value <= 744)  {*(GPIO_ptr) = 0x1;}
    else if (Value <= 1116) {*(GPIO_ptr) = 0x3;}
    else if (Value <= 1488) {*(GPIO_ptr) = 0x7;}
    else if (Value <= 1860) {*(GPIO_ptr) = 0xF;}
    else if (Value <= 2231) {*(GPIO_ptr) = 0x1F;}
    else if (Value <= 2602) {*(GPIO_ptr) = 0x3F;}
    else if (Value <= 2973) {*(GPIO_ptr) = 0x7F;}
    else if (Value <= 3344) {*(GPIO_ptr) = 0xFF;}
    else if (Value <= 3715) {*(GPIO_ptr) = 0x1FF;}
    else                    {*(GPIO_ptr) = 0x3FF;}
    */
  }
}

int ADC_Read(int selection){
  *(Chan0)|=0x1; //upade ADC
  if (selection == 1){ //Use pot 0
    *(LED_ptr) |= 0x1;
    PotValue = *(Chan0);
    return PotValue;
  }
  else { //use pot 1
    PotValue = *(Chan1);
    *(LED_ptr) &= ~0x1;
    return PotValue;
  }
}
//function to read position of switch
int Switch_Read(void){
  return * Switch_ptr&0x01; //return the value of the first switch
}
