#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e5 + 10;

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

void solve ()
{
    int n;
    cin >> n;
    vector <int> ans(n + 1);
    iota(ans.begin() + 1, ans.end(), 1);
    for (int i = 1; i <= n; i++) {
        if (primes[i] > n) break;
        int cnt = 0;
        for (int j = primes[i]; j <= n; j += primes[i]) {
            cnt++;
        }
        int t = primes[i] + primes[i];
        bool ok = false;
        for (int j = primes[i]; j <= n; j += primes[i]) {
            if (t > n) {
                if (ok) {
                    break;
                }
                t = primes[i];
                ok = true;
            }
            ans[j] = t;
            t += primes[i];          
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
} 
    
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    get_primes(N);
    while (_--) {
        solve();
    }
    return 0;
} 