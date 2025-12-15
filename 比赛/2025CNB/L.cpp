#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const ll MAXN = 1e7;
const ld eps = 1e-12;
const ll mod = 1e9 + 7;

vector <vector <ll> > e(8);
ll n;
ll ans = 0;

void solve ()
{
    cin >> n;
    map <pair<ll, ll>, bool> mp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp[{a, b}] = true;
    }

    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 6; j++) {
            if (!mp[{i, j}]) {
                e[i].push_back(j);
            }
        }
    }

    auto dfs = [&] (ll day, ll course, auto self) -> void {
        if (day == 7) {
            ans++;
            return;
        }

        for (auto x : e[day + 1]) {
            if (x == course) continue;
            self(day + 1, x, self);
        }
    };

    for (auto x : e[1]) {
        dfs(1, x, dfs);
    }

    cout << ans << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}