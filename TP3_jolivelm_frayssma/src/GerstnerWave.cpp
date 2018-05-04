#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "GerstnerWave.h"
using namespace std;

////////////////////////////// Constructeurs /////////////////////////////////

GerstnerWave::GerstnerWave(double amplitude, double phase, double frequence, Dvector direction) {
    this->amplitude = amplitude;
    this->phase = phase;
    this->frequence = frequence;
    this->direction = Dvector(direction);
}

void GerstnerWave::display(ostream &str) const {
    this->direction.display(str);
    str << "amplitude :" << amplitude << "\n";
    str << "phase :" << phase << "\n";
    str << "frequence :" << frequence << "\n";
}
