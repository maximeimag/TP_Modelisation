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

GerstnerWaveModel::~GerstnerWaveModel() {
    delete &this->WindDirection;
}

GerstnerWaveModel & GerstnerWaveModel::operator=(const GerstnerWaveModel &Model) {
    WindDirection = Model.WindDirection;
    alignement = Model.alignement;
    intensite = Model.intensite;
    longueur_onde = Model.longueur_onde;
    ajustement = Model.ajustement;
    nb_wave = Model.nb_wave;

    delete [] listeGerstner;
    listeGerstner = new GerstnerWave[nb_wave];
    memcpy(listeGerstner, Model.listeGerstner, nb_wave*sizeof(GerstnerWave));
    return *this;
}
