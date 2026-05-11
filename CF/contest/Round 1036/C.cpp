#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <int> a;
    for (int i = n - 1; i >= 1; i--) {
        if (v[i + 1] % v[i]) {
            a.push_back(v[i] / gcd(v[i], v[i + 1]));
        }
    }

    if (a.empty()) {
        cout << 1 << '\n';
    }else {
        int ans = a[0];
        for (int i = 1; i < a.size(); i++) {
            ans = lcm(ans, a[i]);
        }
        cout << ans << '\n';
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