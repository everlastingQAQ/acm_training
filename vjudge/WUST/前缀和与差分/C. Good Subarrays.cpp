#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int MAXN = 32000;
const double eps = 1e-5;
const ll mod = 998244353;
ll n;
string s;

void solve ()
{
    cin >> n >> s;

    ll sum = 0, ans = 0;
    map <ll, ll> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += s[i] - '0';
        ans += mp[sum - i - 1];
        mp[sum - i - 1]++;
    }

    cout << ans << '\n';

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