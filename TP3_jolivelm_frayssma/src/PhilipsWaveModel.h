
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
#include "WaveModel.h"

using namespace std;


class PhilipsWaveModel : public WaveModel
{
    private:
        double WaveConstant;

    public:
        PhilipsWaveModel(Dvector Wind, Height HeightField, double align, double intensity, double longueur, double ajust, double Constant);

};
