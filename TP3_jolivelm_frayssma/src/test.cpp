#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include "test.h"
#include "Dvector.h"
#include "Height.h"
#include "GerstnerWaveModel.h"

using namespace std;

int main () {
	Height h1 = Height(4.5, 3.2, 10, 20, 27);
	h1(4, 7) = 3.7;
	double val1 = h1(4, 6);
	double val2 = h1(4, 7);
	std::cout << val1 << '\n';
	std::cout << val2 << '\n';
	h1.display(cout);

	Dvector v = Dvector(3, 2.5);
	v(1) = 5.3;
	v.display(cout);

	GerstnerWave wave = GerstnerWave(1.0, 1.0, 1.0, v);

	WaveModel w = WaveModel(v, val1, val2, val1, val2);

	GerstnerWaveModel Gw = GerstnerWaveModel(v, val1, val2, val1, val2, &wave, 1);
    cout << "\n";
	wave.display(cout);
    cout << "\n";
	w.display(cout);
}
