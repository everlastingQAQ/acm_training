#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n; cin >> n;
    vector <int> v(n + 1);
    int mn = 1e11;
    int mx = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] >= 2 * mn && i != 1) {
            ok = false;
        }
        mn = min(mn, v[i]);
    }

    cout << (ok == false ? "NO" : "YES") << '\n';
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