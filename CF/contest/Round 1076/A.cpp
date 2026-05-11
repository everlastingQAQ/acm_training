#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, s, x; cin >> n >> s >> x;
    vector <int> v(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i]; sum += v[i];
    }

    int t = s - sum;
    if (t < 0) {
        cout << "NO" << '\n';
        return;
    }else if (t == 0) {
        cout << "YES" << '\n';
        return;
    }

    if (t % x == 0) {
        cout << "YES" << '\n';
    }else {
        cout << "NO" << '\n';
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