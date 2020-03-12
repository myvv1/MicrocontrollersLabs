#include "address_map_arm.h"
/* Your first program*/

volatile int DELAY_LENGTH;
volatile int *SW_ptr=(int*)SW_BASE; //Switch address
volatile int *HEX_ptr=(int*)HEX3_HEX0_BASE; //7-bit display address

void DisplayHex(int value){
	unsigned char LookUpTable[15]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
	*(HEX_ptr)=LookUpTable[value]; //select the point in the lookup table "value" from the switches
}

int ReadSwitches(void){
	int *sw;
	int p;
	sw = (int*)SW_BASE; //point to address of switch inputs
	p = *sw; 
	return p&0xF; //return the value of the 4 switches
}
	
int main(void){

	volatile int delay_count;
	volatile int status;

	//Flashing freq and initial state
	DELAY_LENGTH=700000;
	status=0;
	
	//loop to keep running main code 
	while(1){
		if(status==0){
			status=1;
			DisplayHex(ReadSwitches()); //call display function by value
		}
		else{
			status=0;
			DisplayHex(17);
		}
		for (delay_count = DELAY_LENGTH; delay_count != 0; --delay_count);
		}
}