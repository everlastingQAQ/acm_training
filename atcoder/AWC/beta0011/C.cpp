#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, k;
    cin >> n >> k;
    vector <i64> v(n + 1);
    i64 cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 0) cnt++;
    }

    if (k == 0) {
        if (cnt == 0) {
            cout << -1 << '\n';
        }else {
            cout << cnt << '\n';
        }
        return;
    }
    
    vector <i64> pos;
    unordered_map <i64, int> mp;
    for (int i = 63; i >= 0; i--) {
        if (k >> i & 1) {
            pos.push_back(i);
            mp[i] = true;
        }
    }

    i64 ans = 0;
    unordered_map <i64, int> mpp;
    for (int i = 1; i <= n; i++) {
        i64 t = v[i];
        bool ok = true;
        for (int j = 63; j >= 0; j--) {
            if (t >> j & 1) {
                if (!mp[j]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            ans++;
            for (int j = 63; j >= 0; j--) {
                if (t >> j & 1) {
                    mpp[j] = 1;
                }
            }
        }
    }

    for (auto [x, y] : mp) {
        if (y == 1) {
            if (mpp[x] != y) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    
    cout << ans << '\n';
}   
    
int main ()
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