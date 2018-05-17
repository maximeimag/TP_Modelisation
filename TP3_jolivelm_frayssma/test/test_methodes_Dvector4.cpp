#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include "../src/DvectorComplex.h"
#include "../src/Height.h"
#include "../src/PhilipsWaveModel.h"


//Ce programme test la classe PhilipsWaveModel et dvectorComplex

int main () {

//test de la classe DvectorComplex
DvectorComplex vc1(3,2.5,3.5);
std::ostringstream str1;
vc1.display( str1 );
assert( str1.str()=="2.5 + 3.5i\n2.5 + 3.5i\n2.5 + 3.5i\n");
std::cout<<"OK "<< endl;

//test de la classe PhilipsWaveModel
PhilipsWaveModel wmp0(Dvector(2,3), 1.5, 2.5);
std::ostringstream str;
wmp0.display( str );
assert(str.str()=="WindSpeed : 2.5\nWaveConstant : 1.5\n");
std::cout<<"OK "<< endl;

}
