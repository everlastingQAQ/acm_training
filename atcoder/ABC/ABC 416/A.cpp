#include <bits/stdc++.h>
#include <ranges>
using namespace std;
using namespace std::views;
using namespace std::ranges;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n, l, r; cin >> n >> l >> r;
    string s; cin >> s;
    if (all_of(iota(l - 1, r), [&](int i) {
        return s[i] == 'o';
    })) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
    }
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