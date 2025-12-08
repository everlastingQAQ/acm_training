#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll m, n;

void solve ()
{
    cin >> m >> n;
    queue <ll> q;
    vector <bool> v(1001, false);

    ll t;
    ll ans = 0;
    while (n--) {
        cin >> t;
        if (!v[t]) {
            if (q.size() < m) {
                q.push(t);
                v[t] = true;
            }else if (q.size() == m) {
                v[q.front()] = false;
                q.pop();
                q.push(t);
                v[t] = true;
            }
            ans++;
        }else {
            continue;
        }
    }

    cout << ans << endl;
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