#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define first fi
#define second se

ll n, a, b;

void solve ()
{
    cin >> n >> a >> b;

    vector <ll> pa(n + 1);
    vector <ll> pb(n + 1);

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        pa[i] = pa[i - 1];
        pb[i] = pb[i - 1];
        if (c == 'a') {
            pa[i]++;
        }else {
            pb[i]++;
        }
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ll xa = lower_bound(pa.begin() + 1, pa.end(), pa[i - 1] + a) - pa.begin();
        ll xb = lower_bound(pb.begin() + 1, pb.end(), pb[i - 1] + b) - pb.begin() - 1;
        ans += max(0LL, xb - xa + 1);
    }

    cout << ans << '\n';
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