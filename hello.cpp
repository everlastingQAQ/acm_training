#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s;
    cin >> s;

    string p = "SCMU";
    int n = s.size();
    int m = p.size();
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        pi[i] = j;
    }

    int ans = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            j++;
        }
        if (j == m) {
            ans++;
            j = pi[j - 1];
        }
    }

    cout << ans << '\n';
}   

int32_t main ()
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