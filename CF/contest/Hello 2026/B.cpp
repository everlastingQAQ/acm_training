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
    ll n, k; cin >> n >> k;
    vector <ll> v(n + 1);
    map <ll, ll> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }

    ll mx = 0;
    ll cnt = 0;
    bool found = false;
    for (int i = 0; i <= n; i++) {
        if (!found && !mp[i]) {
            found = true;
            mx = i;
        }else if (!found && mp[i]) {
            cnt += mp[i] - 1;
        }else if (found) {
            cnt += mp[i];
        }
    }

    ll t = n - k + 1;
    cout << mx - max(t - cnt, 0LL) << '\n';
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