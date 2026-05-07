#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    string ans;
    bool ok = false;
    string t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            ok = true;
            continue;
        }
        if (!ok) {
            ans.push_back(s[i]);
        }else {
            t.push_back(s[i]);
        }
    }
    if (t.front() >= '5') {
        ok = true;
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (ok) {
                ok = false;
                if (ans[i] == '9') {
                    ans[i] = '0';
                    ok = true;
                }else {
                    ans[i]++;
                }
            }else {
                break;
            }
        }
        if (ok) {
            ans = '1' + ans;
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