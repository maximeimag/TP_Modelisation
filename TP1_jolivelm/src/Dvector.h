#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;
#ifndef DVECTORH
#define DVECTORH

class Dvector
{
    private:
        int dim;
        double *coordonnees;
    public:
        Dvector();
        Dvector(int n);
        Dvector(int n, double val_init);
        Dvector(Dvector *Dvec);
        Dvector(string filename);
        ~Dvector();
        void display(ostream& str);
        void fillRandomly();
        int size();
};

#endif
