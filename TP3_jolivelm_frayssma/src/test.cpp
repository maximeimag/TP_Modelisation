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
	double val1 = 1.5;
	double val2 = 1.5;
	Height HeightField = Height(5, 5, 20, 20, 0);

	Dvector Wind = Dvector(2, 2.5);

	GerstnerWave listeGerstner[3];
	listeGerstner[0] = GerstnerWave(1.0, 1.0, 1.0, Wind);
	listeGerstner[1] = GerstnerWave(1.0, 1.0, 1.0, Wind);
	listeGerstner[2] = GerstnerWave(1.0, 1.0, 1.0, Wind);

	WaveModel w = WaveModel(Wind, val1, val2, val1, val2);

	GerstnerWaveModel Gw = GerstnerWaveModel(Wind, val1, val2, val1, val2, listeGerstner, 3);
	double val3 = listeGerstner[0].EvalWave(Wind, 0);
	double val4 = Gw.EvalWaves(Wind, 0);

	std::cout << val3 << '\n';
	std::cout << val4 << '\n';
	Gw.display(cout);

}
