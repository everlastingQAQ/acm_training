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
                
void solve ()
{
    cin >> n;
    vector <ll> a;
    vector <ll> b;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        ll t;
        cin >> t;
        sum += t;
        if (t & 1) {
            a.push_back(t);
        }else {
            b.push_back(t);
        }
    }

    vector <ll> ans(n);
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    
    if (a.size() == 0) {
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }else if (b.size() == 0) {
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                cout << 0 << ' ';
            }else {
                cout << a[0] << ' ';
            }
        }
        cout << '\n';
        return;
    }

    ans[0] = a[0];
    for (int i = 0; i < b.size(); i++) {
        ans[i + 1] = ans[i] + b[i];
    }

    for (int i = b.size() + 1; i < n; i++) {
        ans[i] = ans[i - 2];
    }

    if (!(sum & 1)) {
        ans[n - 1] = 0;
    }

    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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