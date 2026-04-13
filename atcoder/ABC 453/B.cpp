#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int t, x;
    cin >> t >> x;
    int cnt = 0;
    int cur;
    cin >> cur;
    cout << cnt << ' ' << cur << '\n';
    int pre = cur;
    for (int i = 1; i <= t; i++) {
        cin >> cur;
        cnt++;
        if (abs(cur - pre) >= x) {
            cout << cnt << ' ' << cur << '\n';
            pre = cur;
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
