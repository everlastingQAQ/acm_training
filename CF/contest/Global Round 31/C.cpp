#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 n, k;
    cin >> n >> k;

    if (k & 1) {
        for (int i = 1; i <= k; i++) {
            cout << n << " \n"[i == k];
        }
        return;
    }

    vector <i64> vis(k + 1, 0);
    queue <int> q;
    for (int i = 1; i <= k; i++) {
        q.push(i);
    }
    vector <i64> ans(k + 1);
    int cnt = 0;
    bool ok = false;

    for (int i = 30; i >= 0; i--) {
        if (n >> i & 1) {
            for (int j = 1; j <= k; j++) {
                ans[j] |= (1LL << i);
            }
            if (!ok) {
                int t = q.front();
                q.pop();
                if (q.empty()) {
                    ok = true;
                    for (int i = 1; i <= k; i++) {
                        q.push(i);
                    }
                }
                ans[t] ^= (1LL << i);
                vis[t] = true;
                cnt++;
            }else {
                if (q.empty()) {
                    for (int i = 1; i <= k; i++) {
                        q.push(i);
                    }
                }
                for (int i = 1; i <= k; i++) {
                    q.push(i);
                }
                int t = q.front();
                q.pop();
                ans[t] ^= (1LL << i);
            }
        }else {
            for (int j = 1; j <= cnt - 1; j++) {
                ans[j] |= (1LL << i);
            }
            if (!(cnt & 1)) {
                ans[cnt] |= (1LL << i);
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        cout << ans[i] << " \n"[i == k];
    }
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