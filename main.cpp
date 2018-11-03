#include <iostream>
#include <cstdlib>
#include "EvOd.h"
#include "PrimesNum.h"

using namespace std;

int * PrintEvens(int *Array , int arsiz,int sizee)
{
	int *EvenOnes = new int[sizee];
	int currcount=0;
	for (int i = 0; i < arsiz; ++i)
	{
		if(EvOd(Array[i]) == 0)
		{
			EvenOnes[currcount]=Array[i];
			currcount++;
		}
	}
	return EvenOnes;
}
int * PrintOdds(int *Array , int arsiz,int sizee)
{
	int *OddOnes = new int[sizee];
	int currcount=0;
	for (int i = 0; i < arsiz; ++i)
	{
		if(EvOd(Array[i]) == 1)
		{
			OddOnes[currcount]=Array[i];
			currcount++;
		}
	}
	return OddOnes;
}

int main(int argc , char *argv[])
{
	int limit = 0;
	if(argc > 1)
		limit  = atoi(argv[1]);
	else
		cout << "You didnt gimme the limit :(\n";

	int *PrimeArray , *NewPrimeArray, *EvenOnes , *OddOnes;
	int  SizPrimes=0 , SizEvens=0 , SizOdds=0;

	//PrimeArray = new int[limit];
	for (int number = 0; number < limit; ++number)
	{
		// cout << "check";
		if(PrimesNum(number) == 0)
		{
			// cout << "check";
			SizPrimes++;
			NewPrimeArray = new int[SizPrimes];
			for (int j = 0; j < SizPrimes; ++j)
			{
				NewPrimeArray[j] = PrimeArray[j];
			}
			NewPrimeArray[SizPrimes-1] = number;
			PrimeArray = NewPrimeArray;
			if(EvOd(number) == 0)
				SizEvens++;
			else
				SizOdds++;
		}
	}
	EvenOnes = PrintEvens(PrimeArray , SizPrimes , SizEvens );
	OddOnes = PrintOdds(PrimeArray , SizPrimes , SizOdds);
	for (int i = 0; i < SizPrimes; ++i)
	{
		cout << i << " " << PrimeArray[i] << '\t';
		cout << endl;
	}
	for (size_t i = 0; i < SizEvens; i++)
	{
			cout << i << " " <<EvenOnes[i] << '\t';
			cout << endl;
	}
	for (size_t i = 0; i < SizOdds; i++)
	{
			cout << i << " " <<OddOnes[i] << '\t';
			cout << endl;
	}

	return 0;
}
