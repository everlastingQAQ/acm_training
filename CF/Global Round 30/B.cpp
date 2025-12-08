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
    vector <ll> a;
    vector <ll> b;

    ll t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t % 2 == 0) {
            a.push_back(t);
        }else if (t % 2 == 1){
            b.push_back(t);
        }
    }

    if (!b.empty() && b[0] == 1) {
        if (b.size() >= 2) {
            cout << 1 << ' ' << b[1] << '\n';
            return;
        }else if (!a.empty()) {
            cout << 1 << ' ' << a[0] << '\n';
            return;
        }
    }

    
    if (a.size() >= 2) { 
        cout << a[0] << ' ' << a[1] << '\n'; 
        return;
    }
    if (a.size() == 1) {
        for (int i = 0; i < b.size(); i++) {
            ll mx = max(a[0], b[i]);
            ll mn = min(a[0], b[i]);
            if ((mx % mn) % 2 == 0) {
                cout << mn << ' ' << mx << '\n';
                return;
            }
        }
    }

    if (b.size() < 2) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < b.size(); i++) {
        for (int j = i + 1; j < b.size(); j++) {
            if ((b[j] % b[i]) % 2 == 0) {
                cout << b[i] << ' ' << b[j] << '\n';
                return;
            }
        }
    }

    cout << -1 << '\n';
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