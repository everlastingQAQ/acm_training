#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;

ll n, k, ans = 0;
ll a[30];
vector<bool> isPrime;
vector <ll> Primes;

void find_primes() {
    isPrime.assign(MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) Primes.push_back(i);
        for (ll p : Primes) {
            if ((long long)i * p > MAXN) break;
            isPrime[i * p] = false;
            if (i % p == 0) break;
        }
    }
}

void dfs (ll sum, ll cnt, ll pos)
{

    if (cnt == k && isPrime[sum]) {
        ans++;
        return;
    }

    for (int i = pos; i <= n; i++) {
        dfs(sum + a[i], cnt + 1, i + 1);
    }
}

void solve ()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ans = 0;

    dfs(0, 0, 1);

    cout << ans <<  '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _; 
    find_primes();
    while (_--) {
        solve();
    }
    return 0;
}