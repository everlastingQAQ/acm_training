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
    
    if (n <= 3) {
        cout << n - 1 << '\n';
        return;
    }

    int ans = 2;
    i64 l = 0, r = 0;
    if (v[3] - v[2] > v[2] - v[1]) {
        l = v[3] - v[2] - (v[2] - v[1]);
        r = v[3] - v[2];
    }else {
        l = 0;
        r = v[3] - v[2];
    }

    for (int i = 4; i <= n; i++) {
        i64 d = v[i] - v[i - 1];
        if (d <= l) {
            l = max(0LL, v[i] - v[i - 1] - (v[i - 1] - v[i - 2]));
            r = v[i] - v[i - 1];
        }else if (d > l && d < r) {
            ans++;
            r = d - l;
            l = 0;
        }else {
            ans++;
            i64 ll = l, rr = r;
            l = d - rr;
            r = d - ll;
        }
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