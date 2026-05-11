#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.size() == 3 && s[0] != s[1] && s[1] != s[2] && s[0] != s[2]) {
        cout << "NO\n";
        return;
    }   
    for (auto c : s) {
        if (c != s[0]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int32_t main()
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