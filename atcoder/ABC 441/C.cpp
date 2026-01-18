#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, k, x; cin >> n >> k >> x;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    ranges::sort(v | views::drop(1), greater<int>());
    
    int sum = 0;
    int cnt = 0;
    for (int i = n - k + 1; i <= n; i++) {
        sum += v[i];
        cnt++;
        if (sum >= x) {
            cout << cnt + n - k << '\n';
            return;
        }
    }

    cout << -1 << '\n'; 

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