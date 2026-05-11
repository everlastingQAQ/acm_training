#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        int t = mp[v[i]];
        while (t % 2 == 0) t /= 2;
        while (v[i] % 2 == 0) v[i] /= 2;
        if (t != v[i]) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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