
#include <iostream>
#include <algorithm>
using namespace std;

char board[9] = {
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' '
};

// Check winner
bool win(char p)
{
    int w[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for(int i = 0; i < 8; i++)
    {
        if(board[w[i][0]] == p &&
           board[w[i][1]] == p &&
           board[w[i][2]] == p)
            return true;
    }

    return false;
}

// Check if board is full
bool full()
{
    for(int i = 0; i < 9; i++)
        if(board[i] == ' ')
            return false;

    return true;
}

// Minimax
int minimax(bool aiTurn)
{
    if(win('O')) return 1;
    if(win('X')) return -1;
    if(full()) return 0;

    if(aiTurn)
    {
        int best = -1000;

        for(int i = 0; i < 9; i++)
        {
            if(board[i] == ' ')
            {
                board[i] = 'O';

                best = max(best, minimax(false));

                board[i] = ' ';
            }
        }

        return best;
    }
    else
    {
        int best = 1000;

        for(int i = 0; i < 9; i++)
        {
            if(board[i] == ' ')
            {
                board[i] = 'X';

                best = min(best, minimax(true));

                board[i] = ' ';
            }
        }

        return best;
    }
}

// Find AI's best move
int bestMove()
{
    int best = -1000;
    int move = -1;

    for(int i = 0; i < 9; i++)
    {
        if(board[i] == ' ')
        {
            board[i] = 'O';

            int score = minimax(false);

            board[i] = ' ';

            if(score > best)
            {
                best = score;
                move = i;
            }
        }
    }

    return move;
}

// Print board
void print()
{
    cout << "\n";
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---------\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---------\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

int main()
{
    cout << "TIC TAC TOE\n";
    cout << "You = X, AI = O\n";

    while(true)
    {
        print();

        int pos;
        cout << "\nEnter position (1-9): ";
        cin >> pos;
        pos--;

        if(pos < 0 || pos >= 9 || board[pos] != ' ')
        {
            cout << "Invalid move!\n";
            continue;
        }

        // Human move
        board[pos] = 'X';

        if(win('X'))
        {
            print();
            cout << "\nYou Win!\n";
            break;
        }

        if(full())
        {
            print();
            cout << "\nDraw!\n";
            break;
        }

        // AI move
        int move = bestMove();
        board[move] = 'O';

        cout << "AI chose: " << move + 1 << endl;

        if(win('O'))
        {
            print();
            cout << "\nAI Wins!\n";
            break;
        }

        if(full())
        {
            print();
            cout << "\nDraw!\n";
            break;
        }
    }

    return 0;
}