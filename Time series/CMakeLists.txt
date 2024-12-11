cmake_minimum_required(VERSION 3.29)
project(Time_series)

set(CMAKE_CXX_STANDARD 20)

add_executable(Time_series main.cpp
        Headers/GaussianGenerator.h
        Headers/GaussianGenerator.h
        Headers/TimeSeriesGenerator.h
        sources/GaussianGenerator.cpp
        Headers/StepGenerator.h
        Headers/SinWaveGenerator.h
        Headers/TimeSeriesDataset.h
        Headers/KNN.h
)
