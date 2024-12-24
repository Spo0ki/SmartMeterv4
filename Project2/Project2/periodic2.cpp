#include "periodic2.h" 
#include<vector>
using namespace std;
vector<double>getPeriod(const vector<signal>& waveform) {
	vector<double> peakTimes;
	for (int i = 1; i < waveform.size() - 1; ++i) {
		if (waveform.at(i).current > waveform.at(i - 1).current && waveform.at(i).current > waveform.at(i + 1).current) {
			peakTimes.push_back(waveform.at(i).time);
		}
	}
	vector <double> totalPeriod;
	for (int i = 1; i < peakTimes.size(); ++i) {
		totalPeriod.push_back((peakTimes[i] - peakTimes[i - 1]));
	}
	return totalPeriod;
}