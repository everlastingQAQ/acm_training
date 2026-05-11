#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, h, l; cin >> n >> h >> l;
    vector <int> v(n);
    for (int &x : v) cin >> x;

    int t = 0;
    int cnt = 0;
    if (l < h) swap(l, h);
    for (int i = 0; i < n; i++) {
        if (v[i] > min(l, h) && v[i] <= max(l, h)) t++;
        if (v[i] <= max(l, h)) cnt++; 
    }

    if (t <= cnt - t) {
        cout << cnt / 2 << '\n';
    }else {
        cout << cnt - t << '\n';
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