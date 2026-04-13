#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	string s;
    cin >> s;
    i64 ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        i64 t = s[i] - '0';
        i64 x = (t - ans + 100) % 10;
        if (x < 0) x += 10;
        ans += x;
    }
    ans += s.size();
    cout << ans << '\n';
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
