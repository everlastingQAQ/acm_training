#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000 + 5;
bool is_prime [MAXN];
vector <int> prime;
int n;

void solve ()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (c - a > d - b || abs(c - a) % 2 != abs(d - b) % 2 || d < b) {
        cout << -1 << endl;
        return;
    }

    int y = d - b;
    int x = (a + d - b - c) / 2;

    cout << x + y << endl;
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