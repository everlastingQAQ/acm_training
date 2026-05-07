#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    map <array <int, 2>, int> mp;
    int c0 = 0, c1 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') c0++;
        else c1++;
        int x = c0 / gcd(c0, c1);
        int y = c1 / gcd(c0, c1);
        cout << ++mp[{x, y}] << " \n"[i == n - 1];
    }
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