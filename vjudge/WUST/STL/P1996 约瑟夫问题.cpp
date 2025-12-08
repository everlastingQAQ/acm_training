#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m;

void solve ()
{
    cin >> n >> m;
    queue <ll> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    ll cnt = 1;
    while (!q.empty()) {
        while (cnt != m) {
            cnt++;
            q.push(q.front());
            q.pop();
        }
        if (cnt == m) {
            cout << q.front() << ' ';
            q.pop();
            cnt = 1;
        }
    }

    return;
    
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