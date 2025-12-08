#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
string s;

void solve ()
{
    cin >> s;
    ll x = 0, y = 0;
    
    vector <pair<ll, ll> > pos;
    pos.push_back({0, 0});

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L') {
            x--;
        }else if (s[i] == 'R') {
            x++;
        }else if (s[i] == 'U') {
            y++;
        }else if (s[i] == 'D') {
            y--;
        }
        pos.push_back({x, y});
    }

    for (int i = 0; i < pos.size(); i++) {
        for (int j = i + 1; j < pos.size(); j++) {
            if (j - i >  abs(pos[i].fi - pos[j].fi) + abs(pos[i].se - pos[j].se)) {
                cout << "BUG" << '\n';
                return;
            }
        }
    }

    cout << "OK" << '\n';
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