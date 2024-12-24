#pragma once
#include "variables.h"

void read_csv(std::string path, std::vector <signal>& waveform);
void read_csv(std::string path, std::vector <signal>& waveform, double Tsamp);