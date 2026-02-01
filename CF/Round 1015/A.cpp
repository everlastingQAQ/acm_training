#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n; cin >> n;
    if (n & 1) {
        cout << n << ' ';
        for (int i = 1; i < n; i++) {
            cout << i << " \n"[i == n - 1];
        }
    }else {
        cout << -1 << '\n';
    }
}   
    
int32_t main ()
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