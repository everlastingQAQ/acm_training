#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        if (a % 3 == 0) cout << 0 << endl;
        if (a % 3 == 1) cout << 2 << endl;
        if (a % 3 == 2) cout << 1 << endl;
    }

    return 0;
}