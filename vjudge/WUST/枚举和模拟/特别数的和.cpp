#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1;
bool a[MAXN];
int n, m;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    cin >> n;

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        for (char c : s) {
            if (c == '2' || c == '0' || c == '1' || c == '9') {
                sum += i;
                break;
            }
        }
    }

    cout << sum << endl;
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