#include <cstdlib>   //exit macros
#include <vector>    //vector
#include <fstream>
#include <iostream>  //cout
#include <algorithm> //std::find
#include <cmath> 		//pow

/* Program implementing the seive of Eratosthenes. This program will find all the
 * prime numbers below a specified maximum number, set by default to 180 million
 * It is advised to pipe the output to a file, unless you want ~92 mb of prime
 * numbers to be dumped into your terminal. 
 */
typedef unsigned long long number_t; 
int main(int argc, char ** argv)
{
	//vector used here because vector<bool> is optimised for bit situations, drastically reducing the ram required to store 180 million bools. 
 	std::vector<bool> numbers;
//	const number_t max = 33906393741;
	const number_t max = 10000000000;
	const number_t maxroot = static_cast<number_t>(sqrt(max));
	const number_t percentage = max/100;
	//const number_t maxroot_percentage = maxroot/100;
	std::ofstream myfile;

	myfile.open("primes.txt");
//	numbers = std::vector<bool>(max);
//	std::fill_n(numbers.begin(),max,true);
	
	for(number_t i = 0; i<max; i++) 
	{//initialize the vector with true bools
		numbers.push_back(true);
	/*	if(i%percentage==0)
		{
			std::cerr << i/percentage <<'%' << "done\n";
		}*/
	}
	std::cerr << numbers.max_size() << '\n';
	numbers[0] = false; // though zero is not composite, it's not prime either
	numbers[1] = false; // 1 is not prime. 
	for(number_t i = 2; i < max;i++)
	{	
		if(numbers[i])
		{
			//std::cerr << i << "\n";
			myfile << i <<'\n';
			for(number_t j = pow(i,2); j<max; j+=i)
			{
				numbers[j] = false;
				/*if(j%percentage==0)
				{
					std::cerr << j/percentage <<'%' << "done\n";
				}*/
			}
		}
	}/*
	for(auto it = numbers.begin(); it!=numbers.end();it++)
	{//retained in case it is desired to write to a file.
		if(*it)
		{
			std::cout << it - numbers.begin() << "\n";
		}
	}
	*/
	
	myfile.close();
	return(EXIT_SUCCESS);
}

