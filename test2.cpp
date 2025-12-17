#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ld, ld>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;
const ll MAX = 1e9;

void solve ()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int & i : a){
        cin >> i;
    }
    for(int & i : b){
        cin >> i;
    }
    ll mx = 0, mn = 0, t;
    for(int i = 0; i < n; i ++) {
        t = mx;
        mx = max(mx - a[i], b[i] - mn);
        mn = min(mn - a[i], b[i] - t);
    }
    cout << mx << endl;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}