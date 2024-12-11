//
// Created by Romain Bomba on 20/11/2024.
//
#include <iostream>
#include <vector>
#include <ctime>
#include "TimeSeriesGenerator.h"
#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H
class GaussianGenerator : public TimeSeriesGenerator {
    private :
        double mean;
        double standardDeviation;
    public :
        GaussianGenerator(double mean, double standardDeviation, int seed): TimeSeriesGenerator(seed), mean(mean), standardDeviation(standardDeviation) {};
        GaussianGenerator(double mean, double standardDeviation): TimeSeriesGenerator(), mean(mean), standardDeviation(standardDeviation) {};
        GaussianGenerator(): TimeSeriesGenerator(), mean(0), standardDeviation(1) {};
        vector<double> generateTimeSeries(int length) override;
};

#endif //GAUSSIANGENERATOR_H
