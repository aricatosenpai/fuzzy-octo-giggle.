//This is a functions to check if the given number
// is prime or not
// 0 --> prime , 1 --> not a prime

#include <iostream>
#include <cmath>
#include "EvOd.h"

int PrimesNum(int number)
{
	if(EvOd(number) == 0)
	{
		if( number == 2 )
			return 0;
		else
			return 1;
	}
	else
	{
		if(number == 1)
			return 1;
		for (int i = 3; i <= int(sqrt(double(number))) ; ++i)
		{
			if(number%i == 0)
				return 1;
		}
		return 0;
	}
}