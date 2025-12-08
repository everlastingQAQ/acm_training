#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200010;
int a[26];

void solve ()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    memset(a, 0, sizeof(a));

    int mn = n + 1;
    for (int i = 0, j = 0; j < n; j++) {

        a[s[j] - 'a']++;

        while (a[s[j] - 'a'] >= k && i <= j) {
            if (a[s[j] - 'a'] == k) {
                mn = min(mn, j - i + 1);
            }
            a[s[i] - 'a']--;
            i++;
        }
    }

    if (mn == n + 1) {
        cout << -1 << endl;
    }else {
        cout << mn << endl;
    }

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