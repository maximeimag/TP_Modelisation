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
}

WaveModel::~WaveModel() {
    delete &this->WindDirection;
}

WaveModel::WaveModel(Dvector WindDirection_init) {
    this->WindDirection = Dvector(WindDirection_init);
}

void WaveModel::display(ostream &str) const {
    str << "Wind direction :\n";
    this->WindDirection.display(str);
}

WaveModel & WaveModel::operator=(const WaveModel &WvM) {
    WindDirection = WvM.WindDirection;
    return *this;
}
