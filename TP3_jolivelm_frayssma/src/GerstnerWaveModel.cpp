#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "GerstnerWaveModel.h"
using namespace std;



GerstnerWaveModel::GerstnerWaveModel(Dvector Wind, double align, double intensity, double longueur, double ajust, GerstnerWave * listeGerstner, size_t nb_wave):WaveModel(Wind, align, intensity, longueur, ajust) {
    this->listeGerstner = listeGerstner;
    this->nb_wave = nb_wave;
}

double GerstnerWaveModel::computeModel(Dvector x0, double time_val) {
    double val = 0;
    for (size_t i = 0; i < this->nb_wave; i++) {
        val += this->listeGerstner[i].EvalWave(x0, time_val);
    }
    return val;
}

void GerstnerWaveModel::display(ostream &str) const {
    for (size_t i = 0; i < this->nb_wave; i++) {
        str << "Wave [" << i << "]" << "\n";
        this->listeGerstner[i].display(str);
    }
}
