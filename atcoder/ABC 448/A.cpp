#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t < x) {
            x = t;
            cout << 1 << '\n';
        }else {
            cout << 0 << '\n';
        }
    }
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