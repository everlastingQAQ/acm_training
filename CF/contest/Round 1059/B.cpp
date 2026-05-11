#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
int a[1001];

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int k;
    string s;
    cin >> k >> s;

    memset(a, 0, sizeof(a));

    int cnt = 0;
    bool found = false;
    for (int i = 0; i < k; i++) {
        if (s[i] == '0') {
            a[cnt] = i;
            cnt++;
            found = true;
        }
    }

    if (found == false) {
        cout << 0 << endl;
        cout << endl;
        return;
    }

    cout << cnt << endl;

    for (int i = 0; i < cnt; i++) {
        cout << a[i] + 1 << ' ';
    }

    cout << endl;
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