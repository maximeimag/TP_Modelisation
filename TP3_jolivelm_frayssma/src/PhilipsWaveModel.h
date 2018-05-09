
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
#include "WaveModel.h"

using namespace std;

#ifndef PWVMH
#define PWVMH



class PhilipsWaveModel : public WaveModel
{
    private:
        double WaveConstant;

    public:
        PhilipsWaveModel();
        PhilipsWaveModel(Dvector Wind, double align, double intensity, double longueur, double ajust, double Constant);
        double computeModel(Dvector x0, double time_val);
        ~PhilipsWaveModel();
};

#endif
