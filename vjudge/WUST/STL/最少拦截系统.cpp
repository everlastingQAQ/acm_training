#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

void solve ()
{
    while (cin >> n) {
        vector <ll> v(n);
        for (ll &i : v) {
            cin >> i;
        }

        vector <ll> rec;
        rec.emplace_back(v[0]);
        
        for (ll t : v) {
            bool found = false;
            for (ll &p : rec) {
                if (t <= p) {
                    found = true;
                    p = t;
                    break;
                }
            }
            if (!found) {
                rec.emplace_back(t);
            }
        }
        cout << rec.size() << '\n';
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