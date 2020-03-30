#include "matrixChain.h"

#include <random>
#include <vector>
#include <iostream>

using namespace std;

MatrixChain::MatrixChain(int num){
  dimensions = vector<int>(num+1,0);
  for(int i=0;i<num+1;i++){
    int dim = rand()%SIZE+1;
    dimensions[i]=dim;
  }

  for(int i=0;i<num;i++){
    generate_matrix(dimensions[i],dimensions[i+1]);
  }
}

void MatrixChain::generate_matrix(int rows, int cols){
  srand(time(0));

  Matrix matrix(rows, vector<int>(cols,0));
  for (int j=0;j<rows;j++){//row
    for (int k=0;k<cols;k++){//
          matrix[j][k] = rand()%NUM+1;
      }
  }
  chain.push_back(matrix);
}

Matrix MatrixChain::multiply(Matrix a, Matrix b){
  //implement here the simple multiplication between two matrices
}

Matrix MatrixChain::dynamicChain(){
  //implement here the optimal approach using the dynamic programming algorithm
}
