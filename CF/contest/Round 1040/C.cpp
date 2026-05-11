#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const int mod = 998244353;

void solve ()
{
    int n; cin >> n;
    vector <array<int, 2> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (v[i][0] >= v[j][0] && v[i][1] <= v[j][1]) {
                found = true;
                break;
            }
        }
        if (!found) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }

}   
    
signed main ()
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