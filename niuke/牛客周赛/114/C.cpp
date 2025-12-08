#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 4;
const double eps = 1e-5;
int n;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n;
    string s;
    cin >> s;

    int cnt[4];
    memset(cnt, 0, sizeof(cnt));

    bool is_found = false;
    cnt[s[0] - '0']++;
    for (int i = 1; i < n - 1; i++) {
        cnt[s[i] - '0']++;
        if (s[i - 1] - '0' + s[i] - '0' + s[i + 1] - '0' == 6 && s[i - 1] != s[i] && s[i - 1] != s[i + 1] && s[i] != s[i + 1]) {
            is_found = true;
            break;
        }
        //cout << s[i - 1] - '0' + s[i] - '0' + s[i + 1] - '0' << endl;
    }
    cnt[s[n - 1] - '0']++;

    if (is_found == true) {
        cout << 0 << endl;
        return;
    }

    bool negative = false;
    for (int i = 1; i < 4; i++) {
        if (cnt[i] == 0) {
            negative = true;
        }
    }

    if (negative) {
        cout << -1 << endl;
    }else {
        cout << 1 << endl;
    }

}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}