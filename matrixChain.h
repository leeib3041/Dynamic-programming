#ifndef MATRIXCHAIN_H
#define MATRIXCHAIN_H

#include <iostream>
#include <vector>

#define NUM 100 //maximum value for a cell of the matrix
#define SIZE 100 //maximum dimension for rows/columns of a matrix

using namespace std;

typedef vector<vector<int> > Matrix;

class MatrixChain
{
  protected:
    vector<Matrix> chain; // stores the matrices
    vector<int> dimensions; // stores the sizes of these matrices || rows = dimesnsions[i] and columns = dimensions[i+1]

  public:
    MatrixChain(int);
    Matrix rec_mul(int i, int j, Matrix K); // BONUS - recursion function to multiply all vertices in optimal order
    Matrix multiply(Matrix a, Matrix b); //TODO - BONUS
    Matrix dynamicChain(); //TODO

    void printDimensions(){
      //print the dimensions generated
      cout << "{";
      for(int i=0; i<dimensions.size()-1; i++){
        cout << dimensions[i] << ",";
      }
      cout << dimensions[dimensions.size()-1] << "}" << endl;
    }

    /* 
      helper get_functions for printing final matrix answer
    */
    // int get_row() { return dimensions[0]; } 
    // int get_col() { return dimensions[chain.size()]; }

  private:
    void generate_matrix(int, int);
};

#endif
