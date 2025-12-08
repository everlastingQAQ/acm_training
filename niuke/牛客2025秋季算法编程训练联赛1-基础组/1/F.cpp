#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e6 + 5;

void solve ()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    int cnt = 0;
    int mx = -1;
    for (int i = 0, j = 0; j < n; j++) {
        if (s[j] == '1' && cnt <= k) {
            s[j] = 0;
            cnt++;
        }
        while (cnt > k) {
            if (s[i] == '0') {
                cnt--;
                s[i] = '1';
            }
            i++;
        }
        mx = max(j - i + 1, mx);
    }

    cout << mx << endl;
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