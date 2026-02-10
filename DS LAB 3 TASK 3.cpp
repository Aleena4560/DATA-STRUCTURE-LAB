#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    cout << "==========| MATRIX |==========" <<endl;
    cout << endl;
    // Ask user for number of rows and columns
    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    // Create pointer-to-pointer for 2D array
    int** matrix = new int*[rows];

    // Allocate memory for each row
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    // Input elements of the matrix
    cout << "\nEnter matrix elements:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Display the matrix
    cout << "\nMatrix is:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Free the allocated memory (delete each row first)
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    // Delete main pointer
    delete[] matrix;

    // Set pointer to nullptr for safety
    matrix = nullptr;

    return 0;
}
