#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, k, g;

void solve ()
{
    while (cin >> n) {
        if (n == 0) {
            break;
        }else {
            map <ll, ll> mp;
            mp[1000000000] = 1;
            for (int i = 1; i <= n; i++) {
                ll a, b;
                cin >> a >> b;
                mp[b] = a;
                
                ll ans = 0;
                auto it = mp.find(b);
                if (it != mp.begin()) {
                    auto jt = it;
                    jt--;
                    it++;
                    if (b - jt->fi <= it->fi - b) {
                        ans = jt->se;
                    }else {
                        ans = it->se;
                    }
                }else {
                    ans = (++it)->se;
                }

                cout << a << ' ' << ans << '\n';

            }
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