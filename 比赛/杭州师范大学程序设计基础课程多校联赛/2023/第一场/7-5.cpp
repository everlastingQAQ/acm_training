#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000 + 5;
bool is_prime [MAXN];
vector <int> prime;
int n;

void solve ()
{
    int a, m;
    cin >> a >> m;

    int ans = m % (a + 1);

    cout << ans;
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