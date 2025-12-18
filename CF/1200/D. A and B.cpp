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
    
ll n; 
string s;

void solve ()
{   
    cin >> n >> s;
    vector <ll> a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') a.push_back(i);
        else b.push_back(i);
    }

    auto found = [&] (vector <ll> v) -> ll {
        ll pos = v.size() / 2;
        ll ans = 0;
        for (int i = 0; i < v.size(); i++) {
            ans += abs(v[i] - v[pos]) - abs(pos - i);
        }
        return ans;
    };

    cout << min(found(a), found(b)) << '\n';
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