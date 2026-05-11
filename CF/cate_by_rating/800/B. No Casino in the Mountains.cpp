#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
int a[MAXN];

void solve ()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        bool going = true;
        if (k + i - 1 > n) {
            break;
        }
        for (int j = i; j < k + i; j++) {
            if (a[j] == 1) {
                going = false;
                break;
            }
        }
        if (going == true) {
            cnt++;
            i += k;
        }
    }

    cout << cnt << endl;
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