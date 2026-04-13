#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int N = 2e7 + 1;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

bool isprime[N];
int prime[N], mnp[N];
ll cnt = 0;

void get_mn_prime_factor ()
{
    mnp[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!isprime[i]) {
            prime[cnt++] = i;
            mnp[i] = i;
        }
        for (int j = 0; j < cnt && i * prime[j] < N; j++) {
            isprime[i * prime[j]] = true;
            mnp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

void solve ()
{
    ll n; cin >> n;

    auto check = [&] (int x) -> bool {
        ll t = x;
        while (t != 1) {
            ll p = mnp[t];
            ll cnt = 0;
            while (t % p == 0) {
                t /= p;
                cnt++;
            }                               
            if (p % 4 == 3 && cnt & 1) {
                return false;
            }
        }
        if ((ll)sqrtl(x) * (ll)sqrtl(x) == x) return false;//特判
        else return true;
    };

    cout << (check(n) ? "Yes" : "No") << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    get_mn_prime_factor();
    while (_--) {
        solve();
    }
    return 0;
}   