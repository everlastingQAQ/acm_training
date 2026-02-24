#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    int pa = 1, pb = 1;
    int cnt = 0;
    while (pa <= n && pb <= m) {
        if (a[pa] >= b[pb]) {
            pa++;
            pb++;
            cnt++;
            continue;
        }else {
            pa++;
        }
    }

    if (cnt >= m) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
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