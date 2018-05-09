#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
#include "WaveModel.h"
#include "GerstnerWave.h"

#ifndef GWMH
#define GWMH

using namespace std;


class GerstnerWaveModel : public WaveModel
{
    private:
        GerstnerWave *listeGerstner;
        size_t nb_wave;

    public:
        GerstnerWaveModel(Dvector Wind, double align, double intensity, double longueur, double ajust, GerstnerWave * listeGerstner, size_t nb_wave);
        double computeModel(Dvector x0, double time);
        void display(ostream& str) const;
};


#endif
