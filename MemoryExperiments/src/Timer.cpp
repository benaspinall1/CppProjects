// I am creating this file because I want to quantify the cost of allocating memory of the stack versus the heap. 

#include "Timer.h"
#include <iostream>

Timer::Timer()
{
	start = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration<float>(0);
};

Timer::~Timer()
{
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	milliseconds = duration.count() *1000.0f;
	std::cout << duration << " ms passed." << std::endl;

};