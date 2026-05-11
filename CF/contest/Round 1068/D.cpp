#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 998244353;
    
ll n, k;

void solve ()
{
    cin >> n >> k;
    bool found = false;
    vector <ll> v;
    for (int i = 31; i >= 0; i--) {
        if (!found) {
            ll t = (n >> i) & 1;
            if (t == 1) {
                found = true;
                v.push_back(i + 1);
            }
        }else {
            if (n & (1 << i)) {
                v.push_back(i + 1);
            }
        }
    }
    
    ll t = v[0] - v.size();
    sort(v.begin(), v.end());

    if (k <= t) {
        vector <ll> cnt;
        ll p = 1;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] - v[i] == 1) {
                p++;
            }else {
                if (t != 1) {
                    cnt.push_back(p);
                }
                p = 1;
            }
        }
        ll ans = 0;
        if (cnt.size() >= k) {
            for (int i = 0; i < k; i++) {
                ans += cnt[i];
            }
            cout << ans << '\n';
        }else {
            for (int i = 0; i < cnt.size(); i++) {
                ans += cnt[i];
            }
            cout << ans + (k - cnt.size()) << '\n';
        }
        return;
    }else {
        ll ans = v[v.size() - 1];
        ll mx = ans;
        if (t == 0) {
            
        }
        ans += (k - t) / t * mx;
        ll temp = (k - t) % t;
        ans += temp;
        cout << ans << '\n';
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