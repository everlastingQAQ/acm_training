#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

ll n, k;    

void solve ()
{
    cin >> n >> k;
    vector <ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll st = v[k - 1];

    sort(v.begin(), v.end());
    ll pos;

    for (int i = 0; i < n; i++) {
        if (v[i] == st) {
            pos = i;
            break;
        }
    }

    ll t = 1;
    set <ll> a;
    for (int i = pos; i < n; i++) {
        a.insert(v[i]);
    }

    // for (auto it = a.begin(); it != a.end(); it++) {
    //     cout << *it << ' ';
    // }
    // cout << '\n';
    
    for (auto it = a.begin(); it != a.end(); it++) {
        if (it == a.end()) break;
        auto nxt = next(it);
        // cout << *it << ' ' << *nxt << ' ' << *it - t << '\n';
        if (*nxt - *it > *it - t + 1) {
            cout << "No" << '\n';
            return;
        }else {
            t += *nxt - *it;
        }
    }
    cout << "Yes" << '\n';
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