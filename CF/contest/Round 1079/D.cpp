#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    int len = sqrt(n) + 1;
    for (int i = 1; i <= n; i++) {
        int t = min(len, (i - 1) / v[i]);
        for (int j = 1; j <= t; j++) {
            if (v[i - j * v[i]] == j) {
                ans++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] <= len) continue;
        int t = min(len, (n - i) / v[i]);
        for (int j = 1; j <= t; j++) {
            if (v[i + v[i] * j] == j) ans++;
        }
    }

    cout << ans << '\n';

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

/*
  /\_/\
 (= ._.)
 / >  \>
*/