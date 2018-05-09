#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */
#include "Ocean.hxx"
#include "Dvector.h"
#include "Height.h"
#include "GerstnerWaveModel.h"

#include "window.hxx"

Ocean *ocean = NULL;
int mainwindow = 0;

int main(int argc, char** argv) {
    /** @todo Initialiser des paramètres de simulation */
    double lx = 5;
    double ly = 5;
    int nx = 20;
    int ny = 20;
    Dvector Wind = Dvector(2, 2.5);
    double time_val = 0;
    double time_skip = 1;

    /** @todo Initialiser du modèle*/
    GerstnerWave listeGerstner[3];
	double val1 = 1.5;
	double val2 = 1.5;
    listeGerstner[0] = GerstnerWave(1.0, 1.0, 1.0, Wind);
    listeGerstner[1] = GerstnerWave(1.0, 1.0, 1.0, Wind);
    listeGerstner[2] = GerstnerWave(1.0, 1.0, 1.0, Wind);

    GerstnerWaveModel Gw = GerstnerWaveModel(Wind, val1, val2, val1, val2, listeGerstner, 3);

    /** @todo Initialiser du champ de hauteur */
    Height HeightField = Height(lx, ly, nx, ny, 0);

    /** @todo Initialiser de l'océan */
    Ocean ocean_model = Ocean(HeightField, Gw, time_skip, time_val);
    ocean = &ocean_model;

    ocean->display(cout);

    /* Initialisation de la fenêtre d'affichage */
    Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);

    /* Execute la simulation */
    Window::launch();

    /* Libère la mémoire */
    Window::quit();
    //delete ocean;

    return 0;

}
