/*
* Anmol Arora: aa2640
* Raunak Negi: rn444
* Machine used: ILab2
WRONGGGGGGGG
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_TOP_BITS 4 //top bits to extract
#define BITMAP_SIZE 4 //size of the bitmap array
#define SET_BIT_INDEX 17 //bit index to set 
#define GET_BIT_INDEX 17 //bit index to read

static unsigned int myaddress = 4026544704;   // Binary  would be 11110000000000000011001001000000

/* 
 * Function 1: EXTRACTING OUTER (TOP-ORDER) BITS
 */
static unsigned int get_top_bits(unsigned int value,  int num_bits)
{
	//Implement your code here
    unsigned int rev=0;

    //reversing the bits 
    while(value>0){
        rev<<=1;
        
        if(value & 1==1){
            rev^=1;
        }

        value>>=1;
    }

    unsigned int ans=0;

    //extracting the num_bits
    while(num_bits>0){
        ans<<=1;

        if(rev & 1==1){
            ans^=1;
        }

        rev>>=1;

        num_bits--;
    }
	return ans;
}


/* 
 * Function 2: SETTING A BIT AT AN INDEX 
 * Function to set a bit at "index" bitmap
 */
static void set_bit_at_index(char *bitmap, int index)
{
    unsigned int bitmapPos=index/8;
    unsigned int maskPos=index%8;

    unsigned int setBit=1<<maskPos;
    bitmap[bitmapPos]=bitmap[bitmapPos] | setBit;
    
}


/* 
 * Function 3: GETTING A BIT AT AN INDEX 
 * Function to get a bit at "index"
 */
static int get_bit_at_index(char *bitmap, int index)
{
    //Get to the location in the character bitmap array
    //Implement your code here

    unsigned int bitmapPos=index/8;
    unsigned int maskPos=index%8;

    unsigned int readBit=bitmap[bitmapPos]<<(8-maskPos);
    return (int)get_top_bits(readBit,1);
}


int main () {

    /* 
     * Function 1: Finding value of top order (outer) bits Now let’s say we
     * need to extract just the top (outer) 4 bits (1111), which is decimal 15  
    */
    // unsigned int outer_bits_value = get_top_bits (myaddress , NUM_TOP_BITS);
    // printf("Function 1: Outer bits value %u \n", outer_bits_value); 
    // printf("\n");

    /* 
     * Function 2 and 3: Checking if a bit is set or not
     */
    char *bitmap = (char *)malloc(BITMAP_SIZE);  //We can store 32 bits (4*8-bit per character)
    memset(bitmap,1, BITMAP_SIZE); //clear everything
    
    /* 
     * Let's try to set the bit 
     */
    set_bit_at_index(bitmap, SET_BIT_INDEX);
    
    /* 
     * Let's try to read bit)
     */
    printf("Function 3: The value at %dth location %d\n", 
            GET_BIT_INDEX, get_bit_at_index(bitmap, GET_BIT_INDEX));
            
    return 0;
}
