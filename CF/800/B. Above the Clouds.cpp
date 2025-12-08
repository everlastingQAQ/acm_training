#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
int a[MAXN];

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int n;
    string s;
    cin >> n >> s;

    char b;
    for (int i = 1; i < n - 1; i++) {
        b = s[i];
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (s[j] == b) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;

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