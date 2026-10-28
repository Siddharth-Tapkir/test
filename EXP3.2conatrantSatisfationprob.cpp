#include <iostream>
#include <string>
#include <vector>
using namespace std;

string words[10];
int n;

int value[26];
bool used[10];

// Convert word into its number
long long getValue(string word)
{
    long long num = 0;

    for (char ch : word)
    {
        num = num * 10 + value[ch - 'A'];
    }

    return num;
}

// Check if the current assignment is valid
bool check()
{
    // First letters cannot be zero
    for (int i = 0; i < n - 1; i++)
    {
        if (value[words[i][0] - 'A'] == 0)
            return false;
    }

    long long sum = 0;

    // Add all words except the last one
    for (int i = 0; i < n - 1; i++)
        sum += getValue(words[i]);

    // Last word is the answer
    long long answer = getValue(words[n - 1]);

    return sum == answer;
}

// Backtracking
bool solve(int letter)
{
    // All letters assigned
    if (letter == 26)
    {
        return check();
    }

    // Skip unused letters
    while (letter < 26 && value[letter] != -1)
        letter++;

    if (letter == 26)
        return check();

    for (int digit = 0; digit <= 9; digit++)
    {
        if (!used[digit])
        {
            value[letter] = digit;
            used[digit] = true;

            if (solve(letter + 1))
                return true;

            // Backtrack
            value[letter] = -1;
            used[digit] = false;
        }
    }

    return false;
}

int main()
{
    cout << "Enter number of words: ";
    cin >> n;

    cout << "\nEnter words:\n";

    for (int i = 0; i < n; i++)
        cin >> words[i];

    // Initialize
    for (int i = 0; i < 26; i++)
        value[i] = -1;

    for (int i = 0; i < 10; i++)
        used[i] = false;

    // Solve
    if (solve(0))
    {
        cout << "\nSolution Found!\n\n";

        // Print letter values
        for (int i = 0; i < 26; i++)
        {
            if (value[i] != -1)
                cout << char('A' + i)
                     << " = " << value[i] << endl;
        }

        cout << "\nEquation:\n";

        for (int i = 0; i < n; i++)
        {
            cout << getValue(words[i]);

            if (i < n - 2)
                cout << " + ";
            else if (i == n - 2)
                cout << " = ";
        }

        cout << endl;
    }
    else
    {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}