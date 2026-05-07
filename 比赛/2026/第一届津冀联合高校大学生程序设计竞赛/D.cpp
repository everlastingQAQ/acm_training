#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    string s;
    cin >> n >> s;
    map <char, int> mp;
    int mx = 0;
    for (auto c : s) {
        mp[c]++;
        mx = max(mx, mp[c]);
    }
    cout << n - mx << '\n';
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