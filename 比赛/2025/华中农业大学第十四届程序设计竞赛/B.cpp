#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;
using pii = pair<pi, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 1e9 + 7;

ll n, m, sx, sy, q;

int dx[5] = {0, 0, -1, 0, 1};
int dy[5] = {0, 1, 0, -1, 0};

void solve ()
{
    cin >> n >> m >> sx >> sy;
    vector <pi> v(m + 1);
    vector <ll> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> v[i].fi >> v[i].se;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
             
    cin >> q;
    vector <pair<char, char> > b(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> b[i].fi >> b[i].se;
    }

    auto check1 = [&] (ll x, ll y) -> bool {
        for (int i = 1; i <= m; i++) {
            auto [xx, yy] = v[i];
            ll t = abs(xx - x) + abs(yy - y);
            if (t <= a[i]) {
                cout << "Escape!" << '\n';
                return true;
            }
        }
        return false;
    };

    auto check2 = [&] (ll x, ll y) -> bool {
        if (x > n || y > n || x < 1 || y < 1 || (x == sx && y == sy)) {
            cout << "Illegal Operation!" << '\n';
            return true;
        }
        return false;
    };

    auto check3 = [&] (ll x, ll y, ll t) -> bool {
        for (int i = 1; i <= m; i++) {
            if (i == t) continue;
            if (x == v[i].fi && y == v[i].se) {
                cout << "Illegal Operation!" << '\n';
                return true;
            }
        }
        return false;
    };

    auto move = [&] (ll x, ll y) -> ll {
        ll mx = 0;
        ll ans = 0;
        bool found1 = false;
        for (int j = 0; j < 5; j++) {
            bool found2 = true;
            ll xx = x + dx[j];
            ll yy = y + dy[j];
            if (xx < 1 || xx > n || yy < 1 || yy > n) continue;
            ll mn = 10000;
            ll mnn = 10000;
            for (int k = 1; k <= m; k++) {
                auto [xxx, yyy] = v[k];
                ll t = abs(xxx - xx) + abs(yyy - yy);
                if (t <= a[k]) {
                    found2 = false;
                    break;
                }
                mnn = min(t, mnn);
            }
            if (!found2) {
                continue;
            }else {
                found1 = true;
                mn = min(mn, mnn);
                if (mn > mx) {
                    mx = mn;
                    ans = j;
                }
            }
        }
        if (!found1) {
            return 6;
        }
        return ans;
    };

    for (int i = 1; i <= q; i++) {
        ll mx = 0;
        ll ans = 0;
        ll t = (i - 1) % m + 1;
        if (b[i].fi == 'N') {
            v[t].se++;
        }else if (b[i].fi == 'S') {
            v[t].se--;
        }else if (b[i].fi == 'W') {
            v[t].fi--;
        }else if (b[i].fi == 'E') {
            v[t].fi++;
        }

        if (check2(v[t].fi, v[t].se)) return;
        if (check3(v[t].fi, v[t].se, t)) return;

        cout << "Legal Operation!" << '\n';

        if (b[i].se == '+') {
            a[t]++;
        }else if (b[i].se == '-') {
            a[t]--;
            if (a[t] < 0) {
                cout << "Illegal Operation!" << '\n';
                return;
            }
        }

        ll tt = move(sx, sy);
        if (tt == 6) {
            cout << "Escape!" << '\n';
            return;
        }
        sx += dx[tt];
        sy += dy[tt];
        
        cout << sx << ' ' << sy << '\n';
    }

    cout << "Grandmaster General Kangaroo!" << '\n';
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