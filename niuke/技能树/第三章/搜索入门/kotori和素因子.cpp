#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define fi first
#define se second

const int N = 1e4;

bool vis[N];
int primes[N], mnp[N];
int cnt = 0;
vector <vector<int> > v(N);

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
            v[i].push_back(p);
        }
    }
}

void solve ()
{
    int n; cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector <vector <int> > sav(n + 1);

    for (int i = 1; i <= n; i++) {
        for (auto x : v[a[i]]) {
            sav[i].push_back(x);
        }
    }

    int ans = 1e11;
    vector <int> rec;
    auto dfs = [&] (int idx, int sum, auto self) -> void {
        if (idx == n) {
            for (auto x : sav[idx]) {
                if (!ranges::count(rec, x)) {
                    ans = min(sum + x, ans);
                }
            }
            return;
        }
        
        for (auto x : sav[idx]) {
            if (!ranges::count(rec, x)) {
                rec.push_back(x);
                sum += x;
                self(idx + 1, sum, self);
                rec.pop_back();
                sum -= x;
            }
        }
    };

    dfs(1, 0, dfs);

    cout << (ans == 1e11 ? -1 : ans) << '\n';
    
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