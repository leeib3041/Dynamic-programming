#include "matrixChain.h"

#define MATRIX 100

int main()
{
    MatrixChain chain = MatrixChain(MATRIX);
    chain.printDimensions();
    Matrix K = chain.dynamicChain();
    
    /*
        print final matrix
        in matrixChain.cpp - uncomment line 51 if negative values print. 
                             Reason for this is in lines 46-50
        in matrixChain.h - uncomment lines 37-38
    */
    // int row = chain.get_row();
    // int col = chain.get_col();
    // cout << endl << "-- answer --" << endl;
    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //     cout << K[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    return 0;
}