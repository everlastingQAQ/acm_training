#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    cin >> n;
    ll ans1, ans2, a, b, ans;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (i == 0) {
            ans1 = a;
            ans2 = b;
            continue;
        }
        if (a != ans1 && b != ans1) {
            ans = ans2;
        }else if (a != ans2 && b != ans2) {
            ans = ans1;
        }
    }

    cout << ans << '\n';
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