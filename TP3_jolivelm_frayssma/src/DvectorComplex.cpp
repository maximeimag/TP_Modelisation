#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "DvectorComplex.h"
using namespace std;

////////////////////////////// Constructeurs /////////////////////////////////

DvectorComplex::DvectorComplex(int n, double val_initR, double val_initI) {
    dim = n;
    coordonneesR = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonneesR[i] = val_initR;
    }
    coordonneesI = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonneesI[i] = val_initI;
    }
}

DvectorComplex::DvectorComplex(const DvectorComplex &Dvec) {
    dim = Dvec.dim;
    coordonneesR = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonneesR[i] = Dvec.coordonneesR[i];
    }
    coordonneesI = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonneesI[i] = Dvec.coordonneesI[i];
    }
}

//////////////////////////// Destructeur /////////////////////////////////////

DvectorComplex::~DvectorComplex() {
    delete [] coordonneesR;
    delete [] coordonneesI;
}

/////////////////////////// Affichage ////////////////////////////////////////

void DvectorComplex::display(ostream& str) const {
    for (int i = 0; i < dim; i++) {
        str << coordonneesR[i] << " + ";
        str << coordonneesI[i] << "i\n";
    }
}
