#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
ll a[MAXN];
ll n;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0, r = n - 1;
    ll sum1 = a[0], sum2 = a[n - 1];
    ll ans = 0;

    while (l < r) {
        if (sum1 < sum2) {
            sum1 += a[++l];
            //l++;
        } else if (sum1 > sum2) {
            sum2 += a[--r];
            //r--;
        } else {
            ans = sum1;
            sum1 += a[++l];
            //l++;
        }
        //cout << l << ' ' << r << ' ' << sum1 << ' ' << sum2 << endl;
    }

    cout << ans << endl;
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