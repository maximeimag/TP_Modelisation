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
        ~WaveModel();

        WaveModel & operator=(const WaveModel &WvM);

        Dvector getWind() {return WindDirection;}

        void display(ostream& str) const;
};

#endif
