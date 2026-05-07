#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int l = 0, r = 0;
    int op = 0;
    while (r < n) {
        if (s[r] == 'a') op = 0;
        else op = 1;
        while (r < n && ((s[r] == 'a' && op == 0) || (s[r] == 'h' && op == 1))) {
            r++;
            op ^= 1;
        }
        ans = max(ans, r - l);
        if (s[r] != 'a' && s[r] != 'h') r++;
        l = r;
    }
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