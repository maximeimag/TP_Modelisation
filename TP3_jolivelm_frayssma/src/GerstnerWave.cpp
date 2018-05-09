#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include "GerstnerWave.h"
using namespace std;

# define M_PI  3.14159265358979323846
////////////////////////////// Constructeurs /////////////////////////////////

GerstnerWave::GerstnerWave() {
    this->amplitude = 0;
    this->phase = 0;
    this->frequence = 0;
    this->direction = Dvector(2);
}

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

double GerstnerWave::EvalWave(Dvector x0, double time_val) {
    return this->amplitude*cos(dot(x0, direction)-(2*M_PI*this->frequence*time_val)+this->phase);
}
