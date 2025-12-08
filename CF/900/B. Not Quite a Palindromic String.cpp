#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, k;
string s;

void solve ()
{
    cin >> n >> k >> s;
    ll cnt_0 = 0, cnt_1 = 0;
    for (char i : s) {
        if (i == '0') {
            cnt_0++;
        }else if (i == '1') {
            cnt_1++;
        }
    }

    ll mx = max(cnt_0, cnt_1);
    ll mn = min(cnt_0, cnt_1);

    while (k--) {
        if (mx < mn) {
            swap(mx, mn);
        }
        mx -= 2;
    }

    if (mn == mx) {
        cout << "YES" << '\n';
    }else {
        cout << "NO" << '\n';
    }

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