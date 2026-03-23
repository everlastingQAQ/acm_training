#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int m, q;
    cin >> m >> q;
    vector <int> cnt(m + 1, 0);
    int cur = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int t;
            cin >> t;
            if (t - 3 >= 1) {
                cnt[t - 3]++;
                if (cnt[t - 3] == 1) cur++;
            }
            if (t + 3 <= m) {
                cnt[t + 3]++;
                if (cnt[t + 3] == 1) cur++;
            }
        }else {
            int t;
            cin >> t;
            if (t - 3 >= 1) {
                cnt[t - 3]--;
                if (cnt[t - 3] == 0) cur--;
            }
            if (t + 3 <= m) {
                cnt[t + 3]--;
                if (cnt[t + 3] == 0) cur--;
            }
        }
        cout << cur << '\n';
    }
} 
    
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
} 