//GN
//8 switches simulate 8-bit ADC Value for a "baramoter sensor"
//4 buttons for thrrotle, pitch, yaw, roll
//4 PWM outputs using timer interrupts

#include "address_map_arm.h"
volatile int * LED_ptr    = (int *)LED_BASE;    //address for on board LEDs
volatile int * Switch_ptr = (int *)SW_BASE;     //address for switch
volatile int * GPIO_ptr   = (int *)JP1_BASE;    //address for gpios
volatile int * Btn_ptr    = (int *)KEY_BASE;    //address for buttons
volatile int * interval_timer_ptr = (int *)TIMER_BASE;
volatile int ADC_Barometer;
volatile int Thrust;
volatile int Pitch;
volatile int Roll;
volatile int Yaw;


//Functions
int Switch_Read(void); //Return value from 8 switches
int Button_Read(void); //Return value from buttons
int PWM(void);         //Create PWM signals duity cycle
int Timer(void);       //run timer interrupt
void TimerConfig();    //Set up timer
void LED_Test(int value);

int main(void){
  TimerConfig();

  while(1){
    //Sensor inputs
    ADC_Barometer = Switch_Read(); //Return ADC value for altitude
    Button_Read();
    //Control
    //Outputs
  }
}

void LED_Test(int value){
  if(value == 0x1){
    *(LED_ptr) |= 0x1;
  }
  else if(value == 0x2){
    *(LED_ptr) |= 0x2;
  }
  else if(value == 0x4){
    *(LED_ptr) |= 0x4;
  }
  else if(value == 0x8){
    *(LED_ptr) |= 0x8;
  }
  else{
    *(LED_ptr) &= ~0xF;
  }
}

int Switch_Read(void){
  return * Switch_ptr&0xFF; //return value of switch 0-7
}

int Button_Read(void){
  return *(Btn_ptr) &= 0xF; //return value of buttons 0-3
}

void TimerConfig(){
  int counter = 1000000; // 1/(100 MHz) x 1x10^6 = 10 msec
  *(interval_timer_ptr + 0x2) = (counter & 0xFFFF);
  *(interval_timer_ptr + 0x3) = (counter >> 16) & 0xFFFF;
  /* start interval timer, enable its interrupts */
  *(interval_timer_ptr + 1) = 0x3; // STOP = 0, START = 0, CONT = 1, ITO = 1
}

int Timer(){
  if ((* interval_timer_ptr & 0x01) == 0x01){
    * interval_timer_ptr = 0x0;
  }
  return 0x1;
}
