#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    vector <vector <int> > pos(4);
    vector <int> cnt(4);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]].push_back(i);
        cnt[v[i]]++;
    }

    vector <int> p(4);
    iota(p.begin() + 1, p.end(), 1);

    i64 ans = 1e18;
    do {
        i64 cur = 0;
        for (int i = 1; i <= cnt[p[1]]; i++) {
            if (v[i] != p[1]) cur++;
        }
        for (int i = cnt[p[1]] + 1; i <= cnt[p[1]] + cnt[p[2]]; i++) {
            if (v[i] != p[2]) cur++;
        }
        for (int i = n; i > cnt[p[1]] + cnt[p[2]]; i--) {
            if (v[i] != p[3]) cur++;
        }
        // cout << cur << '\n';
        ans = min(ans, cur / 2);

    }while (next_permutation(p.begin() + 1, p.end()));

    cout << ans << '\n';
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