#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector <array <string, 2> > v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    vector <int> a(m);
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == v[i][1][j]) {
                cnt++;
            }
        }
        a[i] = cnt;
    }

    int mx = *max_element(a.begin(), a.end());

    vector <string> ans;
    for (int i = 0; i < m; i++) {
        if (a[i] == mx) {
            ans.push_back(v[i][0]);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans[0] << '\n';
    cout << fixed << setprecision(2) << 100.0 * mx / n << '\n';
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