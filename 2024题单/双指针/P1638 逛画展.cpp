#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 10;
int a[MAXN];
int vis[MAXN];

int cmp (int a1, int b1) {
    return a1 < b1;
}

void solve ()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(vis, 0, sizeof(vis));

    int l = 1, r = 1;

    int mn = n + 1;
    int count = 0;
    for (int i = 1, j = 1; j <= n; j++) {

        if (vis[a[j]] == 0) {
            count++;
        }
        vis[a[j]]++;

        while (count == m && i < j) {  
            if (j - i + 1 < mn) {
                mn = j - i + 1;
                l = i;
                r = j;
            }
            vis[a[i]]--;
            if (vis[a[i]] == 0) {
                count--;
            }
            i++;
        }
    }

    cout << l << ' ' << r << endl;
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