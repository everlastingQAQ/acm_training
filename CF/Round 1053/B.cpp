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
const ll inf = LLONG_MAX;

ll n, m;
string s;

void solve ()
{
    cin >> n >> m >> s;
    set <ll> v;
    for (int i = 0; i < m; i++) {
        ll t;
        cin >> t;
        v.insert(t);
    }

    ll t = 1;
    for (int i = 0; i < n; i++) {
        t++;
        if (s[i] == 'A') {
            v.insert(t);
        }else if (s[i] == 'B') {
            while (v.count(t)) {
                t++;
            }
            v.insert(t);
            while (v.count(t)) {
                t++;
            }
        }   
    }
    
    cout << v.size() << '\n';
    for (auto x : v) {
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