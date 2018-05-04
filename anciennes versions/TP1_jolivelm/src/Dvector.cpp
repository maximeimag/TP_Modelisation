#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
using namespace std;

Dvector::Dvector() {
    dim = 2;
    coordonnees = new double[dim];
    coordonnees[0] = 0.0;
    coordonnees[1] = 0.0;
}

Dvector::Dvector(int n) {
    dim = n;
    coordonnees = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonnees[i] = 0.0;
    }
}

Dvector::Dvector(int n, double val_init) {
    dim = n;
    coordonnees = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonnees[i] = val_init;
    }
}

Dvector::Dvector(Dvector *Dvec) {
    dim = Dvec->dim;
    coordonnees = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonnees[i] = Dvec->coordonnees[i];
    }
}

Dvector::Dvector(string filename) {
    dim = 0;
    const char *name = filename.c_str();
    ifstream monFlux;
    monFlux.open(name);
    vector<double> data;

    if (monFlux) { // le fichier existe
        string ligne;

        while (getline(monFlux, ligne)) {
            dim += 1;
            const char *line = ligne.c_str();
            data.push_back(atof(line));
        }

    } else { // le fichier n'existe pas
        cout << "Fichier " << filename << " introuvable.";
    }

    coordonnees = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonnees[i] = data[i];
    }


}

Dvector::~Dvector() {
    delete [] coordonnees;
}

void Dvector::display(ostream& str) {
    for (int i = 0; i < dim; i++) {
        str << coordonnees[i] << "\n";
    }
}

void Dvector::fillRandomly() {
    int nb_pas = 500000;
    double rng;
    for (int i = 0; i < dim; i++) {
        rng = rand() % nb_pas;
        coordonnees[i] = (double)rng / (double)nb_pas;
    }
}

int Dvector::size() {
    return dim;
}
