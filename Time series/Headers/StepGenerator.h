//
// Created by Romain Bomba on 20/11/2024.
//
#include "TimeSeriesGenerator.h"
#include <cmath>

#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H
class StepGenerator : public TimeSeriesGenerator {
    public :
    virtual vector<double> generateTimeSeries(int length){
        vector<double> timeSeries;
        timeSeries.push_back(0);

        for (int i = 1; i < length; i++) {
            // 50% chance of choosing the same value as the previous one
            if (rand() % 2 == 0) {
                timeSeries.push_back(timeSeries[i - 1]);
            }
            // 50% chance of choosing a random value between 0 and 100
            else {
                timeSeries.push_back(rand()%101);
            }
        }

        return timeSeries;
    }
};

#endif //STEPGENERATOR_H
