# Dynamic Programming
In this assignment, you will implement the dynamic programming solution to the matrix chain multiplication problem.

All the information you need regarding dynamic programming can be found in your textbook (Algorithm Design and Applications, Chapter 12).

### Step 1 - Setup
You can create your own `main.cpp` file for debugging your implementation.
Other than that your implementation will be limited to `matrixChain.cpp`. You should always be able to compile everything with something simple like: `c++ *.cpp -o main`

Take your time to understand the structure of these files.
- `matrixChain.h` is a class that stores the actual chain of matrices.
- `chain` stores the matrices (each Matrix is a bidimensional vector) while `dimensions` stores the sizes of these matrices.
- as we have seen in class, the matrix at position i in `chain` has number of rows = `dimensions[i]` and number of columns = `dimensions[i+1]`.

The constructor of the class `ChainMatrix` takes as input an integer `num` that indicate the number of matrices to be generated. By calling the constructor a sequence of `num` matrices will be generated with random sizes. `#define NUM ...` indicates the maximum value for each entry of a matrix. `#define SIZE ...` indicates the maximum size for the dimension of a matrix.

Two functions are already implemented the constructor `MatrixChain` and `generate_matrix`. These are creating the vector of dimensions and the matrices for you. They use a random function so that the matrix will change every time. You can decide to create the matrices manually at first, for testing your algorithm under simpler conditions, or you can change the parameters `num`, `NUM` and `SIZE` to create smaller matrices


### Step 3 - Dynamic programming approach, minimum number of steps

As a firs step let's implement function `DynamicChain`. Here you should implement the algorithm discussed in class. This will compute the matrix N storing the minimum number of steps required for multiplying the chain of matrices.

Once completed, print the last value computed in the matrix (the one telling you the optimal solution).

### Step 4 - Dynamic programming approach, subdivision.

Let's extend the previous function now. Modify the algorithm so to compute the matrix K storing all the k values describing how to get to the optimal solution.
Once you have created the matrix K, return the matrix.

### Step 5 - Wrapping up and constructing the final main.cpp file

Create your final main.cpp file. Your main function should contain only the following code.

```c++
MatrixChain chain = MatrixChain(100);
chain.printDimensions();
Matrix K = chain.dynamicChain();

return 0;
```

Run your last experiment with parameters
```c++
#define NUM 100 //maximum value for a cell of the matrix
#define SIZE 100 //maximum dimension for rows/columns of a matrix
```

Update this README file, copy and paste the results printed by your program. This should contain, the list of dimensions as printed by the function `chain.printDimensions();` and the optimal solution as printed by `chain.dynamicChain();`

        [UPDATE HERE]
        
        {8,50,74,59,31,73,45,79,24,10,41,66,93,43,88,4,28,30,41,13,4,70,10,58,61,34,100,79,17,36,98,27,13,68,11,34,80,50,80,22,68,73,94,37,86,46,29,92,95,58,2,54,9,45,69,91,25,97,31,4,23,67,50,25,2,54,78,9,29,34,99,82,36,14,66,15,64,37,26,70,16,95,30,2,18,96,6,5,52,99,89,24,6,83,53,67,17,38,39,45,2}

        Minimum number of steps required for multiplying the chain of matrices: 433254


### Step 5 BONUS - Complete the dynamic programming multiplication

Now that you have the matrix K we know what is the correct order for applying our matrix multiplications. So let's do this.

Start by implementing the function `Matrix multiply(Matrix a, Matrix b);` in `MatrixChain` that, given two matrices, returns their multiplication.

Then, modify function `dynamicChain()` again. This time, instead of returning K, use K for computing the matrix multiplications in the optimal sequence. Then, return the matrix obtained instead of returning K.

        Completed