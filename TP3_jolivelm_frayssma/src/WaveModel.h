#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
using namespace std;


class WaveModel
{
    private:
        Dvector WindDirection;
        double alignement;
        double intensite;
        double longueur_onde;
        double ajustement;

    public:
        WaveModel(Dvector Wind, double align, double intensity, double longueur, double ajust);
        ~WaveModel();

        Dvector getWind() {return WindDirection;}
        double getAlignement() {return alignement;}
        double getIntensite() {return intensite;}
        double getLongueur_onde() {return longueur_onde;}
        double getAjustement() {return ajustement;}

        void display(ostream& str) const;

};