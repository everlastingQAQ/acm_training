#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 4;
const double eps = 1e-5;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            bool not_protected = false;
            int cnt = max(0, i - k + 1);
            for (int j =  i - 1; j >= cnt; j--) {
                //cout << s[j] << endl;
                if (s[j] == '1') {
                    not_protected = true;
                    break;
                }

            }
            if (!not_protected) {
                ans++;
            }
        }
        //cout << ans << ' ' << s[i] << endl;
    }

    cout << ans << endl;

    return;
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