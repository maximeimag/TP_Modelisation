#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

#ifndef OCEANH
#define OCEANH

class Ocean
{
    private:
        Height HeightField;
        WaveModel Model;
        double time_skip;
        double time_val;

    public:
        Ocean(Height HeightField, WaveModel Model, double init_time_skip, double init_time_val);
        ~Ocean();

        main_computaion();
        compute(double time_val);

        void init_gl_VertexArrayX(const int y, double* const vertices);
        void init_gl_VertexArrayY(const int x, double* const vertices);
        void gl_VertexArrayX(const int y, double* const vertices);
        void gl_VertexArrayY(const int x, double* const vertices);

        int getNx { return HeightField.getn_x();}
        int getNy { return HeightField.getn_y();}
        double get_lx { return HeightField.getL_x();}
        double get_ly { return HeightField.getL_y();}
}

#endif
