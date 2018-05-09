#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include "../src/Dvector.h"

//Ce programme test les méthodes additionnelles de la classe Dvector

int main () {

//test de l'acces à un élément
Dvector v0;
assert( v0.size()==2 );
assert( v0(0)==0);
v0(0) = 1;
assert( v0(0)==1);
std::cout<<"OK ";

//test de l'opérateur =
Dvector v3; v3 = Dvector(3,2.5);
assert( v3.size()==3 );
std::ostringstream str3;
v3.display( str3 );
assert( str3.str()=="2.5\n2.5\n2.5\n");
std::cout<<"OK ";

//test des opérateurs mathématiques
v3 = v3 + 1;
assert( v3(0)==3.5);
v3 = v3 - 2;
assert( v3(0)==1.5);
v3 += 1;
assert( v3(0)==2.5);
v3 -= 1;
assert( v3(0)==1.5);
v3 *= 2;
assert( v3(0)==3);
v3 /= 3;
assert( v3(0)==1);
std::cout<<"OK ";

//test de l'égalité
assert(v3==Dvector(3,1));

//test de resize
v0.resize(4,2);
assert(v0(3)==2);

//test des streams
std::ostringstream str4;
str4 << v3;
cout << str4.str();
assert( str4.str()=="dim 3\n1\n1\n1\n");
cin >> v3;
assert( v3(0)==5);
std::cout<<"OK ";

}
