#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, m, k;

void solve ()
{
    cin >> n >> m >> k;
    vector <ll> hd(n);
    vector <ll> bd(m);

    for (int i = 0; i < n; i++) {
        cin >> hd[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> bd[i];
    }
    sort(hd.begin(), hd.end());
    sort(bd.begin(), bd.end());

    ll cnt = 0;

    ll l = 0, r = 0;

    while (l < n && r < m) {
        if (hd[l] <= bd[r]) {
            cnt++;
            l++;
            r++;
        }else {
            r++;
        }
        if (cnt == k) {
            break;
        }
    }

    if (cnt == k) {
        cout << "Yes" << '\n';
    }else {
        cout << "No" << '\n';
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