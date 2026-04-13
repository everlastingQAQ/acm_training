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
    
    auto cal = [&] (i64 x) -> i64 {
        i64 res = 0;
        while (x > 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    };

    int ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        while (v[i] > 9 && v[i] > v[i + 1]) {
            v[i] = cal(v[i]);
            ans++;
        }
        if (v[i] > v[i + 1]) {
            cout << -1 << '\n';
            return;
        }
    }   

    cout << ans << '\n';
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 