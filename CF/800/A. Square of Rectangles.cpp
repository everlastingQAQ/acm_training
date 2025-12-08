#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e6 + 2;

void solve ()
{
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    if (l1 == l2 && l2 == l3 && l1 == b1 + b2 + b3 || b1 == b2 && b2 == b3 && b1 == l1 + l2 + l3 || l2 + l3 == l1 && b2 == b3 && b1 + b2 == l1 || b2 + b3 == b1 && l2 == l3 && l1 + l2 == b1) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
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