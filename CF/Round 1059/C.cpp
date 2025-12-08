#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
vector <int> p;

void solve ()
{
    int a, b;
    cin >> a >> b;

    p.clear();

    for (int i = 0; (1 << i) <= a; i++) {
        if ((a >> i & 1) != (b >> i & 1)) {
            p.push_back(1 << i);
            a ^= 1 << i;
        }
    }

    if (a != b) {
        cout << -1 << endl;
    }else {
        cout << p.size() << endl;
        if (p.size() == 0) return;
        for (auto q : p) {
            cout << q << ' ';
        }
        cout << endl;
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