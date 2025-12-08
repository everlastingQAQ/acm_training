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

    int ans = 0;
    for (int i = 0; i < n; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j < n; j++){
            cnt[s[j] - '0']++;
            if (cnt[1] == cnt[2] && cnt[2] == cnt[3]) {
                ans++;
            }
        }
    }

    cout << ans << endl;
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