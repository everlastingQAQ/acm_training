#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int a, b;
    cin >> a >> b;

    if (a < b) swap(a, b);
    if (a == b) {
        cout << 0 << endl;
        return;
    }else if (a % b != 0) {
        cout << 2 << endl;
        return;
    }else {
        cout << 1 << endl;
    }
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