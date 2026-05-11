#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

void solve ()
{   
    ll x, k; cin >> x >> k;
    if (k == 1) {
        if (x == 1) {
            cout << "No" << '\n'; 
            return;
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                cout << "No" << '\n';
                return;
            }
        }
        cout << "Yes" << '\n';
    }else {
        if (x == 1 && k == 2) {
            cout << "Yes" << '\n';
        }else {
            cout << "No" << '\n';
        }
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