#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    int n;
    cin >> n;

    int mn = 1001;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mn = min(t, mn);
    }

    cout << mn << endl;
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