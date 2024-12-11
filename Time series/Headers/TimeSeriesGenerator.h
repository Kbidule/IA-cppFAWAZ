//
// Created by Romain Bomba on 20/11/2024.
//
#include <iostream>
#include <vector>
#include <ctime>

#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H
using namespace std;
class TimeSeriesGenerator {
public :
    virtual vector<double> generateTimeSeries(int length) = 0;
    void static printTimeSeries(const vector<double>& timeSeries) {
        for (int i = 0; i < timeSeries.size(); i++) {
            cout << timeSeries[i] << " ";
        }
        cout << endl;
    };
    TimeSeriesGenerator(int seed): seed(seed) {};
    TimeSeriesGenerator(): seed(time(NULL)) {};
protected:
    int seed;


};
#endif //TIMESERIESGENERATOR_H