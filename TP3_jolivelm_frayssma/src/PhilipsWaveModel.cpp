#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "PhilipsWaveModel.h"
using namespace std;

PhilipsWaveModel::PhilipsWaveModel():WaveModel() {
    this->WaveConstant = 0;
}

PhilipsWaveModel::PhilipsWaveModel(Dvector Wind, double align, double intensity, double longueur, double ajust, double constant):WaveModel(Wind, align, intensity, longueur, ajust) {
    this->WaveConstant = constant;
}

double PhilipsWaveModel::computeModel(Dvector x0, double time_val) {
    return 0;
}

PhilipsWaveModel::~PhilipsWaveModel() {
    delete &this->WindDirection;
}
