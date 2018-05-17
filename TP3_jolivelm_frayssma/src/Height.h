#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
using namespace std;

#ifndef HEIGHTH
#define HEIGHTH


class Height
{
    private:
        double L_x;
        double L_y;
        size_t n_x;
        size_t n_y;
        Dvector datas;

    public:
        Height();
        Height(double L_x, double L_y, int n_x, int n_y, double val_init);
        Height(const Height &Hgt);
        ~Height();


        Height & operator=(const Height &Hgt);

        double & operator()(int i, int j) const { return this->datas(i*n_x + j);}

        double getL_x() const;
        double getL_y()const;
        int getn_x()const;
        int getn_y()const;

        void set(int i, int j, double val);

        void display(ostream& str) const;

};

#endif
