#include <cstdio>
#define uint32		unsigned int
#define uint64		unsigned long long

const uint32 put1by1 = 0x55555555; //binary: 0101...
const uint32 put2by2 = 0x33333333; //binary: 00110011..
const uint32 put4by4 = 0x0F0F0F0F; //binary:  4 zeros,  4 ones ...
const uint32 put1by8 = 0x01010101; //the sum of 256 to the power of 0,1,2,3...

const uint64 put1by1_64 = 0x5555555555555555;	//binary: 0101...
const uint64 put2by2_64 = 0x3333333333333333;	//binary: 00110011..
const uint64 put4by4_64 = 0x0f0f0f0f0f0f0f0f;	//binary:  4 zeros,  4 ones ...
const uint64 put8by8_64 = 0x00ff00ff00ff00ff;	//binary:  8 zeros,  8 ones ...
const uint64 put16by16_64 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
const uint64 put32by32_64 = 0x0000ffff0000ffff; //binary: 32 zeros, 32 ones
const uint64 put1by8_64 = 0x0101010101010101;	//the sum of 256 to the power of 0,1,2,3...

uint32 CountBit32(uint32 rValue)
{
	rValue -= (rValue >> 1) & put1by1;
	rValue = (rValue & put2by2) + ((rValue >> 2) & put2by2);
	rValue = (rValue + (rValue >> 4)) & put4by4;

	return ((rValue * put1by8) >> 24);
}

//This uses fewer arithmetic operations than any other known  
//implementation on machines with fast multiplication.
//This algorithm uses 12 arithmetic operations, one of which is a multiply.
uint32 CountBit64(uint64 rValue)
{
	rValue -= (rValue >> 1) & put1by1_64;							//put count of each 2 bits into those 2 bits
	rValue = (rValue & put2by2_64) + ((rValue >> 2) & put2by2_64);	//put count of each 4 bits into those 4 bits 
	rValue = (rValue + (rValue >> 4)) & put4by4_64;					//put count of each 8 bits into those 8 bits 
	return (rValue * put1by8_64) >> 56;								//returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 
}

int main(void)
{
	uint32 a = 0xFFF50000;

	printf("%d\n", CountBit32(a));

	uint64 b = 0xFF00FF0010101010;

	printf("%d\n", CountBit64(b));

	return 0;
}
