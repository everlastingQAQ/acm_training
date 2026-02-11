#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point {
    int x, y;  
};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > v(n + 1, vector <int> (m + 1));
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            sum += v[i][j];   
        }
    }

    int t = sum / 2;
    cout << t * (sum - t) << '\n';

    int tt = 0;
    bool ok = false;
    point p;

    for (int j = m; j >= 1; j--) {
        for (int i = 1; i <= n; i++) {
            tt += v[i][j];
            if (tt >= t) {
                p.x = i;
                p.y = j;
                ok = true;
                break;
            }
        }
        if (ok) break;
    }

    cout << string(p.y - 1, 'R') << string(p.x, 'D') << 'R' << string(max(0LL, n - p.x), 'D') << string(max(0LL, m - p.y), 'R') << '\n';

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