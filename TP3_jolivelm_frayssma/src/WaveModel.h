#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
#include "Height.h"
using namespace std;


class WaveModel
{
    private:
        Height HeightField;
        Dvector WindDirection;
        double alignement;
        double intensite;
        double longueur_onde;
        double ajustement;

    public:
        WaveModel(Dvector Wind, Height HgtF, double align, double intensity, double longueur, double ajust);

        Height getHeightField() { return HeightField;}
        Dvector getWind() {return WindDirection;}
        double getAlignement() {return alignement;}
        double getIntensite() {return intensite;}
        double getLongueur_onde() {return longueur_onde;}
        double getAjustement() {return ajustement;}

        void display(ostream& str) const;

};
