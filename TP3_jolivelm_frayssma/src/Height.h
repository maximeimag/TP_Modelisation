#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
using namespace std;


class Height
{
    private:
        double L_x;
        double L_y;
        size_t n_x;
        size_t n_y;
        Dvector datas;

    public:
        Height(double L_x, double L_y, int n_x, int n_y, double val_init);
        ~Height();

        double & operator()(int i, int j) const { return this->datas(i*n_x + j);}

        double getL_x();
        double getL_y();
        int getn_x();
        int getn_y();

        void set(int i, int j, double val);

        void display(ostream& str) const;

};
