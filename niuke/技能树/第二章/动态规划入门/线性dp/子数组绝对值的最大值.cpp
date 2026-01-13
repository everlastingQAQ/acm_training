#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n; cin >> n;
    vector <int> v(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i], s[i] = s[i - 1] + v[i];
    cout << *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()) << '\n';
}   
    
signed main ()
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