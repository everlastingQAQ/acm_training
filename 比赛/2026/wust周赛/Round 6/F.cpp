#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    map <int, vector <int>, greater <int> > mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]].push_back(i);
    }
    vector <int> a(n + 1, 0), b(n + 1, 0);
    iota(a.begin(), a.end(), 0);
    iota(b.begin(), b.end(), 0);
    
    int mnp = 1e18, mxp = -1;

    for (auto [x, y] : mp) {
        for (auto p : y) {
            mnp = min(mnp, p);
            mxp = max(mxp, p);
        }
        for (auto p : y) {
            a[p] = mxp;
            b[p] = mnp;
        }
    }

    for (int i = 1; i <= n; i++) {
        int l1 = abs(i - a[i]);
        int l2 = abs(i - b[i]);
        if (l1 > l2) {
            cout << a[i] - 1 << ' ';
        }else if (l2 > l1) {
            cout << b[i] - 1 << ' ';
        }else {
            cout << min(a[i], b[i]) - 1 << ' ';
        }
    }

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