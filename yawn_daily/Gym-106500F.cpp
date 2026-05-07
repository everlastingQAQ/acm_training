#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <vector <i64> > cnt(11, vector <i64> (11));
    vector <int> c(11);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            cnt[j][v[i]] += c[j];
        }
        c[v[i]]++;
    }

    vector <int> p(11);
    iota(p.begin() + 1, p.end(), 1);

    i64 ans = 1e18;
    do {
        i64 cur = 0;
        for (int i = 1; i <= 10; i++) {
            for (int j = i + 1; j <= 10; j++) {
                cur += cnt[p[j]][p[i]];
            }
        }
        ans = min(ans, cur);

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