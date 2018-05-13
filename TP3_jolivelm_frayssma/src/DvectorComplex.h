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


        double get_Real(int i) const {return coordonneesR[i]; }
        double get_Im(int i) const {return coordonneesI[i]; }

        int getDim() { return dim;}

        void set_Real(int i, double val) {coordonneesR[i] = val; }
        void set_Im(int i, double val) {coordonneesI[i] = val; }
        void cp_val(int i, int j, const DvectorComplex &Dvec) {
            coordonneesR[i] = Dvec.get_Real(j);
            coordonneesI[i] = Dvec.get_Im(j);
        }

        void display(ostream& str) const;
};

#endif
