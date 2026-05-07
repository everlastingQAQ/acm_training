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

ll n;

void solve ()
{
    cin >> n;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector <ll> ans;
    ans.push_back(-1);
    for (int i = 2; i <= n; i++) {
        ll pos = i;
        for (int j = i - 1; j > 0; j--) {
            if (v[i] < v[j]) {
                pos = j;
                break;
            }
        }
        if (pos == i) {
            ans.push_back(-1);
        }else {
            ans.push_back(pos);
        }
    }

    for (auto x : ans) {
        cout << x << '\n';
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