#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

struct node
{
    string s;
    ll cnt;
};

void solve ()
{
    ll n, p, k; cin >> n >> p >> k;
    node nd[n];
    ll sum = 0;
    map <string, ll> mp;

    for (int i = 0; i < n; i++) {
        cin >> nd[i].s >> nd[i].cnt; 
        mp[nd[i].s] = nd[i].cnt;
        sum += nd[i].cnt;
    }

    ll mn = 1e15;
    for (int i = 0; i < k; i++) {
        string s; cin >> s;
        mn = min(mn, mp[s]);
    }

    if (mn * p < sum) {
        cout << -1 << '\n';
    }else {
        cout << (sum + p - 1) / p << ' ' << mn << '\n';
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