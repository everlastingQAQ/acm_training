#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<string, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void init() 
{

}

void solve ()
{
    ll n; string s; cin >> n >> s;
    ranges::reverse(s);
    vector <ll> v;
    ll l = 1, r = n;
    ll idx = 0;
    while (idx < n - 1) {
        if (s[idx] == '>') v.push_back(r--);
        else v.push_back(l++);
        idx++;
    }
    v.push_back(l);
    ranges::reverse(v);
    for (auto x : v) cout << x << ' ';
    cout << '\n';
}   

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    init();
    while (_--) {
        solve();
    }
    return 0;
}