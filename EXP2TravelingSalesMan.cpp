/*#include <iostream>
using namespace std;

int main()
{
    // Cost Matrix
    int cost[4][4] =
    {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int minCost = 99999;

    cout << "Possible Tours:\n\n";

    // Start city is always 0 (A)
    for(int i = 1; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            if(j == i)
                continue;

            for(int k = 1; k < 4; k++)
            {
                if(k == i || k == j)
                    continue;

                int totalCost = cost[0][i] + cost[i][j] + cost[j][k] + cost[k][0];

                cout << "A -> " << char('A'+i) << " -> " << char('A'+j) << " -> " << char('A'+k) << " -> A";

                cout << " = " << totalCost << endl;

                if(totalCost < minCost)
                    minCost = totalCost;
            }
        }
    }

    cout << "\nMinimum Cost = " << minCost << endl;

    return 0;
}
    */

    #include <iostream>
using namespace std;

const int MAX = 10;

int n;
int cost[MAX][MAX];

// Function to calculate total tour cost
int calculateCost(int path[])
{
    int total = 0;

    for(int i = 0; i < n - 1; i++)
        total += cost[path[i]][path[i + 1]];

    total += cost[path[n - 1]][path[0]]; // Return to starting city

    return total;
}

// Display path
void displayPath(int path[])
{
    for(int i = 0; i < n; i++)
        cout << path[i] << " -> ";

    cout << path[0];
}

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "\nEnter Cost Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int path[MAX];

    cout << "\nEnter Initial Tour (Example: 0 1 2 3):\n";

    for(int i = 0; i < n; i++)
        cin >> path[i];

    int currentCost = calculateCost(path);

    cout << "\nInitial Tour: ";
    displayPath(path);

    cout << "\nInitial Cost = " << currentCost << endl;

    bool improved = true;

    while(improved)
    {
        improved = false;

        for(int i = 1; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                // Swap two cities
                int temp = path[i];
                path[i] = path[j];
                path[j] = temp;

                int newCost = calculateCost(path);

                if(newCost < currentCost)
                {
                    currentCost = newCost;
                    improved = true;

                    cout << "\nBetter Tour Found:\n";
                    displayPath(path);
                    cout << "\nCost = " << currentCost << endl;
                }
                else
                {
                    // Undo swap
                    temp = path[i];
                    path[i] = path[j];
                    path[j] = temp;
                }
            }
        }
    }

    cout << "\n\nFinal Optimal Tour:\n";
    displayPath(path);

    cout << "\nMinimum Cost = " << currentCost << endl;

    return 0;
}

 