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

////////////////////////////// Constructeurs /////////////////////////////////

Height::Height(double L_x, double L_y, int n_x, int n_y, double val_init) {
    this->L_x = L_x;
    this->L_y = L_y;
    this->n_x = n_x;
    this->n_y = n_y;
    this->datas = Dvector(n_x*n_y, val_init);
}

Height::~Height() {
    //delete [] this->datas;
}

double Height::getL_x() {
    return L_x;
}

double Height::getL_y() {
    return L_y;
}

int Height::getn_x() {
    return n_x;
}

int Height::getn_y() {
    return n_y;
}

void Height::set(int i, int j, double val) {
    this->datas(i*n_y + n_x) = val;
}

void Height::display(ostream& str) const {
    for (size_t i = 0; i < n_y; i++) {
        for (size_t j = 0; j < n_x; j++) {
            str << this->datas(i*n_x + j) << " ";
        }
        str << "\n";
    }
}
