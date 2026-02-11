#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <array <int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    sort(v.begin() + 1, v.end(), [] (auto a, auto b) {
        return
    });
}   
    
int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;   
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