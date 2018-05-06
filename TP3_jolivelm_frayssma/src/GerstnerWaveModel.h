#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
#include "WaveModel.h"
#include "GerstnerWave.h"

using namespace std;


class GerstnerWaveModel : public WaveModel
{
    private:
        GerstnerWave *listeGerstner;
        size_t nb_wave;

    public:
        GerstnerWaveModel(Dvector Wind, Height HeightField, double align, double intensity, double longueur, double ajust, GerstnerWave * listeGerstner, size_t nb_wave);

};
