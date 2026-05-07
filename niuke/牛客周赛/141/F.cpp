#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;

    vector <vector <int> > pos(26);
    vector <vector <i64> > pre(26), prp(26);
    for (int i = 1; i <= n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
        int m = pos[i].size();
        pre[i].assign(m + 1, 0);
        prp[i].assign(m + 1, 0);
        for (int j = 0; j < m; j++) {
            pre[i][j + 1] = pre[i][j] + pos[i][j];
            i64 cur = 1LL * j * pos[i][j] - pre[i][j] - j;
            prp[i][j + 1] = prp[i][j] + cur;
        }
    }

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        if (x == 1) {
            cout << r - l + 1 << '\n';
        }else if (x == 2) {
            i64 ans = 0;
            for (int i = 0; i < 26; i++) {
                i64 cur = pre[r][i] - pre[l - 1][i];
                ans += cur * (cur - 1) / 2;
            }
            cout << ans << '\n';
        }else if (x == 3) {
            i64 ans = 0;
            for (int i = 0; i < 26; i++) {
                
            }
            cout << ans << '\n';
        } 

    }
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