#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    int n, k; cin >> n >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <int> pre(n + 2);
    for (int i = 1; i <= n; i++) {
        pre[i + 1] = max(pre[i], (v[i] == 0 ? 0 : min(n + 1, v[i] + i + 1)));
    }

    auto check = [&] (int x) -> bool {
        int idx = 1;
        while (idx <= n && v[idx] == 0) idx++;
        for (int i = 1; i <= k && idx <= n; i++) {
            idx++;
            for (int j = 1; idx <= n && j <= x && pre[idx] > idx; j++) {
                idx = pre[idx];
            }
            while (idx <= n && v[idx] == 0) idx++;
        }
        return idx == n + 1;
    };

    int l = 0, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }

    cout << (l == n + 1 ? -1 : l) << '\n';
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