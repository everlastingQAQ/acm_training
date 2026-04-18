#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            string s1;
            cin >> s1;
            if (s.find(s1) != string::npos) {
                cout << s.find(s1) << '\n';
            }else {
                cout << -1 << '\n';
            }
        }else if (op == 2) {
            string s2, s3;
            cin >> s2 >> s3;
            if (s.find(s2) != string::npos) {
                s.replace(s.find(s2), s2.size(), s3);
            }
            cout << s << '\n';
        }else {
            char c1, c2;
            string s4;
            cin >> c1 >> c2 >> s4;
            string t;
            for (int i = 0; i < s.size() - 1; i++) {
                t = t + s[i];
                if (s[i] == c1 && s[i + 1] == c2) {
                    t = t + s4;
                }
            }
            if (!s.empty()) t = t + s.back();
            s = t;
            cout << s << '\n';
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