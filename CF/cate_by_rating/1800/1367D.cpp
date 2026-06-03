#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve ()
{
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    int m;
    cin >> m;
    vector <int> v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
    }

    vector <int> cnt(26);
    for (int i = 1; i <= n; i++) {
        cnt[s[i] - 'a']++;
    }
    int pos = 25;
    for (int i = 25; i >= 0; i--) {
        if (cnt[i]) {
            pos = i;
            break;
        }
    }

    vector <char> ans(m + 1, '?');
    while (pos >= 0) {
        vector <int> p0;
        for (int i = 1; i <= m; i++) {
            if (v[i] == 0 && ans[i] == '?') p0.push_back(i);
        }
        while (pos >= 0 && cnt[pos] < p0.size()) {
            pos--;
        }
        char c = 'a' + pos;
        for (auto p : p0) {
            ans[p] = c;
        }
        for (auto p : p0) {
            for (int i = p - 1; i >= 1; i--) {
                v[i] -= p - i;
            }
            for (int i = p + 1; i <= m; i++) {
                v[i] -= i - p;
            }
        }
        // for (int i = 1; i <= m; i++) {
        //     cout << v[i] << ' ';
        // }cout << '\n';
        cnt[pos] = 0;
        while (pos >= 0 && !cnt[pos]) {
            pos--;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i];
    }
    cout << '\n';
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