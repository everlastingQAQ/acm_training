#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1), b(m + 1);
    int mx = -1;
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        mx = max(a[i], mx);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        mx = max(b[i], mx);
    }
    // sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end(), greater<>());

    vector <int> cnt(mx + 1);
    for (int i = 1; i <= n; i++) {
        map <int, int> mpp;
        for (int j = 1; j <= m; j++) {
            int t = gcd(a[i], b[j]);
            if (mpp[t]) continue;
            mpp[t] = true;
            cnt[t]++;
        }
    }

    int mn = 1e9;
    for (int i = 1; i <= mx; i++) {
        // cout << cnt[i] << ' ';
        if (cnt[i] >= n) {
            mn = min(mn, n - mp[i]);
        }
    }
    cout << (mn == 1e9 ? -1 : mn) << '\n';
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