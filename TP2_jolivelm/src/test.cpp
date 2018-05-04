#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include "test.h"
#include "Dvector.h"

using namespace std;

int main () {
	Dvector v1 = Dvector(5, 4.3);
	Dvector v2 = v1;
	bool same = (v1 == v2);
	std::cout << same << '\n';
	v2(4) = 2.6;
	same = (v1 == v2);
	std::cout << same << '\n';
	std::cout << v1 << '\n';
	std::cout << v2 << '\n';
	std::cout << "v1" << '\n';
	std::cout << "v2" << '\n';
	std::cout << "fin" << '\n';
}
