#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "PhilipsWaveModel.h"
using namespace std;

# define M_PI  3.14159265358979323846

PhilipsWaveModel::PhilipsWaveModel():WaveModel() {
    this->WindSpeed = 0;
    this->WaveConstant = 0;
}

PhilipsWaveModel::PhilipsWaveModel(Dvector Wind, double constant, double speed):WaveModel(Wind) {
    this->WindSpeed = speed;
    this->WaveConstant = constant;
}

void fft(DvectorComplex & x) {
    size_t n = x.getDim();
    if (n > 1) {
        size_t n_mid = n>>1;
        DvectorComplex even = DvectorComplex(n_mid, 0, 0);
        DvectorComplex odd = DvectorComplex(n_mid, 0, 0);
        double t_r;
        double t_i;
        double arg, a, b;
        for (size_t i = 0; i < n_mid; i++) {
            even.cp_val(i, i<<1, x);
            odd.cp_val(i, (i<<1)+ 1, x);
        }
        fft(even);
        fft(odd);
        for (size_t k = 0; k < n_mid; k++) {
            arg = 2*M_PI*((double)k/(double)n);
            a = odd.get_Real(k); b = odd.get_Im(k);
            t_r = a*cos(arg) + b*sin(arg);
            t_i = b*sin(arg) - a*sin(arg);
            x.set_Real(k, even.get_Real(k) + t_r);
            x.set_Im(k, even.get_Im(k) + t_i);
            x.set_Real(k + n_mid, even.get_Real(k + n_mid) + t_r);
            x.set_Im(k + n_mid, even.get_Im(k + n_mid) + t_i);
        }
    }
}

void ifft(DvectorComplex & x) {
    size_t n = x.getDim();
    if (n > 1) {
        for (size_t i = 0; i < n; i++) {
            x.set_Im(i, -x.get_Im(i));
        }
        fft(x);
        for (size_t i = 0; i < n; i++) {
            x.set_Real(i, x.get_Real(i)/(double)n);
            x.set_Im(i, -x.get_Im(i)/(double)n);
        }
    }
}


void PhilipsWaveModel::computeModel(Height &HeightField, int nx, int ny, double lx, double ly, double time_val) {
    DvectorComplex H = DvectorComplex(nx*ny, 0, 0);
    double kx, ky, norm_k, g = 9.81, P1, P2, omega_time, val_attrib;
    int ix, jy;
    Dvector k = Dvector(2), sigma = Dvector(2);
    sigma.fillNormal();
    // Fréquences de la houle de Philips
    for (size_t i = 0; i < ny; i++) {
        ix = i - (ny>>1);
        kx = (2*M_PI*ix)/ly;
        k(0) = kx;
        for (size_t j = 0; j < nx; j++) {
            jy = j - (nx>>1);
            ky = (2*M_PI*jy)/lx;
            k(1) = ky;
            norm_k = k.norm();
            P1 = sqrt(WaveConstant * exp(-1/square((norm_k*square(WindSpeed))/g)) * square(dot(k, WindDirection)));
            P2 = sqrt(WaveConstant * exp(-1/square((norm_k*square(WindSpeed))/g)) * square(-dot(k, WindDirection)));
            omega_time = sqrt(g*norm_k)*time_val;

            H.set_Real(j*ny + i, ((P1 + P2)*sigma(0)*cos(omega_time) - ((P1 + P2)*sigma(1)*sin(omega_time)))/sqrt(2));
            H.set_Im(j*ny + i, ((P1 - P2)*sigma(0)*sin(omega_time) - ((P1 - P2)*sigma(1)*cos(omega_time)))/sqrt(2));
        }
    }
    // appliccation de la fft inverse
    ifft(H);
    // affectation dans le champ des hauteur
    for (size_t i = 0; i < ny; i++) {
        for (size_t j = 0; j < nx; j++) {
            val_attrib = H.get_Real(j*ny + i);
            if (val_attrib > 10) {
                val_attrib = 10;
            } else if (val_attrib < -10 ) {
                val_attrib = -10;
            }
            HeightField(i, j) = val_attrib;
        }
    }

}

void PhilipsWaveModel::display(ostream &str) const {
    str << "WindSpeed : " << WindSpeed << endl;
    str << "WaveConstant : " << WaveConstant << endl;
}
