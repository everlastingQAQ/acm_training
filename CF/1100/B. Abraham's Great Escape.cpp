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
    if (n * n == k + 1) {
        cout << "No" << '\n';
        return;
    }else {
        cout << "Yes" << '\n';
    }

    vector <vector <char> > v(n + 1, vector <char> (n + 1, 'X'));

    ll cnt = 0;
    ll x = 0;
    ll y = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[i][j] = 'U';
            cnt++;
            if (cnt == k) {
                x = i;
                y = j;
                break;
            }
        }
    }

    y++;
    if (y == n) {
        v[x][y] = 'D';
    }else if (y < n) {
        v[x][y] = 'R';
    }
    y++;

    //cout << x << ' ' << y << '\n';
    
    while (y <= n) {
        v[x][y] = 'L';
        y++;
    }
    x++;
    for (int i = x; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                v[i][j] = 'R';
            }else {
                v[i][j] = 'L';
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << v[i][j];
        }
        cout << '\n';
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