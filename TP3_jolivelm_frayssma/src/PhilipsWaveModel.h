
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Dvector.h"
#include "WaveModel.h"
#include "DvectorComplex.h"

using namespace std;

#ifndef PWVMH
#define PWVMH



class PhilipsWaveModel : public WaveModel
{
    private:
        double WaveConstant;
        double WindSpeed;

    public:
        PhilipsWaveModel();
        PhilipsWaveModel(Dvector Wind, double Constant, double speed);

        virtual ~PhilipsWaveModel();
        virtual void computeModel(Height &HeightField, int nx, int ny, double lx, double ly, double time_val);
        virtual void display(ostream& str) const;
};

void fft(DvectorComplex & x, size_t n);

#endif
