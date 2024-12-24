#include "alarm2.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void alarm(home_appliance P_property, vector<signal> waveform, vector<double> Period) {
    vector<double> timev;
    vector<double> timei_;
    vector<double> timeF;
    vector<double> timef_;

    for (size_t i = 0; i < waveform.size(); i++) {
        if (fabs(waveform.at(i).voltage) > P_property.getProperty().max_cap_volt) {
            timev.push_back(waveform.at(i).time);
        }
        if (fabs(waveform.at(i).current )> P_property.getProperty().max_cap_current) {
            timei_.push_back(waveform.at(i).time);
        }
        if (i < Period.size() && Period.at(i) != 0) {
            double frequency = 1 / Period.at(i);
            if (frequency > 50.5) {
                timeF.push_back(waveform.at(i).time);
            }
            if (frequency < 49.5) { // Assuming 49.5 as the lower threshold for frequency
                timef_.push_back(waveform.at(i).time);
            }
        }
    }

    if (timev.size() > 1) {
        double V_time = timev.back() - timev.front();
        String^ V_time_str = gcnew String(std::to_string(V_time).c_str());
        MessageBox::Show("Warning: Voltage was too high for " + V_time_str + " seconds.", "Voltage Alarm", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }

    if (!timei_.empty()) {
        double I_time = timei_.back() - timei_.front();
        MessageBox::Show("Warning: Current was too high for " + I_time.ToString("F2") + " seconds.", "Current Alarm", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
    if (!timeF.empty()) {
        double F_time = timeF.back() - timeF.front();
        MessageBox::Show("Warning: Frequency was too high for " + F_time.ToString("F2") + " seconds.", "Frequency High Alarm", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
    if (!timef_.empty()) {
        double ftime_under = timef_.back() - timef_.front();
        MessageBox::Show("Warning: Frequency was too low for " + ftime_under.ToString("F2") + " seconds.", "Frequency Low Alarm", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
}
