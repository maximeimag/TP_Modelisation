#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include "../src/Dvector.h"
#include "../src/Height.h"
#include "../src/WaveModel.h"
#include "../src/GerstnerWave.h"
#include "../src/GerstnerWaveModel.h"


//Ce programme test les classes Height, WaveModel, GerstnerWave et GerstnerWaveModel

int main () {

//test de la classe Height
Height h0;
Height h1(2.5, 3.5, 1, 2, 1.5);
Height h2 = Height(h1);
assert( h0.getL_x()==1 && h0.getL_y()==1 && h0.getn_x()==2 && h0.getn_y()==1);
assert( h1.getL_x()==2.5 && h1.getL_y()==3.5 && h1.getn_x()==1 && h1.getn_y()==2);
assert( h2.getL_x()==2.5 && h2.getL_y()==3.5 && h2.getn_x()==1 && h2.getn_y()==2);
std::ostringstream str1;
h1.display( str1 );
assert( str1.str()=="1.5 \n1.5 \n");
h2.set(0,0,2.5);
std::ostringstream str2;
h2.display( str2 );
cout << str2.str();
assert( str2.str()=="2.5 \n1.5 \n");
std::cout<<"OK ";

//test de la classe WaveModel
Dvector v0;
WaveModel w0(v0, 1.5, 2.5, 3.5, 4.5);
std::ostringstream str3;
w0.display( str3 );
assert( str1.str()!= "");
std::cout<<"OK ";

//test de GerstnerWave
GerstnerWave gw0(1.5, 2.5, 3.5, v0);
assert(gw0.EvalWave(Dvector(2,3),10)+1.20172<=0.00001 && gw0.EvalWave(Dvector(2,3),10)+1.20172>=-0.00001);
std::cout<<"OK ";

//test de GerstnerWaveModel
GerstnerWaveModel gwm0(v0, 1.5, 2.5, 3.5, 4.5, &gw0, 1);
assert(gwm0.computeModel(Dvector(2,3),10)+1.20172<=0.00001 && gwm0.computeModel(Dvector(2,3),10)+1.20172>=-0.00001);
std::cout<<"OK ";

}
