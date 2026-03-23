#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, s, t;
    cin >> n >> s >> t;
    i64 sum = 0;
    vector <array <i64, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        i64 p, c, w;
        cin >> p >> c >> w;
        v[i][0] = p - c;
        v[i][1] = w;
        sum += w;
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