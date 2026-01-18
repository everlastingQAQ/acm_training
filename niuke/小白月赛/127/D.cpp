#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

void solve ()
{
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s; s = ' ' + s;
    
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'w') v[i] = 0;
        else if (s[i] == 'y') v[i] = 1;
        else v[i] = 2;
    }

    int l = 1, r = n;

    auto check = [&] (int md) -> bool {
        vector <int> cnt(3, 0);
        for (int i = 1; i <= md; i++) {
            cnt[v[i]]++;
        }
        int sum = min(m, cnt[0]) * 2 + max(cnt[1], cnt[2]) * 2 + min(cnt[1], cnt[2]);
        for (int i = md + 1; i <= n; i++) {
            cnt[v[i]]++;
            cnt[v[i - md]]--;
            sum = max(min(m, cnt[0]) * 2 + max(cnt[1], cnt[2]) * 2 + min(cnt[1], cnt[2]), sum);
        }

        return sum >= k;
    };

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }

    if (l == n + 1) {
        cout << -1 << '\n';
    }else {
        cout << l << '\n';
    }
}   
    
signed main ()
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