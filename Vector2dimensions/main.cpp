#include <iostream>
#include <vector>

// 2d vectors ( matrix ) --> using vector of vectors
// vector[i][j] --> [fila][columna]
int main()
{

    std::vector<std::vector<int>> grid(3, std::vector<int>(4, 7)); // matrix of 3 rows and 4 columns

    // print the matrix

    for(int row = 0; row < grid.size(); row++) {
        for(int col = 0; col < grid[row].size(); col++) {
            std::cout << grid[row][col] << std::endl;
        }
        std::cout << "new row" << std::endl;
    }

    return 0;
}