#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 10000 + 5;
int n;

int find_factor (int x)
{
    int sum = 1;
    if (x == 1) return 1;
    for (int i = 1; i < sqrt(x); i++) {
        if (x % i == 0) {
            sum += 2;
        }
    }

    return sum;
}

void solve ()
{
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n / i; i++) {
        ans += find_factor(i * i);
    }

    cout << ans << endl;
    return;
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