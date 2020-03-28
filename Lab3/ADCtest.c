//ADC Test

//Lab 3, Using ADC inputs
//Geoffrey Nielsen March 11th

#include "address_map_arm.h"

//Global variables etc.
volatile int * Switch_ptr = (int *)SW_BASE;//address for switch
volatile int * GPIO_ptr   = (int *)JP1_BASE;//address for gpio
volatile int * ADC_ptr    = (int *)ADC_BASE;//address for ADC inputs
volatile int * LED_ptr    = (int *)LED_BASE;//address for on board LEDs
volatile int PotValue = 0;
volatile int Light = 0;

#define in_min  = 0;    //min ADC value
#define in_max  = 4096; //max 12-bit ADC values
#define out_min = 0;    //min number of LEDs
#define out_max = 10;   //max number of LEDs

//Functions



//function to read ADC inputs and return a value
int ADC_Read(){
  *(ADC_ptr) = 0x00;
  PotValue = * ADC_ptr;
  return PotValue;
}
//function to read position of switch


//function to map one range of numbers to antother range


int main(void){

    while (1){

		if (ADC_Read() >= 10){
			*(LED_ptr) = 0x1;
		}
    if (ADC_Read() >= 150){
      *(LED_ptr) = 0x2;
    }
    if (ADC_Read() >= 250){
      *(LED_ptr) = 0x4;
    }
  }
}
