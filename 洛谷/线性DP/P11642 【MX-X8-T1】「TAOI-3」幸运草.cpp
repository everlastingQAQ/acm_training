#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{   
    int n, x;
    cin >> n >> x;
    vector <int> v(n + 1), a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
        a[i] = x - v[i];
    }

    vector <int> s(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = max(s[i - 1] + a[i], a[i]);
        mx = max(mx, s[i]);
    }

    cout << mx + sum << '\n';
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