#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int N = 1e6 + 1;

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

void solve ()
{
    for (auto [x, y] : v[677]) {
        cout << x << ' ' << y << '\n'; 
    }
}

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    get_factors();
    while (_--) {
        solve();
    }
    return 0;
}   