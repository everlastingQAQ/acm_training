#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
    
ll n, k;

void solve ()
{   
    cin >> n >> k;
    vector <ll> v(n);
    map <ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    ll tag = n;
    for (int i = 0; i <= n; i++) {
        if (mp[i] == 0) {
            tag = i;
            break;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > tag || mp[v[i]] > 1) {
            v[i] = tag;
            cnt++;
        }
    }

    if (k & 1) {
        cout << accumulate(v.begin(), v.end(), 0LL) << '\n';
    }else {
        cout << accumulate(v.begin(), v.end(), 0LL) + cnt << '\n';
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