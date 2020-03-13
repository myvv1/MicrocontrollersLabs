//Lab 3, Using ADC inputs
//Geoffrey Nielsen March 11th

#include "address_map_arm.h"

//Global variables etc.
volatile int * Switch_ptr = (int *)SW_BASE;//address for switch
volatile int * GPIO_ptr   = (int *)JP1_BASE;//address for gpio
volatile int * ADC_ptr    = (int *)ADC_BASE;//address for ADC inputs
volatile int * LED_ptr    = (int *)LED_BASE;//address for on board LEDs
volatile int PotValue = 0;

#define in_min  = 0;    //min ADC value
#define in_max  = 4096; //max 12-bit ADC values
#define out_min = 0;    //min number of LEDs
#define out_max = 10;   //max number of LEDs

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
  int *sw;
  int p;
  sw = (int*)SW_BASE; //point to address of switch inputs
  p = *sw;
  return p&0x01; //return the value of the first switch
}
//function to turn on LEDs
void LED_Display(int value){

  if (value == 1){
    *(LED_ptr) |= 0x1;
  }
}

//function to map one range of numbers to antother range
long Map(long input, long in_min, long in_max, long out_min, long out_max){
  return (input-in_min)*(out_max-out_min)/(in_max-in_min)+out_min;
}

int main(void){
  Configure();
  while(1){
    //Pass switch position to ADC, Pass ADC value to LED, Drive LEDs
    LED_Display(ADC_Read(Switch_Read()));
  }


}
