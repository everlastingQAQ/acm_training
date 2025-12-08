#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
ll n, t;

struct coin{
    ll m;
    ll v;
    double per;
};

bool cmp (const coin &a, const coin &b)
{
    return a.per > b.per;
}

void solve ()
{
    cin >> n >> t;

    coin s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i].m >> s[i].v;
        s[i].per = 1.0 * s[i].v / s[i].m;
    }

    sort(s, s + n, cmp);

    ll sum = 0;
    double ans = 0;
    int j = 0;
    while (sum <= t) {
        if (sum + s[j].m <= t) {
            sum += s[j].m;
            ans += s[j].v;
        }else if (sum + s[j].m > t) {
            ll o = t - sum;
            ans += 1.0 * o * s[j].v / s[j].m;
            break;
        }
        j++;
    }

    cout << fixed << setprecision(2) << ans << endl;

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