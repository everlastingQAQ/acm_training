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
    ll a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    ll sum = 0;
    
    sum += min(a, y);
    sum += min(b, z);
    sum += min(c, x);

    cout << sum << endl;

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