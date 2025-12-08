#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2001;
const double eps = 1e-5;
int k;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> k;

    int a[MAXN];
    int b[MAXN];

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= k; i++) {
        cin >> b[i];
    }

    vector <int> dp(k + 1, 0);

    dp[1] = a[1];

    for (int i = 2; i <= k; i++) {
        dp[i] = min(dp[i - 1] + a[i], b[i] + dp[i - 2]);
    }

    int t = dp[k];
    int hour = 8 + dp[k] / 3600;
    int minute = (dp[k] % 3600) / 60;
    int second = dp[k] % 60;

    if (hour > 11) {
        hour -= 12;
        printf("%02d:%02d:%02d pm\n", hour, minute, second);
    }else {
        printf("%02d:%02d:%02d am\n", hour, minute, second);
    }
    
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