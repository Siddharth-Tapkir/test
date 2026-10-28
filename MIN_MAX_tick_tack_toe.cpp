#include <iostream>
#include <algorithm>
using namespace std;

char board[3][3] = {
    {'X', 'O', 'X'},
    {'O', 'X', ' '},
    {' ', ' ', 'O'}
};

bool win(char p)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return true;

        if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return true;
    }

    if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return true;

    if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
        return true;

    return false;
}

bool full()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;

    return true;
}

int minimax(bool maximizing)
{
    if (win('X'))
        return 1;

    if (win('O'))
        return -1;

    if (full())
        return 0;

    if (maximizing)
    {
        int best = -1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'X';

                    best = max(best, minimax(false));

                    board[i][j] = ' ';
                }
            }
        }

        return best;
    }
    else
    {
        int best = 1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'O';

                    best = min(best, minimax(true));

                    board[i][j] = ' ';
                }
            }
        }

        return best;
    }
}

int main()
{
    int bestScore = -1000;
    int bestRow = -1, bestCol = -1;

    cout << "Initial Board:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }

    // Find best move for X
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'X';

                int score = minimax(false);

                board[i][j] = ' ';

                if (score > bestScore)
                {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }

    cout << "\nBest Move for X: ";
    cout << bestRow + 1 << ", " << bestCol + 1 << endl;

    cout << "Score: " << bestScore << endl;

    return 0;
}