#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1;
bool a[MAXN];
int n, m;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        a[t] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == false) {
            cout << i << endl;
            return;
        }
    }
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