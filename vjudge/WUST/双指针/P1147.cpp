#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200010;
int a[26];

void solve ()
{
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1, j = 1; j < n; j++) {
        sum += j;
        while (sum > n) {
            sum -= i;
            i++;
            if (sum == n) {
                cout << i << ' ' << j << endl;
                break;
            }else if (sum < n) {
                break;
            }
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