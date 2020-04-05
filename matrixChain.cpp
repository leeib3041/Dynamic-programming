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
      /*
        reduce final output for large matrix input. 100 NUM/SIZE/MATRIX input causes overflow
        in INT's max pos value and causes sum to be negative value. Modulus keeps values in
        single digits so no overflow occurs. Not helpful for the correct answer, but helpful
        to confirm negative values do not actually exist and the algorithm isn't doing something
        weird. Modulus of negative number will result in negative output, so if algorithm is
        causing negative output, the modulus of that will also be negative.
        i.e.
        -7 % 2 = -1
        7 % 2 = 1
      */
      mul[i][j] = sum; // % 10; 
    }
  }
  /*
    print multiply matrix
  */
  // cout << "-- multiply --" << endl;
  // cout << "row: " << mul.size() << "   col: " << mul[0].size() << endl;
  // for (int i = 0; i < mul.size(); i++) {
  //   for (int j = 0; j < mul[i].size(); j++) {
  //     cout << mul[i][j] << "\t";
  //   }
  //   cout << endl;
  // }

  return mul;
}

// helper function, recursive
Matrix MatrixChain::rec_mul(int i, int j, Matrix K)
{
  if (i == j) {
    return chain[i];
  }
  else {
    int k = K[i][j];
    if (k < i) k = i;
    Matrix left = rec_mul(i, k, K);
    Matrix right = rec_mul(k+1, j, K);
    return multiply(left, right);
  }
}

Matrix MatrixChain::dynamicChain(){
  //implement here the optimal approach using the dynamic programming algorithm
  int inf = std::numeric_limits<int>::max(); // representing infinity with max value for int
  int n = chain.size();
  Matrix N(n, vector<int>(n, 0)); // holds min num of step
  Matrix K(n, vector<int>(n, 0)); // holds k value for optimal subdivision

  for (int i = 0; i < n; i++) {
    N[i][i] = 0;
    K[i][i] = 0;
  }

  for (int starting_entry = 1; starting_entry < n; starting_entry++) {
    for (int row = 0; row < n-starting_entry; row++) {
      int col = starting_entry + row;
      N[row][col] = inf;
      // find k
      for (int k = row; k < col; k++) {
        int cost = N[row][k] + N[k+1][col] + (dimensions[row]*dimensions[k+1]*dimensions[col+1]);
        if (cost < N[row][col]) {
          N[row][col] = cost;
          K[row][col] = k-row;
        }
      }
    }
  }
  cout << endl << "Minimum number of steps required for multiplying the chain of matrices: " << N[0][n-1] << endl;
  /*
    print optimal cost
  */
  // cout << endl << "-- N --" << endl;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << N[i][j] << "\t";
  //   }
  //   cout << endl;
  // }
  /*
    print k
  */
  // cout << endl << "-- K --" << endl;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << K[i][j] << "\t";
  //   }
  //   cout << endl;
  // }
  /*
    print matrices in chain
  */
  // cout << endl << "-- matrices --" << endl;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < chain[i].size(); j++) {
  //     for (int k = 0; k <chain[i][j].size(); k++) {
  //       cout << chain[i][j][k] << "\t";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }

  return rec_mul(0, n-1, K);
}