#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "PhilipsWaveModel.h"
using namespace std;



PhilipsWaveModel::PhilipsWaveModel(Dvector Wind, double align, double intensity, double longueur, double ajust, double constant):WaveModel(Wind, align, intensity, longueur, ajust) {
    this->WaveConstant = constant;
}
