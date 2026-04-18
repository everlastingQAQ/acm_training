#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int k = 1; k <= n; k++) {
        int op;
        cin >> op;
        if (op == 1) {
            string s1;
            cin >> s1;
            vector <int> ans;
            for (int i = 0; i <= s.size() - s1.size(); i++) {
                string t = s.substr(i, s1.size());
                if (t == s1) ans.push_back(i);
            }
            if (ans.empty()) {
                cout << -1 << '\n';
            }else if (ans.size() == 1) {
                cout << ans[0] << '\n';
            }else if (ans.size() == 2) {
                cout << ans[0] << ' ' << ans[1] << '\n';
            }else {
                cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
            }
        }else if (op == 2) {
            int pos;
            string s2;
            cin >> pos >> s2;
            string t;
            for (int i = 0; i < s.size(); i++) {
                if (i == pos) {
                    t = t + s2;
                }
                t = t + s[i];
            }
            if (pos == s.size()) {
                t = t + s2;
            }
            s = t;
            cout << s << '\n';
        }else {
            int l, r;
            cin >> l >> r;
            int len = r - l + 1;
            string tt = s.substr(l, len);
            if (!tt.empty()) reverse(tt.begin(), tt.end());
            string t;
            for (int i = 0; i < l; i++) {
                t = t + s[i];
            }
            t = t + tt;
            for (int i = r + 1; i < s.size(); i++) {
                t = t + s[i];
            }
            s = t;
            cout << s << '\n';
        }
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