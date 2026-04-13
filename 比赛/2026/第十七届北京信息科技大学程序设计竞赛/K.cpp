#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-5;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

void solve ()
{
    int n;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1e9 + 10;

    auto check = [&] (int m) -> bool {
        int chu = m;
        for (int i = 1; i <= n; i++) {
            if (m > a[i]) m++;
            else if (m < a[i]) m--;
        }
        if (m > chu) return 1;
        return 0;
    };

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            r = m - 1;
        } 
        else l = m + 1;
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