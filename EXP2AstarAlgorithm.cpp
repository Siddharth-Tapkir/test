#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    vector<vector<char>> state;
    int g, h, f;
};

// Count misplaced tiles
int heuristic(vector<vector<char>> state,vector<vector<char>> goal)
{
    int h = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (state[i][j] != '_' &&
                state[i][j] != goal[i][j])
            {
                h++;
            }
        }
    }

    return h;
}

// Find blank position
pair<int, int> findBlank(vector<vector<char>> state)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (state[i][j] == '_')
                return {i, j};
        }
    }

    return {-1, -1};
}

// Print puzzle
void printState(vector<vector<char>> state)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << state[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    vector<vector<char>> start(3, vector<char>(3));
    vector<vector<char>> goal(3, vector<char>(3));

    cout << "Enter Initial State:\n";

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];

    cout << "\nEnter Goal State:\n";

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> goal[i][j];

    vector<Node> open;

    Node startNode;
    startNode.state = start;
    startNode.g = 0;
    startNode.h = heuristic(start, goal);
    startNode.f = startNode.g + startNode.h;

    open.push_back(startNode);

    cout << "\nSolution:\n\n";

    while (!open.empty())
    {
        // Find node with smallest f
        int best = 0;

        for (int i = 1; i < open.size(); i++)
        {
            if (open[i].f < open[best].f)
                best = i;
        }

        Node current = open[best];

        // Remove selected node
        open.erase(open.begin() + best);

        cout << "g = " << current.g
             << " h = " << current.h
             << " f = " << current.f << endl;

        printState(current.state);
        cout << endl;

        // Goal reached
        if (current.state == goal)
        {
            cout << "Goal State Reached!" << endl;
            break;
        }

        // Find blank
        pair<int, int> blank = findBlank(current.state);

        int x = blank.first;
        int y = blank.second;

        // Four possible moves
        int moves[4][2] =
        {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        for (int k = 0; k < 4; k++)
        {
            int nx = x + moves[k][0];
            int ny = y + moves[k][1];

            // Check valid move
            if (nx >= 0 && nx < 3 &&
                ny >= 0 && ny < 3)
            {
                Node child;

                child.state = current.state;

                // Move blank
                swap(child.state[x][y],
                     child.state[nx][ny]);

                child.g = current.g + 1;
                child.h = heuristic(child.state, goal);
                child.f = child.g + child.h;

                open.push_back(child);
            }
        }
    }

    return 0;
}