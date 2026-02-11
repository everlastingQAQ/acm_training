#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m; cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    map <char, int> mp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            mp[v[i][j]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[v[i][j]] > 1) cout << "Y";
            else cout << "N";
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