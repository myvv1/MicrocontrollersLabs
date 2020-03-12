#include "address_map_arm.h"
/* Your first program*/
volatile int DELAY_LENGTH; // volatile so it survives compilation
volatile int LookUpTable[9] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}

void DisplayHex(int value){
	volatile int * Hex_ptr = (int *)HEX3_HEX0_BASE; //lower order 7-seg display address
	*(Hex_ptr) = value
}

int ReadSwitches(void){
	volatile int * SW_ptr = (int *)SW_BASE; //Switch address
	return SW_ptr
}
//Blinks the lowest 7-seg display	
int main(void) {
	
	volatile int delay_count; // volatile so the C compiler doesn't remove the loop
	volatile int status;
	
	//Set blinking freq and initial state
	DELAY_LENGTH = 700000;
	status = 0;
	
	//Loop that blinks the 7-Seg display
	while(1){
			
		if (status == 0) //show 4-bit number
		{
			status = 1;
			int SW_Pos = ReadSwitches(); //set an int to the return
			DisplayHex(SW_Pos);			 //call by value
			//*(LED_ptr) |= 0x1;
		}
		else			//turn off
		{
			status = 0; 
			//*(LED_ptr) &= ~0x01; //AND bits to turn off
		}

        for (delay_count = DELAY_LENGTH; delay_count != 0; --delay_count); // delay loop
	}
	
}