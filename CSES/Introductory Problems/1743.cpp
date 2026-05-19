#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    vector <int> v(26);
    string s;
    cin >> s;
    for (char c : s) {
        v[c - 'A']++;
    }
    int cnt = s.size();
    int pre = -1;
    string ans;
    while (cnt > 0) {
        bool ok = false;
        for (int i = 0; i < 26; i++) {
            if (i == pre) continue;
            char c = 'A';
            if (v[i]) {
                pre = i;
                v[i]--;
                c = c + i;
                ok = true;
                ans = ans + c;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans;
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