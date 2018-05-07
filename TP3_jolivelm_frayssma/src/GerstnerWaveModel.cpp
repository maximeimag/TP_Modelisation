#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "GerstnerWaveModel.h"
using namespace std;



GerstnerWaveModel::GerstnerWaveModel(Dvector Wind, Height HeightField, double align, double intensity, double longueur, double ajust, GerstnerWave * listeGerstner, size_t nb_wave):WaveModel(Wind, HeightField, align, intensity, longueur, ajust) {
    this->listeGerstner = listeGerstner;
    this->nb_wave = nb_wave;
}
