//
// Created by Romain Bomba on 20/11/2024.
//
#include "../Headers/GaussianGenerator.h"
#include <vector>


vector<double> GaussianGenerator::generateTimeSeries(int length) {
    vector<double> timeSeries;
    srand(seed);
    for (int i = 0; i < length; i++) {
        double u1 = (double) rand() / RAND_MAX;
        double u2 = (double) rand() / RAND_MAX;
        double z = (double) (sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2) ) + (sqrt(-2.0 * log(u1)) * sin(2 * M_PI * u2)) / 2;
        timeSeries.push_back(mean + standardDeviation * z);
    }
    return timeSeries;
}