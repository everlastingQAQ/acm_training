#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    if ((n & (n - 1)) == 0) {
        cout << -1 << '\n';
        return;
    }

    if (n & 1) {
        cout << n - 1 << ' ';
        for (int i = 2; i < n - 1; i += 2){
            cout << i + 1 << ' ' << i << ' ';
        }
        cout << n << ' ' << 1 << '\n';
        return;
    }

    int x = n & -n;

    cout << x << ' ';
    for (int i = 2; i < n; i += 2) {
        cout << (i + 1 == x ? n : i + 1) << ' ' << (i == x ? n : i) << ' ';
    }
    cout << 1 << '\n';
}   
    
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 