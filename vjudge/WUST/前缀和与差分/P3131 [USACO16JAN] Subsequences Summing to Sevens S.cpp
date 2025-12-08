#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
ll n;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n;

    vector <ll> a(n + 1);
    vector <ll> s(n + 1);

    a[0] = 0;
    s[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        a[i] = (a[i - 1] + s[i]) % 7;
    }

    vector <ll> fir(7, -1);
    vector <ll> las(7, -1);

    for (ll i = 0; i <= n; i++) {
        if (fir[a[i]] == -1) {
            fir[a[i]] = i;
        }
    }

    for (ll i = n; i >= 0; i--) {
        if (las[a[i]] == -1) {
            las[a[i]] = i;
        }
    }

    ll mx = 0;
    for (int i = 0; i < 7; i++) {
        mx = max(mx, las[i] - fir[i]);
    }

    cout << mx << endl;

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