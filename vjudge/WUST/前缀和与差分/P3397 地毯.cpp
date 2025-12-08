#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
ll n, m;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n >> m;

    vector <vector<ll>> s(n + 2, vector<ll>(n + 2, 0));
    
    for (int i = 1; i <= m; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        s[x2 + 1][y2 + 1]++;
        s[x2 + 1][y1]--;
        s[x1][y2 + 1]--;
        s[x1][y1]++;

    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }

}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	//cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}