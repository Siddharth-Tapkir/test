#include <iostream>
#include <cmath>
using namespace std;

// Check if queen can be placed safely
bool isSafe(int board[], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        // Same column
        if (board[i] == col)
            return false;

        // Same diagonal
        if (abs(board[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

// Solve N-Queen
bool solve(int board[], int row, int n)
{
    // All queens placed
    if (row == n)
        return true;

    // Try every column
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            // Place queen
            board[row] = col;

            // Move to next row
            if (solve(board, row + 1, n))
                return true;

            // Backtrack
            board[row] = -1;
        }
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter value of N: ";
    cin >> n;

    int board[20];

    // Initially no queens
    for (int i = 0; i < n; i++)
        board[i] = -1;

    if (solve(board, 0, n))
    {
        cout << "\nSolution Found:\n\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}