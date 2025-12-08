#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
int a[MAXN];

int cmp (int a1, int b)
{
    return a1 > b;
}

void solve ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);

    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += a[i];
    }

    cout << ans << endl;
}

int main ()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}