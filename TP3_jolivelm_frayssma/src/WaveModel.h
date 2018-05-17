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

#ifndef WVMH
#define WVMH


class WaveModel
{
    protected:
        Dvector WindDirection;

    public:
        WaveModel();
        WaveModel(Dvector Wind);
        virtual ~WaveModel();

        WaveModel & operator=(const WaveModel &WvM);

        Dvector getWind() {return WindDirection;}

        virtual void computeModel(Height &HeightField, int nx, int ny, double lx, double ly, double time_val);

        virtual void display(ostream& str) const;
};

#endif
