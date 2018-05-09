#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include "../src/Dvector.h"

//Ce programme test la classe Dvector

int main () {

//test du constructeur par défaut, du display et de size()
Dvector v0;
assert( v0.size()==2 );
std::ostringstream str0;
v0.display( str0 );
assert( str0.str()=="0\n0\n");
std::cout<<"OK ";

//test du constructeur à deux entrées
Dvector v1(3,2.5);
assert( v1.size()==3 );
std::ostringstream str1;
v1.display( str1 );
assert( str1.str()=="2.5\n2.5\n2.5\n");
std::cout<<"OK ";

//test de fillRandomly()
Dvector v2 = Dvector(3,2.5);
assert( v2.size()==3 );
v2.fillRandomly();
assert( v2.size()==3 );
std::ostringstream str2;
v2.display( str2 );
assert( str2.str()!="2.5\n2.5\n2.5\n");
std::cout<<"OK ";

//test du constructeur par recopie
Dvector v3 = Dvector(v1);
assert( v3.size()==3 );
std::ostringstream str3;
v3.display( str3 );
assert( str3.str()=="2.5\n2.5\n2.5\n");
std::cout<<"OK ";

//test du constructeur avec entrée fichier
Dvector v4("test/test1.txt");
assert( v4.size()==10 );
std::ostringstream str4;
v4.display( str4 );
assert( str4.str()=="1.62182\n7.94285\n3.11215\n5.28533\n1.65649\n6.01982\n2.62971\n6.54079\n6.89215\n7.48152\n");
std::cout<<"OK ";



}
