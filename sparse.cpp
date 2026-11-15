#include <iostream>
using namespace std;
// This was messy sorry in advance sir

#define MAX 10

int main() 
{
    int matrix[MAX][MAX];
    int sparse[MAX * MAX + 1][3];   // [row, col, value]
    int rows, cols;

    cout << "Enter number of rows and columns: (Add space in between the values)";
    cin >> rows >> cols;

    cout << "Enter the matrix elements: (One at a time and press enter)\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
          {
            cin >> matrix[i][j];
          }
    }
    // Row 0 of the sparse array stores these..: total rows, total columns, non-zero count
    int k = 1;   // next free row in the sparse array
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;   // number of non-zero elements

    cout << "\nOriginal matrix:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
          {
            cout << matrix[i][j] << "\t";
          }
        cout << "\n";
    }

    cout << "\nSparse representation (triplet form):\n";
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i < k; i++)
      {
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << "\n";
      }
    return 0;
}
