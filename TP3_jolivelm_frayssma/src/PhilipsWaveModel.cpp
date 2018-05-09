#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "PhilipsWaveModel.h"
using namespace std;



PhilipsWaveModel::PhilipsWaveModel(Dvector Wind, double align, double intensity, double longueur, double ajust, double constant):WaveModel(Wind, align, intensity, longueur, ajust) {
    this->Wind=Wind;
    this->align = align;
    this->intensity= intensity;
    this->longueur=longueur;
    this->ajust=ajust;
    this->WaveConstant = constant;
}

double PhilipsWaveModel::computeModel() {
    cout << "PhilipsWaveModel non implémenté";
    return 0;
}

void PhilipsWaveModel::display(ostream &str) const {
  this->Wind.display(str);
  str << "align :" << align << "\n";
  str << "intensity :" << intensity << "\n";
  str << "longueur :" << longueur << "\n";
  str << "ajust :" << ajust << "\n";
  str << "constant :" << WaveConstant << "\n";
}
