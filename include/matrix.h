#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include "all-headers.h"
using namespace std;

#ifndef __MATRICI_H__
#define __MATRICI_H__

typedef struct Tmatrix{ // Struct Tmatrix 
    float **mat; // Fraction **mat;
    int nr; 
    int nc;
    string name;

    Tmatrix(){ // default constructor
        nr = nc = 0;
    }

    Tmatrix(int _nr, int _nc){ // Matrix init
        nr = _nr;
        nc = _nc;
        mat = new float*[nr];
        for(int i = 0; i < nr; i++){
            mat[i] = new float[nc];
        }
    }

    Tmatrix(string _name, int _nr, int _nc){ // Matrix init
        name = _name;
        nr = _nr;
        nc = _nc;
        mat = new float*[nr];
        for(int i = 0; i < nr; i++){
            mat[i] = new float[nc];
        }
    }

    Tmatrix(int _nr, int _nc, int min, int max){ // Random number init constructor
        nr = _nr;
        nc = _nc;
        mat = new float*[nr];
        for(int i = 0; i < nr; i++){
            *(mat + i) = new float[nc];
            for(int j = 0; j < nc; j++){
                *( *(mat + i) + j) = (rand() % (max - min + 1) + min);
            }
        }
    }

    void copy_matrix(Tmatrix *a){ // Initializes the current matrix by copying a new one
        nr = a->nr;
        nc = a->nc;
        mat = new float*[nr];
        for(int i = 0; i < nr; i++){
            mat[i] = new float[nc];
            for(int j = 0; j < nc; j++){
                mat[i][j] = a->mat[i][j];
            }
        }
    }

    ~Tmatrix(){ // Destroy f.
        for(int i = 0; i < nr; i++)
            delete[] mat[i];

        delete[] mat;
    }

    void sum(Tmatrix *b){ //Sums a new matrix to the current one
        for(int i = 0; i < nr; i++){
            for(int j = 0; j < nc; j++){
                mat[i][j] = b->mat[i][j] + b->mat[i][j];
            }
        }
    }

    /*void Id_n(int n){
        nr = nc = n;
        mat = new float*[n];
        for(int i = 0; i < n; i++){
            mat[i] = new float[n];
            for(int j = 0; j < n; j++){

            }
        }
    }*/

} Tmatrix;

typedef Tmatrix* Matrix; 

Matrix init_matrix(string name);
void print_matrix(Matrix m);
Matrix matrix_transpose(Matrix m);
void matrix_sum(Tmatrix *sum, Tmatrix *a, Tmatrix *b);
Matrix matrix_multiplication(Matrix a, Matrix b);
Matrix matrix_scalar_multiplication(Matrix a, float lambda);
void S(Matrix m, int d, int s); // Change rows operation
void D(Matrix m, int a, float lambda); // Multiply a row by a real number
void E(Matrix m, int d, int s, float lambda); // Add a row to another, multiplied by lambda
string parse_fraction(string s);
void print_fract_matrix(Matrix m);
int rg(Matrix m); // rango
void matrix_stairs_gauss_jordan(Matrix m);
void matrix_rref_calculator(Matrix m);
Matrix matrix_rref_full(Matrix m);
bool is_stairs_form(Matrix m);
bool matrix_is_square(Matrix m);
bool matrix_is_base(Matrix m);
Matrix matrix_orthonormal_base(Matrix v);



#endif
