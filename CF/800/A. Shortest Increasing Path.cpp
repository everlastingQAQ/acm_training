#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        if (x == y || x == y + 1 || y == 1) {
            cout << -1 << endl;
            continue;
        }else if (x < y) {
            cout << 2 << endl;
            continue;
        }else if (x > y + 1) {
            cout << 3 << endl;
            continue;
       }
    }

    return 0;
}