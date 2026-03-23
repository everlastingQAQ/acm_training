#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    double t;
    cin >> t;
    cout << fixed << setprecision(10);
    cout << acos(-1) * (t / 2) * (t / 2) << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 
