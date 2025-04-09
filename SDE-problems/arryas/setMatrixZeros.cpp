#include <iostream>
#include <vector>

using namespace std;

void setmatrixrixZerosBF(vector<vector<int>> &matrix)
{
    /*
    Time Complexity

    Two for loops (n*m)
    Two replce function (n+m)
    Two for loops replace -1 with 0 (n*m)

    Total: nm * (n+m) + nm

    Space: O(1)

    */
    int m = matrix.size();
    int n = matrix[0].size();
    int MARKER = -1;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 0)
            {
                // mark the row
                for (int k = 0; k < n; ++k)
                {
                    if (matrix[i][k] != 0 && matrix[i][k] != MARKER)
                        matrix[i][k] = MARKER;
                }
                // mark the col
                for (int k = 0; k < m; ++k)
                {
                    if (matrix[k][j] != 0 && matrix[k][j] != MARKER)
                        matrix[k][j] = MARKER;
                }
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == MARKER)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void setMatrixZerosBetter(vector<vector<int>> &matrix)
{
    /*
    Time Complexity

    Two main for loops: m*n

    Space: (m+n)
    */

    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m, 0);
    vector<int> col(n, 0);

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void setMatrixZeroesOptimized(vector<vector<int>> &matrix)
{
    // Time Complex: O(m*n)
    // Space: O(1)
    int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowHasZero = false, firstColHasZero = false;

    // check is 1st row has zero
    for (int j = 0; j < n; ++j)
    {
        if (matrix[0][j] == 0)
        {
            firstRowHasZero = true;
        }
    }

    // check if 1st col has zero
    for (int i = 0; i < m; ++i)
    {
        if (matrix[i][0] == 0)
        {
            firstColHasZero = true;
        }
    }

    // use first row/col to mark zeros
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // set cells based on markers
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Zero out first row if needed
    if (firstRowHasZero)
        for (int j = 0; j < n; ++j)
            matrix[0][j] = 0;

    // Zero out first column if needed
    if (firstColHasZero)
        for (int i = 0; i < m; ++i)
            matrix[i][0] = 0;
}

// Utility to print matrix
void printMatrix(const vector<vector<int>> mat)
{
    for (const auto &row : mat)
    {
        for (int val : row)
            cout << val << " ";
        cout << '\n';
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 1}};

    cout << "Before:\n";
    printMatrix(mat);

    // setmatrixrixZerosBF(mat);
    // setMatrixZerosBetter(mat);
    setMatrixZeroesOptimized(mat);

    cout << "\nAfter:\n";
    printMatrix(mat);
}