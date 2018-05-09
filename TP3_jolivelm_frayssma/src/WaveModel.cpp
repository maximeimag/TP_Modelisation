#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "WaveModel.h"
using namespace std;



////////////////////////////// Constructeurs /////////////////////////////////

WaveModel::WaveModel() {
    this->WindDirection = Dvector(2);
    this->alignement = 0;
    this->intensite = 0;
    this->longueur_onde = 0;
    this->ajustement = 0;
}

WaveModel::~WaveModel() {
    delete &this->WindDirection;
}


WaveModel::WaveModel(Dvector Wind, double align, double intensity, double longueur, double ajust) {
    this->WindDirection = Dvector(Wind);
    this->alignement = align;
    this->intensite = intensity;
    this->longueur_onde = longueur;
    this->ajustement = ajust;
}

void WaveModel::display(ostream &str) const {
    this->WindDirection.display(str);
    str << "alignement : " << alignement << "\n";
    str << "intensite : " << intensite << "\n";
    str << "longueur_onde : " << longueur_onde << "\n";
    str << "ajustement : " << ajustement << "\n";
}

WaveModel & WaveModel::operator=(const WaveModel &WvM) {
    WindDirection = WvM.WindDirection;
    alignement = WvM.alignement;
    intensite = WvM.intensite;
    longueur_onde = WvM.longueur_onde;
    ajustement = WvM.ajustement;
    return *this;
}
