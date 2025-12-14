#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 1e7;
const double eps = 1e-5;
const ll mod = 998244353;
    
vector <bool> vis(MAXN + 1, false);
vector <ll> prime(MAXN + 1);
ll cnt = 0;

void get_prime (ll n)
{
    for (ll i = 2; i <= n; i++) {
        if (!vis[i]) prime[++cnt] = i;
        for (ll j = 1; i * prime[j] <= n; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

ll n;

void solve ()
{
    cin >> n;
    ll sum = 0, sump = 0;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum += v[i];
        sump += prime[i];
    }

    if (sum >= sump) {
        cout << 0 << '\n';
    }else {
        sort(v.begin() + 1, v.end(), greater<ll>());
        ll ans = 0;
        for (int i = n; i >= 1; i--) {
            sump -= prime[i];
            sum -= v[i];
            ans++;
            if (sum >= sump) break;
        }
        cout << ans << '\n';
    }
}
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    get_prime(MAXN);
    while (_--) {
        solve();
    }
    return 0;
}