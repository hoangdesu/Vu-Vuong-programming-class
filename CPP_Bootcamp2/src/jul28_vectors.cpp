#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void print_grid(vector<vector<char>> &zoo_grid)
{
    for (auto row : zoo_grid)
    {
        for (auto element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    std::srand(0); // fixed seed

    vector<vector<char>> zoo_grid;

    int rows, cols, koalas, tigers;

    cin >> rows >> cols >> koalas >> tigers;

    if (rows * cols < koalas + tigers) 
    {
        cout << "Not enough room!" << endl;
        return EXIT_FAILURE;
    }

    // init an empty grid
    for (int i = 0; i < rows; i++) 
    {
        vector<char> row;
        for (int j = 0; j < cols; j++)
        {
            row.push_back('-');
        }
        zoo_grid.push_back(row);
    }

    for (int k = 0; k < koalas; k++) 
    {
        int randomRowIndex = rand() % rows;
        int randomColIndex = rand() % cols;

        while (zoo_grid[randomRowIndex][randomColIndex] != '-')
        {
            randomRowIndex = rand() % rows;
            randomColIndex = rand() % cols;
        }

        zoo_grid[randomRowIndex][randomColIndex] = 'K';
    }

    for (int t = 0; t < tigers; t++) 
    {
        int randomRowIndex = rand() % rows;
        int randomColIndex = rand() % cols;

        while (zoo_grid[randomRowIndex][randomColIndex] != '-')
        {
            randomRowIndex = rand() % rows;
            randomColIndex = rand() % cols;
        }

        zoo_grid[randomRowIndex][randomColIndex] = 'T';
    }

    print_grid(zoo_grid);

    return EXIT_SUCCESS;
}
