#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 105;
int a[MAXN];

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int n;
    cin >> n;

    memset(a, 0, sizeof(a));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                cout << "YES" << endl << 2 << endl;
                cout << a[i] << ' ' << a[j] << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
    
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