#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
using namespace std;

#ifndef GWH
#define GWH



class GerstnerWave
{
    private:
        double amplitude;
        double phase;
        double frequence;
        Dvector direction;

    public:
        GerstnerWave();
        GerstnerWave(double amplitude, double phase, double frequence, Dvector direction);
        double EvalWave(Dvector x0, double time);
        void display(ostream& str) const;

};

#endif
