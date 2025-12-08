#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1;
int n, m;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    while (cin >> n >> m) {
        int t;
        set <int> s;
        for (int i = 0; i < n; i++) {
            cin >> t;
            s.insert(t);
        }
        for (int i = 0; i < m; i++) {
            cin >> t;
            s.insert(t);
        }
        for (auto l : s) {
            cout << l << ' ';
        }
        cout << endl;
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