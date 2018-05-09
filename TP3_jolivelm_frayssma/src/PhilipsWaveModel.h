
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
        double align;
        double intensity;
        double longueur;
        double ajust;
        Dvector Wind;

    public:
        PhilipsWaveModel(Dvector Wind, double align, double intensity, double longueur, double ajust, double Constant);
        double computeModel();
        void display(ostream& str) const;
};
