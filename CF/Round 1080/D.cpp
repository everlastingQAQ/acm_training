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

    vector <int> ans(n + 1);
    int val = (v[1] + v[n]) / (n - 1);
    for (int i = 2; i <= n - 1; i++) {
        ans[i] = (v[i + 1] + v[i - 1] - 2 * v[i]) / 2;
        val -= ans[i];
    }
    
    int cur = v[2] - v[1];
    for (int i = 2; i <= n - 1; i++) {
        cur += ans[i];
    }
    
    ans[1] = (val + cur) / 2;
    ans[n] = (val - cur) / 2;
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/