#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5;

bool vis[N];
int primes[N];//1-based
int cnt = 0;

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
    get_primes(10000);
}

void solve ()
{   
    int a, b; cin >> a >> b;
}   
    
int32_t main ()
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