#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 11;
int a[MAXN];
int b[MAXN];
int cnt[MAXN];

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        cnt[i] = a[i] - b[i];
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += max(0, a[i] - b[i]);
    }

    cout << sum + 1 << endl;
}

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}