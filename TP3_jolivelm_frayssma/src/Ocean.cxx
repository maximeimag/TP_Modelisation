#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "Ocean.hxx"
using namespace std;

Ocean::Ocean(Height & HeightField, PhilipsWaveModel & Model, double init_time_skip, double init_time_val) {
    this->HeightField = HeightField;
    this->Model = Model;
    this->time_skip = init_time_skip;
    this->time_val = init_time_val;
}

void Ocean::main_computation() {
    this->Model.computeModel(this->HeightField, this->getNx(), this->getNy(), this->get_lx(), this->get_ly(), this->get_time());
    this->time_val += this->time_skip;
}



/** Initialise la grille dans la direction x
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<this->getNx() ; x++) {
    vertices[3*x]   = (this->get_lx()/this->getNx())*x;
    vertices[3*x+2] = (this->get_ly()/this->getNy())*y;
  }
  vertices[3*this->getNx()]   = this->get_lx();
  vertices[3*this->getNx()+2] = (this->get_ly()/this->getNy())*y;
}

/** Initialise la grille dans la direction y
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<this->getNy() ; y++) {
    vertices[3*y]   = (this->get_lx()/this->getNx())*x;
    vertices[3*y+2] = (this->get_ly()/this->getNy())*y;
  }
  vertices[3*this->getNy()]   = (this->get_lx()/this->getNx())*x;
  vertices[3*this->getNy()+2] = this->get_ly();
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un y donné
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<this->getNx() ; x++) {
    vertices[3*x+1] = pow(-1, x+y)*HeightField(y, x);
  }
  vertices[3*this->getNx()+1] = pow(-1, this->getNx()+y)*HeightField(y, 0);
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un x donné
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<this->getNy() ; y++) {
    vertices[3*y+1] = HeightField(y,x);
  }
  vertices[3*this->getNy()+1]  = HeightField(0,x);
}

void Ocean::display(ostream& str) const {
    this->HeightField.display(str);
    this->Model.display(str);
    str << "time_val :" << time_val << '\n';
    str << "time_skip :" << time_skip << '\n';
}

Ocean::~Ocean() {
    delete &HeightField;
}
