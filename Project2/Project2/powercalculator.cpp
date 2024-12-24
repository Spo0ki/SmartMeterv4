#include<iostream>
#include "powercalculator.h"
using namespace std;

double powercalculator::CalcPowerAverage(const vector<double>& voltages, const vector<double>& currents)
{
	double SumPower = 0;
	int size = currents.size();
	for (int i = 0; i < size; i++)
	{
		SumPower += voltages[i] * currents[i];
	}
	return SumPower/size;
}