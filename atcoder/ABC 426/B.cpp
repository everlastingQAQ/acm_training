#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
const ll inf = LLONG_MAX;

string s;

void solve ()
{
    cin >> s;
    map <char, ll> mp;
    char a, b;
    a = s[0];
    int cnt = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != a) {
            b = s[i];
            cnt++;
        }
    }

    if (cnt > 1) {
        cout << a << '\n';
    }else {
        cout << b << '\n';
    }
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