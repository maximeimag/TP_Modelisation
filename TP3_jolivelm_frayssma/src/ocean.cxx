#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

Ocean::Ocean(Height HeightField, WaveModel Model, double init_time_skip, double init_time_val) {
    this->HeightField = Height(HeightField);
    this->Model = Model;
    this->time_skip = init_time_skip;
    this->time_val = init_time_val;
}

void Ocean::main_computaion() {
    Dvector pos = Dvector(2);
    for (size_t i = 0; i < this->getNy; i++) {
        for (size_t j = 0; j < this->getNx; j++) {
            pos(0) = (i/this->getNy)*this->getL_y;
            pos(1) = (j/this->getNx)*this->getL_x;
            this->HeightField(i, j) = this->Model->computeModel(pos, this->time_val);
        }
    }
    this->time_val += this->time_skip;
}



/** Initialise la grille dans la direction x
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<nx ; x++) {
    vertices[3*x]   = (lx/nx)*x;
    vertices[3*x+2] = (ly/ny)*y;
  }
  vertices[3*nx]   = lx;
  vertices[3*nx+2] = (ly/ny)*y;
}

/** Initialise la grille dans la direction y
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<ny ; y++) {
    vertices[3*y]   = (lx/nx)*x;
    vertices[3*y+2] = (ly/ny)*y;
  }
  vertices[3*ny]   = (lx/nx)*x;
  vertices[3*ny+2] = ly;
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un y donné
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<nx ; x++) {
    vertices[3*x+1] = pow(-1, x+y)*HeigtField(y, x);
  }
  vertices[3*nx+1] = pow(-1, nx+y)*HeigtField(y, 0);
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un x donné
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<ny ; y++) {
    vertices[3*y+1] = HeigtField(y,x);
  }
  vertices[3*ny+1]  = HeigtField(0,x);
}
