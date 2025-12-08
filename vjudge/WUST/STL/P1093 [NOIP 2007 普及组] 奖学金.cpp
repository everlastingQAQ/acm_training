#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

struct grades {
    ll p;
    ll chinese;
    ll math;
    ll english;
    ll sum;
};

bool cmp (const grades &a, const grades &b)
{
    if (a.sum != b.sum) {
        return a.sum > b.sum;
    }
    if (a.chinese != b.chinese) {
        return a.chinese > b.chinese;
    }else {
        return a.p < b.p;
    }
}

void solve ()
{
    cin >> n;

    grades g[n + 1];
    for (ll i = 1; i <= n; i++) {
        cin >> g[i].chinese >> g[i].math >> g[i].english;
        g[i].p = i;
        g[i].sum = g[i].chinese + g[i].math + g[i].english;        
    }

    sort(g + 1, g + n + 1, cmp);

    for (ll i = 1; i <= 5; i++) {
        cout << g[i].p << ' ' << g[i].sum << endl;
    }

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