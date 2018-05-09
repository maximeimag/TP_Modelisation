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

//test de la classe DvectorComplex (CLASSE INCOMPLETTE)
DvectorComplex vc1(3,2.5,3.5);
std::ostringstream str1;
vc1.display( str1 );
assert( str1.str()=="2.5 + 3.5i\n2.5 + 3.5i\n2.5 + 3.5i\n");
std::cout<<"OK "<< endl;

//test de la classe PhilipsWaveModel (CLASSE INCOMPLETTE)
PhilipsWaveModel wmp0(Dvector(2,3), 1.5, 2.5, 3.5, 4.5, 5.5);
std::ostringstream str;
wmp0.display( str );
assert(str.str()=="3\n3\nalign :1.5\nintensity :2.5\nlongueur :3.5\najust :4.5\nconstant :5.5\n");
std::cout<<"OK "<< endl;

}
