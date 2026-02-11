#include <bits/stdc++.h>
using namespace std;
// #define int long long

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1);
    map <int, int> mp;
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        mx = max(mx, v[i]);
    }

    if (!(mp[mx] & 1)) {
        for (int i = 1; i <= n; i++) {
            if (v[i] == mx) cout << 0;
            else cout << 1;
        }
        cout << '\n';
    }else {
        for (int i = 1; i <= n; i++) {
            if (v[i] == mx) cout << 1;
            else cout << 0;
        }
        cout << '\n';
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