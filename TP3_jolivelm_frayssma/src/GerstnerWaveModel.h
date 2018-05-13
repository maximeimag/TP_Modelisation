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
        GerstnerWaveModel();
        GerstnerWaveModel(Dvector Wind, GerstnerWave * listeGerstner, size_t nb_wave);
        void computeModel(Height &HeightField, int nx, int ny, double lx, double ly, double time_val);
        void display(ostream& str) const;

        GerstnerWaveModel & operator=(const GerstnerWaveModel &Model);
        ~GerstnerWaveModel();
};


#endif
