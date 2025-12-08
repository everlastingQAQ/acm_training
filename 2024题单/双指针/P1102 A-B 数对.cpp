#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 10;
int a[MAXN];

int cmp (int a1, int b1) {
    return a1 < b1;
}

void solve ()
{
    ll n, c;
    cin >> n >> c;
    map <ll, ll> mp;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        ans += mp[a[i] - c];
    }

    cout << ans << '\n';

}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	//cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}