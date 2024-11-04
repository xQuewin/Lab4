#include<iostream>
#include<iomanip>
#include"temperature.h"

int main() {

	// Create a TemperatureChart object
	TemperatureChart temperatureChart;

	//print the chart header with temperature ranges
	std::cout << "Temperature Chart" << std::endl;
	std::cout << std::setw(8) << "-30 " << "              0" << "              30" << "              60" << "              90" << "              120" << std::endl;

	// Call the getTemperatureChart function to display the temperature chart
	temperatureChart.getTemperatureChart();

	return 0;

}