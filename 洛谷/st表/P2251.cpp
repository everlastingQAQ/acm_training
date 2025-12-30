#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve1 ()
{
    ll n, m; cin >> n >> m;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector <vector <ll> > st(n + 1, vector <ll> (30));
    ll t = log2(n);
    for (int i = 1; i <= n; i++) st[i][0] = v[i];

    for (int j = 1; j <= t; j++) {
        for (int i = 1; i <= n - (1LL << j) + 1; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
        }
    }

    ll q = n - m + 1;
    ll l = 1, r = m;
    ll len = log2(m);
    while (q--) {
        cout << min(st[l][len], st[r - (1LL << len) + 1][len]) << '\n';
        l++, r++;
    }
}   

void solve2 ()
{
    ll n, m; cin >> n >> m;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    deque <ll> dq;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && v[i] <= v[dq.back()]) dq.pop_back();
        while (!dq.empty() && i - dq.front() >= m) dq.pop_front();
        dq.push_back(i);
        if (i >= m) cout << v[dq.front()] << "\n";
    }
}
 
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve2();
    }
    return 0;
}