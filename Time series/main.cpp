#include "Headers/GaussianGenerator.h"
#include "Headers/SinWaveGenerator.h"
#include "Headers/StepGenerator.h"
#include "Headers/TimeSeriesDataset.h"
#include "Headers/TimeSeriesGenerator.h"
#include "Headers/KNN.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    TimeSeriesDataset trainData(false, true);
    TimeSeriesDataset testData(false, false);

    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;

    vector<double> gaussian1 = gsg.generateTimeSeries(11);
    TimeSeriesGenerator::printTimeSeries(gaussian1);
    trainData.addTimeSeries(gaussian1, 0);

    vector<double> gaussian2 = gsg.generateTimeSeries(11);
    TimeSeriesGenerator::printTimeSeries(gaussian2);
    trainData.addTimeSeries(gaussian2, 0);

    vector<double> sin1 = swg.generateTimeSeries(11);
    TimeSeriesGenerator::printTimeSeries(sin1);
    trainData.addTimeSeries(sin1, 1);

    vector<double> sin2 = swg.generateTimeSeries(11);
    TimeSeriesGenerator::printTimeSeries(sin2);
    trainData.addTimeSeries(sin2, 1);

    vector<double> step1 = stg.generateTimeSeries(11);
    TimeSeriesGenerator::printTimeSeries(step1);
    trainData.addTimeSeries(step1, 2);

    vector<double> step2 = stg.generateTimeSeries(11);
    TimeSeriesGenerator::printTimeSeries(step2);
    trainData.addTimeSeries(step2, 2);

    vector<int> ground_truth;

    testData.addTimeSeries(gsg.generateTimeSeries(11));
    ground_truth.push_back(0);

    testData.addTimeSeries(swg.generateTimeSeries(11));
    ground_truth.push_back(1);

    testData.addTimeSeries(stg.generateTimeSeries(11));
    ground_truth.push_back(2);


    return 0;
}