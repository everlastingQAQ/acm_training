#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;

bool vis[N];
int primes[N], mnp[N];
int cnt = 0;
vector <vector <int> > v(N);

void get_factors ()
{
    mnp[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            primes[++cnt] = i;
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
            v[i].push_back(p);
        }
    }
}

void solve ()
{
    int n;
    cin >> n;
    vector <int> b(n + 1);
    int mx = 0;
    bool ok = false;
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != 1) ok = true;
        for (auto x : v[b[i]]) {
            mp[x]++;
            mx = max(mx, mp[x]);
        }
    }

    if (!ok) {
        cout << -1 << '\n';
        return;
    }

    int ans = n - mx;
    cout << ans << '\n';
}   

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    get_factors();
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}   