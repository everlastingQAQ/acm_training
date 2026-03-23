#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, m, t;
    cin >> n >> m >> t;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < t) {
            ans += t - x;
        }
    }
    cout << (ans <= m ? ans : -1) << '\n';
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