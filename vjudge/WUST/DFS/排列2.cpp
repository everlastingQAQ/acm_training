#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;

ll a[4], ans[4];
vector <bool> pd(4, false);
ll temp = -1;

void print()
{
    if (ans[0] != temp) {
        cout << '\n';
    }
    
    for (ll x : ans) {
        cout << x;
    }
    cout << ' ';
    temp = ans[0];
}

void dfs (ll k)
{
    if (k == 4) {
        print();
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (!pd[i]) {
            if (k == 0 && a[i] == 0) {
                continue;
            }
            if (i > 0 && a[i] == a[i - 1] && !pd[i - 1]) {
                continue;
            }            
            pd[i] = true;
            ans[k] = a[i];
            dfs(k + 1);
            pd[i] = false;
        }
    }
}

void solve ()
{
    while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
        fill(pd.begin(), pd.end(), false);
        temp = -1;
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) {
            break;
        }else {
            dfs(0);
        }
        cout << '\n';
    }
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