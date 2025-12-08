#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n, k;

bool cmp(const pair<ll, bool> &a1, const pair<ll, bool> &b1)
{
    return a1.fi < b1.fi;
}

void solve ()
{
    cin >> n >> k;

    vector <ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll ans1 = 0;
    ll cnt1 = 0;
    
    ll i = 0, j = 1;
    while (j < n) {
        if (v[j] - v[i] <= k) {
            ans1 = max(ans1, j - i + 1);
            j++;
        }else {
            i++;
        }
    }

    ll ans2 = 0;
    ll cnt2 = 0;

    i = n - 1;
    j = n - 2;
    while (1) {
        if (v[i] - v[j] <= k) {
            j++;
            cnt2++;
            ans2 = max(ans2, cnt2);
            if (j == n) {
                break;
            }
        }else {
            i++;
            cnt2--;
        }
    }

    cout << ans1 + ans2 << '\n';
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