#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
using namespace std;


class GerstnerWave
{
    private:
        double amplitude;
        double phase;
        double frequence;
        Dvector direction;

    public:
        GerstnerWave(double amplitude, double phase, double frequence, Dvector direction);
        void display(ostream& str) const;

};
