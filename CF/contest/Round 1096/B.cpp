#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    int c0 = 0, c1 = 0;
    string s;
    cin >> s;
    for (auto c : s) {
        if (c == '(') c0++;
        else c1++;
    }
    cout << (c0 == c1 ? "YES\n" : "NO\n");
}

int main ()
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