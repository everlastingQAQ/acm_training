#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

string s;

void solve ()
{
    cin >> s;
    ll ans1 = 0;
    ll ans2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y') {
            ans1++;
        }
        if (s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l') {
            ans2++;
        }
    }
    cout << ans1 << '\n';
    cout << ans2 << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}