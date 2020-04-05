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
  int a_row = a.size();
  int a_col = a[0].size();
  int b_col = b[0].size();
  
  Matrix mul(a_row, vector<int>(b_col, 0));

  for (int i = 0; i < a_row; i++) {
    for (int j = 0; j < b_col; j++) {
      int sum = 0;
      for (int k = 0; k < a_col; k++) {
        sum += (a[i][k] * b[k][j]);
      }
      mul[i][j] = sum;
    }
  }
  // // print new matrix
  // cout << "row: " << mul.size() << "   col: " << mul[0].size() << endl;
  // for (int i = 0; i < mul.size(); i++) {
  //   for (int j = 0; j < mul[i].size(); j++) {
  //     cout << mul[i][j] << "\t";
  //   }
  //   cout << endl;
  // }

  return mul;
}

Matrix MatrixChain::dynamicChain(){
  //implement here the optimal approach using the dynamic programming algorithm
  int inf = std::numeric_limits<int>::max(); // representing infinity with max value for int
  int n = chain.size();
  Matrix N(n, vector<int>(n, 0));
  Matrix K(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    N[i][i] = 0;
    K[i][i] = 0;
  }

  for (int starting_entry = 1; starting_entry < n; starting_entry++) {
    for (int row = 0; row < n-starting_entry; row++) {
      int col = starting_entry + row;
      N[row][col] = inf;

      for (int k = row; k < col; k++) {
        int num_steps = N[row][k] + N[k+1][col] + (dimensions[row]*dimensions[k+1]*dimensions[col+1]);
        if (num_steps < N[row][col]) {
          N[row][col] = num_steps;
          K[row][col] = k-row;
        }
      }
    }
  }
  cout << endl << "Minimum number of steps required for multiplying the chain of matrices: " << N[0][n-1] << endl;

  for (int i = 0; i < n-1; i++) {
    multiply(chain[i], chain[i+1]);
  }
  

  // // matrix initialization print test
  // cout << endl;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << N[i][j] << "\t";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << K[i][j] << "\t";
  //   }
  //   cout << endl;
  // }

  // // print matrices in chain
  // cout << endl;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < chain[i].size(); j++) {
  //     for (int k = 0; k <chain[i][j].size(); k++) {
  //       cout << chain[i][j][k] << "\t";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }

  return K;
}
