#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "GerstnerWaveModel.h"
using namespace std;


GerstnerWaveModel::GerstnerWaveModel():WaveModel() {
    this->listeGerstner = NULL;
    this->nb_wave = 0;
}

GerstnerWaveModel::GerstnerWaveModel(Dvector Wind, GerstnerWave * listeGerstner, size_t nb_wave):WaveModel(Wind) {
    this->listeGerstner = listeGerstner;
    this->nb_wave = nb_wave;
}

void GerstnerWaveModel::computeModel(Height &HeightField, int nx, int ny, double lx, double ly, double time_val) {
    Dvector pos = Dvector(2);
    double val;
    for (size_t i = 0; i < ny; i++) {
        for (size_t j = 0; j < nx; j++) {
            pos(0) = ((double)i/ny)*ly;
            pos(1) = ((double)j/nx)*lx;
            val = 0;
            for (size_t i = 0; i < this->nb_wave; i++) {
                val += this->listeGerstner[i].EvalWave(pos, time_val);
            }
            HeightField(i, j) = val;
        }
    }
}

void GerstnerWaveModel::display(ostream &str) const {
    str << "Wind direction :\n";
    this->WindDirection.display(str);
    for (size_t i = 0; i < this->nb_wave; i++) {
        str << "Wave [" << i << "]" << "\n";
        this->listeGerstner[i].display(str);
    }
}

GerstnerWaveModel::~GerstnerWaveModel() {
  return;
}

GerstnerWaveModel & GerstnerWaveModel::operator=(const GerstnerWaveModel &Model) {
    WindDirection = Model.WindDirection;
    nb_wave = Model.nb_wave;
    delete [] listeGerstner;
    listeGerstner = new GerstnerWave[nb_wave];
    memcpy(listeGerstner, Model.listeGerstner, nb_wave*sizeof(GerstnerWave));
    return *this;
}
