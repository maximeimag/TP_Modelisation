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

WaveModel::WaveModel(Dvector Wind, Height HgtF, double align, double intensity, double longueur, double ajust) {
    this->HeightField = Height(HgtF);
    this->WindDirection = Dvector(Wind);
    this->alignement = align;
    this->intensite = intensity;
    this->longueur_onde = longueur;
    this->ajustement = ajust;
}

void WaveModel::display(ostream &str) const {
    this->WindDirection.display(str);
    this->HeightField.display(str);
    str << "alignement : " << alignement << "\n";
    str << "intensite : " << intensite << "\n";
    str << "longueur_onde : " << longueur_onde << "\n";
    str << "ajustement : " << ajustement << "\n";
}
