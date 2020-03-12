//Lab 3, Using ADC inputs
//Geoffrey Nielsen March 11th

#include "address_map_arm.h"

//Global variables etc.
volatile int * Switch_ptr = (int *)SW_BASE;//address for switch
volatile int * GPIO_ptr = (int *)JP1_BASE;//address for gpio
volatile int * ADC_ptr = (int *)ADC_BASE;
volatile int PotValue = 0;

void Configure(void){
  *(GPIO_ptr + 0x4) = 0; //set 0-9 pins to 0 (inputs)

}

//function to read ADC inputs and return a value
int ADC_Read(int selection){
  if (selection == 1){ //Use pot 0
    //Read ADC
    return PotValue;
  }
  else if (selection == 0){ //use pot 1

  }
  else{ //error

  }
}
//function to read position of switch
int Switch_Read(void){

}
//function to turn on LEDs
void LED_Display(int value){

}

int main(void){
  Configure();
  while(1){
    //Pass switch position to ADC, Pass ADC value to LED, Drive LEDs
    LED_Display(ADC_Read(Switch_Read()));
  }


}
