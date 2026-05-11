#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e8 + 5;
int a[MAXN];
int b[MAXN];

bool cmp (int a, int b)
{
    return a > b;
}

void solve ()
{
    int n, m;
    cin >> n >> m;
 
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1, cmp);

    unsigned long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i] * max(0, m - i + 1);
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