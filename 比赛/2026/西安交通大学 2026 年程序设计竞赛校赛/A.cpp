#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    cout << (sum == 3 ? "Congratulations on graduation!" : "Songfes in Japan...");
}   

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   