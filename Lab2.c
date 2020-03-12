//Lab 2, create a stopwatch
//Geoffrey Nielsen Feb 19th 2020

//global variables
volatile int * Hex_ptr1 = (int *)HEX3_HEX0_BASE; //lower order 7-seg display address
volatile int * Hex_ptr2 = (int *)HEX5_HEX0_BASE; //Higher order 7-seg display address
volatile int * BT_ptr = (int *)KEY_BASE; //address for buttons
volatile int * SW_ptr = (int *)SW_BASE;//address for switch
volatile int * Time_ptr = (int *)TIMER_BASE;//address for timer

//function to set the 7-seg display outputs
void DisplayHex(int value){

  *(Hex_ptr1) = value
  *(Hex_ptr2) = value
}

//function to read the button states
int ReadButtons(void){

  reture BT_ptr
}

//function to read switch state
int ReadSwitches(void){
  int *sw;
	int p;
	sw = (int*)SW_BASE; //point to address of switch inputs
	p = *sw;
	return p&0xF; //return the value of the 4 switches
  return SW_ptr
}

//function to
int Timer(void){


}

int main(void){

  while(1){

    int BW_State = ReadButtons();//Read button states
    int SW_Pos = ReadSwitches();//Read switch posisiton

    //display either current or lap time
    if (SW_Pos = 0x01){

    }
    else{

    }

    //if cleared (button state 0001)
    if((BW_State = 0x01) = 0x01){

    }
    //if started (button state 0010)
    else if((BW_State = 0x01) = 0x02){


    }
    //if stopped (button state 0100)
    else if((BW_State = 0x01) = 0x04){

    }

    //record lab (button state 1000)
    else if((BW_State = 0x01) = 0x08){

    }

  }
}
