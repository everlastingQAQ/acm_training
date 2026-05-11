#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    double a1, b1;
    cin >> a1 >> b1;
    double maxium1 = max(a1, b1);
    double minium2 = min(a1, b1);
    if ((maxium1 - 2) / 2 > minium2) {
        cout << "NO" << endl;
        cin >> a1 >> b1;
        return;
    }
    double a2, b2;
    cin >> a2 >> b2;
    a2 -= a1;
    b2 -= b1;
    double maxium3 = max(a2, b2);
    double minium4 = min(a2, b2);
    if ((maxium3 - 2) / 2 > minium4) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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