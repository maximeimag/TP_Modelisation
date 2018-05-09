#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Height.h"
#include "WaveModel.h"
#include "GerstnerWaveModel.h"
using namespace std;

#ifndef OCEANH
#define OCEANH

class Ocean
{
    private:
        Height HeightField;
        GerstnerWaveModel Model;
        double time_skip;
        double time_val;

    public:
        Ocean(Height & HeightField, GerstnerWaveModel & Model, double init_time_skip, double init_time_val);
        ~Ocean();

        void main_computation();

        void init_gl_VertexArrayX(const int y, double* const vertices) const;
        void init_gl_VertexArrayY(const int x, double* const vertices) const;
        void gl_VertexArrayX(const int y, double* const vertices) const;
        void gl_VertexArrayY(const int x, double* const vertices) const;

        int getNx() const { return HeightField.getn_x();}
        int getNy() const { return HeightField.getn_y();}
        double get_lx() const { return HeightField.getL_x();}
        double get_ly() const { return HeightField.getL_y();}

        void display(ostream& str) const;
};

#endif
