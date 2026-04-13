#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    i64 x;
    cin >> n >> x;
    vector <i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    
    i64 cnt = 0;
    i64 ans = 0;
    int l = 1, r = n;
    i64 cur = 0;
    vector <int> res;
    while (l <= r) {
        while (l <= r && cur + v[r] >= (cnt + 1) * x) {
            res.push_back(v[l]);
            cur += v[l];
        }
        ans += v[r];
        r--;
        cnt++;
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