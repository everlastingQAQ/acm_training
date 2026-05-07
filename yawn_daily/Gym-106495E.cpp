#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e6 + 5;

bool vis[N];
int primes[N], mnp[N];
int cnt = 0;
vector <vector<int> > v(N);

void get_factors (int n)
{
    mnp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            primes[++cnt] = i;//1-based
            mnp[i] = i;
        }
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++) {
            vis[i * primes[j]] = 1;
            mnp[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;  
        }
    }

    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t > 1) {
            int p = mnp[t];
            int count = 0;
            while (t % p == 0) {
                t /= p;
                count++;
                v[i].push_back(p);
            }
        }
    }
}

void solve ()
{
    int n, q;
    cin >> n >> q;
    get_factors(n);

    vector <int> ans(n + 1);
    iota(ans.begin() + 1, ans.end(), 1);

    sort(ans.begin() + 1, ans.end(), [&] (int x, int y) {
        return v[x] < v[y];
    });

    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}   
    
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}