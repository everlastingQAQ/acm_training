#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e12 + 5;

ll find_factor(ll x) {
    ll ans = 0;
    
    for (ll i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            if (i == x / i) {
                ans++;
                break;
            }else {
                ans += 2;
            }
        }
    }

    return ans;
}

void solve ()
{
    ll n;
    cin >> n;
    ll cnt = 0;
    while (n != 2) {
        n = find_factor(n);
        cnt++;
    }
    cout << cnt << endl;
    return;
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