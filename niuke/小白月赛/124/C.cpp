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
 
ll x, y, n;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void solve ()
{
    cin >> x >> y >> n;
    ll t = 0;
    bool found = false;

    while (n--) {
        ll a, b;
        cin >> a >> b;
        for (int i = 0; i < 8; i++) {
            if (abs(a + dx[i] - x) + abs(b + dy[i] - y) <= 2 && abs(a + dx[i] - x) <= 1 && abs(b + dy[i] - y) <= 1) {
                t++;
            }
            if (abs(a + dx[i] - x) + abs(b + dy[i] - y) == 0) {
                found = true;
            }
        }
    }

    if (found && t >= 8) {
        cout << 'B' << '\n';
    }else if (!found && t >= 8) {
        cout << 'A' << '\n';
    }else {
        cout << 'C' << '\n';
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