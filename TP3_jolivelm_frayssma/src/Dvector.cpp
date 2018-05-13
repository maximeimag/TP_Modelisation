#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "Dvector.h"
using namespace std;

# define M_PI  3.14159265358979323846

////////////////////////////// Constructeurs /////////////////////////////////

Dvector::Dvector() {
    //cout << "la methode " << "Dvector() " << "a été appelée" << endl;
    dim = 2;
    coordonnees = new double[dim];
    coordonnees[0] = 0.0;
    coordonnees[1] = 0.0;
}

Dvector::Dvector(int n) {
    //cout << "la methode " << "Dvector(int n) " << "a été appelée" << endl;
    dim = n;
    coordonnees = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonnees[i] = 0.0;
    }
}

Dvector::Dvector(int n, double val_init) {
    //cout << "la methode " << "Dvector(int n, double val_init) " << "a été appelée" << endl;
    dim = n;
    coordonnees = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonnees[i] = val_init;
    }
}

Dvector::Dvector(const Dvector &Dvec) {
    //cout << "la methode " << "Dvector(const Dvector &Dvec) " << "a été appelée" << endl;
    dim = Dvec.dim;
    coordonnees = new double[dim];
    for (int i = 0; i < dim; i++) {
        coordonnees[i] = Dvec.coordonnees[i];
    }
}

Dvector::Dvector(string filename) {
    //cout << "la methode " << "Dvector(string filename) " << "a été appelée" << endl;
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
    //cout << "la methode " << "~Dvector() " << "a été appelée" << endl;
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

//estimation de la loi normale entrée réduite par la méthode de Box-Muller
void Dvector::fillNormal() {
    int nb_pas = 500000;
    double U, V;
    for (int i = 0; i < dim; i++) {
        U = (double)(rand() % nb_pas)/(double)nb_pas;
        V = (double)(rand() % nb_pas)/(double)nb_pas;
        coordonnees[i] = sqrt(-2*log(U))*cos(2*M_PI*V);
    }
}

void Dvector::resize(int taille, double valeur){
  if(dim < taille){
    double* temp = new double[taille];
    for (int i = 0; i<dim;i++){
      temp[i] = coordonnees[i];
    }
    for (int i = dim;i<taille;i++){
      temp[i] = valeur;
    }
    delete [] coordonnees;
    coordonnees = temp;
  }
}

int Dvector::size() const {
    return dim;
}

double square(double x) {
    return x*x;
}

double Dvector::norm() const {
    double norme = 0;
    for (int i = 0; i < dim; i++) {
        norme += square(coordonnees[i]);
    }
    return sqrt(norme);
}

double dot(const Dvector &u, const Dvector &v) {
    double prod = 0;
    if (v.size() == u.size()) {
        for (size_t i = 0; i < v.size(); i++) {
            prod += u(i)*v(i);
        }
    } else {
        std::cout << "dot btw Dvector with different sizes" << '\n';
        exit(-1);
    }
    return prod;
}

////////////////////////// Operateurs : égalité ///////////////////////////////


Dvector & Dvector::operator=(const Dvector &v) {
    dim = v.size();
    delete [] coordonnees;
    coordonnees = new double[dim];
    memcpy(coordonnees, v.coordonnees, dim*sizeof(double));
    return *this;
}

//autre implémentation de l'égalité

/*
Dvector & Dvector::operator=(const Dvector &v) {
    dim = v.size();
    coordonnees = new double[dim];

    for (int i = 0; i < dim; i++) {
        coordonnees[i] = v(i);
    }

    return *this;
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
        out << v(i) << "\n";
    }
    return out;
}

istream & operator>>(istream &in, Dvector &v) {
    for (int i = 0; i < v.size(); i++) {
        in >> v(i);
    }
    return in;
}
