#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include "test.h"
#include "Dvector.h"

using namespace std;

int main () {
    Dvector v = Dvector("test/test1.txt");
    v.display(cout);
    cout << v.size() << "\n";
}
