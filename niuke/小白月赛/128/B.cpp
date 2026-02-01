#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3 + 5;

bool vis[N];
int primes[N], mnp[N];
int cnt = 0;
vector <vector<pair<int, int> > > v(N);

void get_factors ()
{
    mnp[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            primes[++cnt] = i;//1-based
            mnp[i] = i;
        }
        for (int j = 1; j <= cnt && i * primes[j] < N; j++) {
            vis[i * primes[j]] = 1;
            mnp[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;  
        }
    }

    for (int i = 1; i < N; i++) {
        int t = i;
        while (t > 1) {
            int p = mnp[t];
            int count = 0;
            while (t % p == 0) {
                t /= p;
                count++;
            }
            v[i].push_back({p, count});
        }
    }
}

void init ()
{
    get_factors();
}

void solve ()
{
    int n; cin >> n;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (v[t].size() <= 1) {
            ok = true;
        }
    }    
    cout << (ok ? "YES" : "NO") << '\n';
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