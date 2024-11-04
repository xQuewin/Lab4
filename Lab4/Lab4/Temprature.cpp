#include "Temperature.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

//constructor 
TemperatureChart::TemperatureChart()
{
}

//destructor
TemperatureChart::~TemperatureChart()
{
}

//function to get the temperature chart
void TemperatureChart::getTemperatureChart()
{
	//Open the input file containing the temperature values
	std::ifstream inputFile("TemperatureIn.dat");
	if (!inputFile)
	{
		std::cout << "Error opening the file" << std::endl;
		return;
	}

	//variable to store the temperature value read from the file
	float number;

	while (inputFile >> number)
	{
		//variable to store the number of stars to be printed
		double TempStar = 0;

		// Calculate the number of stars based on temperature (1star for every 3 degrees)
		TempStar = std::round(abs(number / 3));

		//positive temperature from 0 to 9 degrees
		if (number >= 0 && number < 10) {
			std::cout << std::setw(3) << number << std::setw(15) << " | ";
			while (TempStar > 0) {
				std::cout << "*";
				TempStar--;
			}
			std::cout << std::endl;
		}

		//positive temperature from 10 to 98 degrees
		else if (number >= 10 && number < 99) {
			std::cout << std::setw(3) << number << std::setw(15) << " | ";

			while (TempStar > 0) {
				std::cout << "*";
				TempStar--;
			}
			std::cout << std::endl;
		}

		//Negative temperature from -1 to -9 
		else if (number <= -1 && number > -10) {
			std::cout << std::setw(3);
			std::cout << number << std::setw(1 + (12 - TempStar));
			while (TempStar > 0) {
				std::cout << "*";
				TempStar--;
			}
			std::cout << " | ";
			std::cout << std::endl;
		}

		//Negative temperature from -10 to -30
		else if (number <= -10 && number >= -30) {
			std::cout << number;
			std::cout << std::setw(13 - TempStar);

			while (TempStar > 0) {
				std::cout << "*";
				TempStar--;
			}
			std::cout << " | ";
			std::cout << std::endl;
		}

		//temperature superior to 100
		else if (number >= 100) {
			std::cout << number << std::setw(15) << " | ";

			while (TempStar > 0) {
				std::cout << "*";
				TempStar--;
			}
			std::cout << std::endl;
		}
	}
}