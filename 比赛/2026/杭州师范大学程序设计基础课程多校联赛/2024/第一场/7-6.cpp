#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1;

void solve ()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        if (i != n) {
            cout << "*   ";
        }else {
            cout << "*";
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << " * *";
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << "  *";
        }else {
            cout << "   *";
        }
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