#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
using namespace std;

////////////////////////////// Constructeurs /////////////////////////////////

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

Dvector::Dvector(const Dvector &Dvec) {
    dim = Dvec.dim;
    coordonnees = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonnees[i] = Dvec.coordonnees[i];
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

//////////////////////////// Destructeur /////////////////////////////////////

Dvector::~Dvector() {
    delete [] coordonnees;
}

//////////////////////////// Display /////////////////////////////////////////

void Dvector::display(ostream& str) const {
    for (int i = 0; i < dim; i++) {
        str << coordonnees[i] << "\n";
    }
}

//////////////////////////// Divers ///////////////////////////////////////////

void Dvector::fillRandomly() {
    int nb_pas = 500000;
    double rng;
    for (int i = 0; i < dim; i++) {
        rng = rand() % nb_pas;
        coordonnees[i] = (double)rng / (double)nb_pas;
    }
}

int Dvector::size() const {
    return dim;
}

////////////////////////// Operateurs : égalité ///////////////////////////////

Dvector & Dvector::operator=(const Dvector &v) {
    dim = v.size();
    coordonnees = new double[dim];
    memcpy(coordonnees, v.coordonnees, dim*sizeof(double));
    return *this;
}

/*
Dvector Dvector::operator=(const Dvector v) {
    dim = v.size();
    coordonnees = new double[dim];

    for (int i = 0; i < dim; i++) {
        coordonnees[i] = v(i);
    }

    return this;
}
*/

//////////////////////////// Operateurs : unaire vectoriel ////////////////////

Dvector & Dvector::operator+=(const Dvector &v) {
    if (dim != v.size()) {
        exit(-1); // vecteurs de tailles différentes
    } else {
        for (int i = 0; i < dim; i++) {
            coordonnees[i] += v(i);
        }
    }
    return *this;
}

Dvector & Dvector::operator-=(const Dvector &v) {
    if (dim != v.size()) {
        exit(-1); // vecteurs de tailles différentes
    } else {
        for (int i = 0; i < dim; i++) {
            coordonnees[i] -= v(i);
        }
    }
    return *this;
}

Dvector & Dvector::operator*=(const Dvector &v) {
    if (dim != v.size()) {
        exit(-1); // vecteurs de tailles différentes
    } else {
        for (int i = 0; i < dim; i++) {
            coordonnees[i] *= v(i);
        }
    }
    return *this;
}

Dvector & Dvector::operator/=(const Dvector &v) {
    if (dim != v.size()) {
        exit(-1); // vecteurs de tailles différentes
    } else {
        for (int i = 0; i < dim; i++) {
            if (v(i) == 0.0) {
                cout << "Erreur : coordonnée indéxée " << i << " nulle, division par zéro \n";
                exit(-1);
            } else {
                coordonnees[i] /= v(i);
            }
        }
    }
    return *this;
}


////////////////////////////////// Operateurs : unaire double /////////////////

Dvector & Dvector::operator+=(const double &val) {
    for (int i = 0; i < dim; i++) {
        coordonnees[i] += val;
    }
    return *this;
}

Dvector & Dvector::operator-=(const double &val) {
    for (int i = 0; i < dim; i++) {
        coordonnees[i] -= val;
    }
    return *this;
}

Dvector & Dvector::operator*=(const double &val) {
    for (int i = 0; i < dim; i++) {
        coordonnees[i] *= val;
    }
    return *this;
}

Dvector & Dvector::operator/=(const double &val) {
    if (val == 0.0) {
        cout << "Erreur : division par zéro \n";
        exit(-1);
    }
    for (int i = 0; i < dim; i++) {
        coordonnees[i] /= val;
    }
    return *this;
}


//////////////////////////////////// Operateurs : binaire vectoriel ///////////

Dvector operator+(const Dvector &u, const Dvector &v) {
    Dvector w = u;
    w += v;
    return w;
}

Dvector operator-(const Dvector &u, const Dvector &v) {
    Dvector w = u;
    w -= v;
    return w;
}

Dvector operator*(const Dvector &u, const Dvector &v) {
    Dvector w = u;
    w *= v;
    return w;
}

Dvector operator/(const Dvector &u, const Dvector &v) {
    Dvector w = u;
    w /= v;
    return w;
}

bool Dvector::operator==(const Dvector &v) {
    if (dim != v.size()) {
        std::cout << "comparaison de deux vecteurs de taille différentes" << '\n';
        exit(-1);
    } else {
        for (int i = 0; i < v.size(); i++) {
            if (coordonnees[i] != v(i)) {
                return false;
            }
        }
    }
    return true;
}

/////////////////////////////////////// Operateurs : binaire double ///////////

Dvector operator+(const Dvector &u, const double &val) {
    Dvector w = u;
    w += val;
    return w;
}

Dvector operator-(const Dvector &u, const double &val) {
    Dvector w = u;
    w -= val;
    return w;
}

Dvector operator*(const Dvector &u, const double &val) {
    Dvector w = u;
    w *= val;
    return w;
}

Dvector operator/(const Dvector &u, const double &val) {
    Dvector w = u;
    w /= val;
    return w;
}


///////////////////////////////////// Operateurs : unaires ////////////////////

void operator-(Dvector &v) {
    for (int i = 0; i < v.size(); i++) {
        v(i) = - v(i);
    }
}

///////////////////////////////////// Operateurs : I/O ////////////////////////

ostream & operator<<(ostream &out, const Dvector &v) {
    out << "dim " << v.size() << endl;
    for (int i = 0; i < v.size(); i ++) {
        out << v(i) << " ";
    }
    out << endl;
    return out;
}

istream & operator>>(istream &in, Dvector &v) {
    for (int i = 0; i < v.size(); i++) {
        in >> v(i);
    }
    return in;
}
