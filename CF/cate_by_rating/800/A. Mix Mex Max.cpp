#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 510;
int a[MAXN];

void solve ()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == -1) {
                break;
            }else if (a[i] != a[j] && a[j] != -1 || a[j] == 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;

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