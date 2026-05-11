#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e6;

bool vis[N];
i64 primes[N];
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

void solve ()
{
    int n;
    cin >> n;
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        i64 t = primes[idx++] * primes[idx];
        cout << t << " \n"[i == n];
    }
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    get_primes(1e6 - 10);
    while (_--) {
        solve();
    }
    return 0;
} 