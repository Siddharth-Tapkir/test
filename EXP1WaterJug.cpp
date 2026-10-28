#include <iostream>
using namespace std;

int main()
{
    int cap1, cap2, target;
    int j1 = 0, j2 = 0;
    int step = 1;

    cout << "Enter capacity of Jug1: ";
    cin >> cap1;

    cout << "Enter capacity of Jug2: ";
    cin >> cap2;

    cout << "Enter target amount for Jug1: ";
    cin >> target;

    if (target > cap1 && target > cap2)
    {
        cout << "No way to measure the exact amount of water." << endl;
        return 0;
    }

    cout << "\nInitial State: J1 = 0, J2 = 0\n";

    while (j1 != target)
    {
        
        if (j2 == 0)
        {
            j2 = cap2;
            cout << "Step " << step++
            << ": Fill Jug2           -> J1 = " << j1
            << ", J2 = " << j2 << endl;
        }
        
        else if (j1 == cap1)
        {
            j1 = 0;
            cout << "Step " << step++
            << ": Empty Jug1          -> J1 = " << j1
            << ", J2 = " << j2 << endl;
        }
        
        else
        {
            int transfer;

            if (j2 < (cap1 - j1)) // J2 has lesswater than J1 IE j2 = 2 j1 = 1 total j1cap = 4 space in j1 is 3
                transfer = j2;    // transfer
            else
                transfer = cap1 - j1; // transfer enough to fill the jug

            j2 -= transfer;
            j1 += transfer;

            cout << "Step " << step++<< ": Pour Jug2 into Jug1 -> J1 = "<< j1 << ", J2 = " << j2 << endl;
        }
    }

    cout << "\nGoal Achieved!" << endl;
    cout << "Final State: J1 = " << j1
         << ", J2 = " << j2 << endl;

    return 0;
}