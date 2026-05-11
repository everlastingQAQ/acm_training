#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n;
    cin >> n;
    i64 ans = 1;

    i64 t = n;
    vector <i64> v;
    for (int i = 2; i * i <= n; i++) {
        if (t % i == 0) {
            v.push_back(i);
            while (t % i == 0) {
                t /= i;
            }
        }
    }

    if (t > 1) {
        v.push_back(t);
    }

    for (auto x : v) {
        ans *= x;
    }

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