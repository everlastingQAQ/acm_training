#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, k;
bool pd[100];
ll ans[100];

void print ()
{
    for (ll i = 0; i < n; i++) {
        cout << setw(5) << ans[i];
    }
    cout << endl;
}

void dfs (ll k)
{
    if (k == n) {
        print();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!pd[i]) {
            ans[k] = i;
            pd[i] = true;
            dfs(k + 1);
            pd[i] = false;
        }
    }
}

void solve ()
{
    cin >> n;
    dfs(0);
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}