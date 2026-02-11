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

    sort(a.begin() + 1, a.end(), greater<>());
    sort(b.begin() + 1, b.end(), greater<>());

    int ans = 0;
    int l = 1, r = 1;
    while (l <= n && r <= m) {
        if (a[l] <= b[r]) {
            r++;
            l++;
            ans++;
        }else {
            l++;
        }
    }

    cout << ans;
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