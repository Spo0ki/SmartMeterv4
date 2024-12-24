#pragma once
#include "powerfactor.h"
#include <cmath>
#include <vector>

double powerfactor(const std::vector<signal>& waveform1) {
    double vrms = 0.0;
    double irms = 0.0;
    double tsample = waveform1.at(1).time - waveform1.at(0).time;
    int size = waveform1.size();

    for (int i = 0; i < size; i++) {
        vrms += pow(waveform1.at(i).voltage, 2);
        irms += pow(waveform1.at(i).current, 2);
    }
    vrms = sqrt(vrms / size);
    irms = sqrt(irms / size);

    double SumPower = 0;
    for (int i = 0; i < size; i++) {
        SumPower += waveform1.at(i).current * waveform1.at(i).voltage;
    }
    double real_power = SumPower / size;
    double apparent_power = vrms * irms;

    double powerfactor = real_power / apparent_power;
    return powerfactor;
}
