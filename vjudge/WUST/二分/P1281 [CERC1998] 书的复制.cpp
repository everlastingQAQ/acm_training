#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
vector <ll> a;
ll m, k;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

bool check (ll x)
{
    ll cnt = 0;
    ll suma = 0;
    for (int i = m - 1; i >= 0; i--) {
        suma += a[i];
        if (suma > x) {
            cnt++;
            suma = a[i];
        }
    }

    if (cnt > k) {
        return false;
    }else {
        return true;
    }

}

void solve ()
{
    cin >> m >> k;

    a.clear();
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        ll a1;
        cin >> a1;
        sum += a1;
        a.push_back(a1);
    }


    ll l = *max_element(a.begin(), a.end());
    ll r = sum;

    ll ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }

    vector <ll> b;

    ll sumb = 0;
    for (int i = m - 1; i > 0; i--) {
        if (i == 1) {
            break;
        }
        sumb += a[i];
        if (sumb > ans) {
            b.push_back(i + 1);
            b.push_back(i + 2);
            sumb = a[i];
        }
    }
    //缺少输出函数
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
