#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

#ifndef DVECTORCOMPLEXH
#define DVECTORCOMPLEXH

class DvectorComplex
{
    private:
        int dim;
        double *coordonneesR;
        double *coordonneesI;

    public:
        DvectorComplex(int n, double val_initR, double val_initI);
        DvectorComplex(const DvectorComplex &Dvec);
        ~DvectorComplex();

        void display(ostream& str) const;
};

#endif
