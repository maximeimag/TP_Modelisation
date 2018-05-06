#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

#ifndef DVECTORH
#define DVECTORH

class Dvector
{
    private:
        int dim;
        double *coordonnees;

    public:
        Dvector();
        Dvector(int n);
        Dvector(int n, double val_init);
        Dvector(const Dvector &Dvec);
        Dvector(string filename);
        ~Dvector();

        double & operator()(int i) const { return coordonnees[i];}

        Dvector & operator=(const Dvector &v);
        //Dvector operator=(const Dvector);

        Dvector & operator+=(const Dvector &v);
        Dvector & operator-=(const Dvector &v);
        Dvector & operator*=(const Dvector &v);
        Dvector & operator/=(const Dvector &v);

        Dvector & operator+=(const double &);
        Dvector & operator-=(const double &);
        Dvector & operator*=(const double &);
        Dvector & operator/=(const double &);

        bool operator==(const Dvector &);

        void display(ostream& str) const;
        void fillRandomly();
        int size() const;
};

Dvector  operator+(const Dvector &, const Dvector &);
Dvector  operator-(const Dvector &, const Dvector &);
Dvector  operator*(const Dvector &, const Dvector &);
Dvector  operator/(const Dvector &, const Dvector &);

Dvector  operator+(const Dvector &, const double &);
Dvector  operator-(const Dvector &, const double &);
Dvector  operator*(const Dvector &, const double &);
Dvector  operator/(const Dvector &, const double &);

void operator-(Dvector &v);

ostream & operator<<(ostream &, const Dvector &);
istream & operator>>(istream &, Dvector &);

#endif
