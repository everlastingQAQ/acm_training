#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
int a[MAXN];

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int m, n;
    cin >> m >> n;

    if (m == 1 || n == 1 || (m == 2 && n == 2)) {
        cout << "NO" << endl;
    }else {
        cout << "YES" << endl;
    }
    
    return;
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