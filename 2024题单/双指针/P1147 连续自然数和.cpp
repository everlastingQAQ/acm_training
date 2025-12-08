#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll m;

void solve ()
{
    cin >> m;

    ll l = 1, r = 1;
    ll sum = 1;

    while (l + r <= m) {
        //cout << l << ' ' << r << '\n';
        if (sum < m) {
            r++;
            sum += r;
        }else if (sum == m) {
            cout << l << ' ' << r << '\n';
            sum -= l;
            l++;
        }else if (sum > m) {
            sum -= l;
            l++;
        }
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