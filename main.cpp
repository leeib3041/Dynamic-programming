#include "matrixChain.h"

int main()
{
    MatrixChain chain = MatrixChain(3);
    chain.printDimensions();
    Matrix K = chain.dynamicChain();

    return 0;
}