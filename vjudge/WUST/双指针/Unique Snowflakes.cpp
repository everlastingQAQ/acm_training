#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 10;
ll a[MAXN];
ll vis[MAXN];

void solve ()
{
    int n;
    cin >> n;

    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mx = 0;
    for (int i = 1, j = 1; j <= n; j++) {
        vis[a[j]]++;
        while (vis[a[j]] >= 2) {
            vis[a[i]]--;
            i++;
        }

        if (j - i + 1 > mx) {
            mx = j - i + 1;
        }
    }

    cout << mx << endl;

}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}