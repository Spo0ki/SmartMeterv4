#include "energy.h"
using namespace std;

double energycalc::Ecalculator(const vector<signal>& waveform1)
{
    double energy = 0;
    int size = waveform1.size();

    for (int i = 0; i < size - 1; i++)
    {
        double power = waveform1.at(i).current * waveform1.at(i).voltage;
        double time_interval = waveform1.at(i + 1).time - waveform1.at(i).time;
        energy += power * time_interval;
    }

    return energy / 3600000; // Convert joules to kilowatt-hours
}
