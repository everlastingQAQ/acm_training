#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) {
            if (i == 1) v[i] = v[2];
            else if (i == n) v[i] = v[n - 1];
            else v[i] = v[i - 1] * v[i + 1];
            ans++;
        }
    }

    for (int i = 2; i < n; i++) {
        if (v[i] == 1) continue;
        if (gcd(v[i - 1], v[i]) == 1) {
            v[i] = v[i - 1] * v[i + 1];
            ans++;
        }
    }

    if (v[n] != 1 && gcd(v[n], v[n - 1]) == 1) ans++;

    cout << ans << '\n';
}   
    
int main ()
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