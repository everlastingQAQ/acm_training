#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;

bool cmp (ll a1, ll b1)
{
    return a1 < b1;
}

void solve ()
{
    cin >> n;
    vector <ll> v(n);
    
    bool a = false;
    bool b = false;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0) {
            a = true;
        }else if (v[i] % 2 == 1) {
            b = true;
        }
    }

    if (a && b) {
        sort(v.begin(), v.end(), cmp);
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << endl;
        return;
    }else {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << endl;
        return;
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