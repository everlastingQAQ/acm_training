#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <string> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] = ' ' + v[i];
    }
    vector <i64> a(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == '1') a[j]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        i64 p = 0;
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == '0') {
                p += a[j];
            }else {
                p += n - a[j];
            }
        }

        i64 mx = 0;
        i64 cur = 0;
        for (int j = 1; j <= m; j++) {
            i64 val = 0;
            if (v[i][j] == '0') {
                val = 2 * a[j] - n + 1;
            }else {
                val = n - 2 * a[j] + 1;
            }
            cur += val;
            if (cur < 0) {
                cur = 0;
            }
            mx = max(mx, cur);
        }

        cout << p - mx << '\n';
    }
}   
    
int main ()
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