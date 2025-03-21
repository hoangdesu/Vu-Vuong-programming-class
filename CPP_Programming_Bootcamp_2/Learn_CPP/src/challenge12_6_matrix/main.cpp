#include <iostream>
#include "matrix.h"

int main() {
    // /**
    // This code is provided as a starting point for development and testing
    //  * Please modify the code below as you develop your program.
    //  * It will NOT BE USED to test your code
    //  * **/

    std::vector<std::vector<int>> mat1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> mat2 = {{7, 8}, {9, 10}, {11, 12}};
    std::vector<std::vector<int>> result = multiplyMatrices(mat1, mat2);

    std::cout << "Resulting matrix:" << std::endl;
    for (const auto &row : result)
    {
        for (int elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}