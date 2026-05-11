#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 10000 + 5;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cout << 1;
    }

    for (int i = 0; i < n - k; i++) {
        cout << 0;
    }

    cout << endl;
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