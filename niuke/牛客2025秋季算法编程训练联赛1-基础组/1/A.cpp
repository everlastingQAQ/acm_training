#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e6 + 5;

void solve ()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    int cnt1 = 0;
    int mx1 = -1;
    for (int i = 0, j = 0; j < n; j++) {
        if (s[j] == '1') {
            cnt1++;
        }
        while (cnt1 > k && i <= j) {         
            if (s[i] == '1') {
                cnt1--;
            }
            i++;
        }
        mx1 = max(j - i + 1, mx1);
    }

    int cnt2 = 0;
    int mx2 = -1;
    for (int i = 0, j = 0; j < n; j++) {
        if (s[j] == '0') {
            cnt2++;
        }
        while (cnt2 > k && i <= j) {    
            if (s[i] == '0') {
                cnt2--;
            }
            i++;
        }
        mx2 = max(j - i + 1, mx2);
    }

    int ans = max(mx1, mx2);

    cout << ans << endl;
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