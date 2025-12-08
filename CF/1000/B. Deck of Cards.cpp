#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
const double eps = 1e-5;
int n, k;
string s;
string ans[MAXN];

void solve ()
{
    cin >> n >> k >> s;

    int cnt_0 = 0;
    int cnt_1 = 0;
    int cnt_2 = 0;

    if (k == n) {
        for (int i = 0; i < n; i++) {
            ans[i] = '-';
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << endl;
        return;
    }

    for (char p : s) {
        if (p == '0') {
            cnt_0++;
        }else if (p == '1') {
            cnt_1++;
        }else if (p == '2') {
            cnt_2++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        ans[i] = '+';
    }

    for (int i = 0; i < cnt_0; i++) {
        ans[i] = '-';
    }

    for (int i = 0; i < cnt_1; i++) {
        ans[n - i - 1] = '-';
    }

    for (int i = 0; i < cnt_2; i++) {
        if (ans[cnt_0 + i] == "-") break;
        ans[cnt_0 + i] = '?';
    }

    for (int i = 0; i < cnt_2; i++) {
        if (ans[n - cnt_1 - 1 - i] == "-") break;
        ans[n - cnt_1 - 1 - i] = '?';
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
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