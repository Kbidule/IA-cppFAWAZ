//
// Created by Romain Bomba on 20/11/2024.
//

#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H
#include "TimeSeriesGenerator.h"

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;
    double frequency;
    double phase;
public :
    SinWaveGenerator(double amplitude, double frequency, double phase, int seed):
    TimeSeriesGenerator(seed),
    amplitude(amplitude),
    frequency(frequency),
    phase(phase) {};
    SinWaveGenerator(double amplitude, double frequency, double phase):
    TimeSeriesGenerator(),
    amplitude(amplitude),
    frequency(),
    phase(phase) {};
    SinWaveGenerator():
    TimeSeriesGenerator(),
    amplitude(1),
    frequency(1),
    phase(0) {};
    vector<double> generateTimeSeries(int length) {
        vector<double> timeSeries;
        srand(this->seed);
        for (int i = 0; i < length; i++) {
            timeSeries.push_back(this->amplitude * sin(this->frequency * i + this->phase));
        }
        return timeSeries;
    }
};

#endif //SINWAVEGENERATOR_H
