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
    int n;
    string s;
    cin >> n >> s;

    int cnt_1 = 0;
    int cnt_6 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt_1++;
        }else if (s[i] == '6') {
            cnt_6++;
        }
    }

    if (cnt_1 < cnt_6) {
        cout << cnt_1;
        return;
    }else if (cnt_1 == cnt_6) {
        cout << cnt_1 - 1;
        return;
    }else if (cnt_1 > cnt_6) {
        cout << cnt_6 - 1;
        return;
    }

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