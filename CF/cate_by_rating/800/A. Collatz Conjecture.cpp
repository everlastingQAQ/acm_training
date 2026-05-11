#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int k, x;
    cin >> k >> x;

    for (int i = 0; i < k; i++) {
        int y = (x - 1) / 3;
        if ((x - 1) % 3 == 0 && y % 2 == 1) {
            x = y;
        }else {
            x *= 2;
        }
    }

    cout << x << endl;

}

int main ()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}