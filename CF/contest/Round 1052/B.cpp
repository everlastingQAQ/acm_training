#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, char>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

ll n, m;

void solve ()
{
    cin >> n >> m;
    vector <vector<ll> > v(n);
    map <ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            ll p;
            cin >> p;
            mp[p]++;
            v[i].push_back(p);
        }
    }

    for (int i = 1; i <= m; i++) {
        if (mp[i] == 0) {
            cout << "No" << '\n';
            return;
        }
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        bool found = true;
        for (auto x : v[i]) {
            // cout << x << ' ';
            if (mp[x] < 2) {
                found = false;
                break;
            }
        }
        if (found) {
            cnt++;
        }
    }
    
    if (cnt >= 2) {
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
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}