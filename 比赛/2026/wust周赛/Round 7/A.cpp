#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, x;
    cin >> n >> x;
    int sum = 0;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin() + 1, v.end());
    if (sum > x) {
        int cnt = 0;
        for (int i = n; i >= 1; i--) {
            sum -= v[i] + 1e4;
            cnt++;
            if (sum <= x) break;
        }
        cout << cnt << '\n';
    }else if (sum == x) {
        cout << 0 << '\n';
    }else {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            sum -= v[i] - 1e4;
            cnt++;
            if (sum >= x) break;
        }
        cout << cnt << '\n';
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