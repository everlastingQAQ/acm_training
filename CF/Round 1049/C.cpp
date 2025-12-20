#include <bits/stdc++.h>
using namespace std;
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
    ll n; cin >> n;
    vector <ll> v(n + 1);
    vector <ll> s(n + 1);
    ll base = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] = 2 * v[i] - i;
        if (i & 1) {
            base += v[i];
        }else {
            base -= v[i];
        }
    }

    ll mx = LLONG_MIN, mn = LLONG_MAX;
    ll posmx = 0, posmn = 0; 
    for (int i = 1; i <= n; i++) {
        if ((i & 1) && s[i] < mn) {
            mn = s[i];
            posmn = i;
        }else if (!(i & 1) && s[i] > mx) {
            mx = s[i];
            posmx = i;
        } 
    }   

    ll t1 = 2 * (v[posmx] - v[posmn]) + abs(posmx - posmn);
    ll ans = base;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, base + (i - (i & 1)));
    }

    cout << max(ans, base + t1) << '\n';
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