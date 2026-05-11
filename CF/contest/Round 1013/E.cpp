#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e7;
const double eps = 1e-5;
const int mod = 1e9 + 7;

bool vis[N + 1];
int primes[N + 1];//1-based
int cnt = 0;
int prevP[N + 1];
int pi[N + 1];

void get_primes (int n)
{
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) primes[++cnt] = i;
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++) {
            vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

void init ()
{
    get_primes(N);
    int last = -1;
    for (int i = 2; i <= N; ++i) {
        if (!vis[i]) last = i;
        prevP[i] = last;
    }
    for (int i = 2; i <= N; ++i) {
        pi[i] = pi[i - 1] + (!vis[i] ? 1 : 0);
    }
}

void solve ()
{
    // cout << pi[2] << '\n';
    int n; cin >> n;
    int ans = 0;
    int t = 1;
    int x = prevP[n];
    while (t < n) {
        // cout << x << ' ' << pi[x] << '\n';
        ans += pi[x];
        t++;
        x = prevP[n / t];
    }
    cout << ans << '\n';
}   
    
signed main ()
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