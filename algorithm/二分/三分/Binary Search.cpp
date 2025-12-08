#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
int n, m;
int a[MAXN];

int lower_binary_search (int x) 
{
    int l = 1, r = n;
    int mid;
    int ans = -1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (a[mid] >= x) {
            if (a[mid] == x) {
                ans = mid;
            }
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    return ans;
}

int upper_binary_search (int x) 
{
    int l = 1, r = n;
    int mid;
    int ans = -1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (a[mid] <= x) {
            if (a[mid] == x) ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve ()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int p;
    for (int i = 1; i <= m; i++) {
        cin >> p;
        int res = lower_binary_search(p);
        cout << res << ' ';
    }

    return;
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

