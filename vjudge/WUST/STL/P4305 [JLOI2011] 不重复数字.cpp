#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    map <ll, ll> mp;
    vector <ll> ans;
    ll t;
    
    for (int i = 1; i <= n; i++) {
        cin >> t;
        if (mp.count(t) == 0) {
            mp[t] = i;
            ans.push_back(t);
        }
    }

    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << endl;
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