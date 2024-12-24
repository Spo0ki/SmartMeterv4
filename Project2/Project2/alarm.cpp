
/*#include "alarm.h"
using namespace std;



using namespace System::Windows::Forms;

void alarm(home_appliance P_property, vector<signal> waveform, vector<double> Period) {
    vector<double> timev;
    vector<double> timei_;
    vector<double> timeF;
    vector<double> timef_;

    for (int i = 0; i < waveform.size(); i++) {
        if (waveform.at(i).voltage > P_property.getProperty().max_cap_volt) {
            timev.push_back(waveform.at(i).time);
        }
        if (waveform.at(i).current > P_property.getProperty().max_cap_current) {
            timei_.push_back(waveform.at(i).time);
        }
        if (1 / Period.at(i) > 50.5) {
            timeF.push_back(waveform.at(i).time);
        }
        if (1 / Period.at(i) < 49.5) { // Assuming 49.5 as the lower threshold for frequency
            timef_.push_back(waveform.at(i).time);
        }
    }

    if (!timev.empty()) {
        double V_time = timev.back() - timev.front();
        MessageBox::Show("Warning: Voltage was too high for " + V_time.ToString() + " seconds.", "Voltage Alarm", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
    if (!timei_.empty()) {
        double I_time = timei_.back() - timei_.front();
        MessageBox::Show("Warning: Current was too high for " + I_time.ToString() + " seconds.", "Current Alarm", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
    if (!timeF.empty()) {
        double F_time = timeF.back() - timeF.front();
        MessageBox::Show("Warning: Frequency was too high for " + F_time.ToString() + " seconds.", "Frequency High Alarm", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
    if (!timef_.empty()) {
        double ftime_under = timef_.back() - timef_.front();
        MessageBox::Show("Warning: Frequency was too low for " + ftime_under.ToString() + " seconds.", "Frequency Low Alarm", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
}
*/