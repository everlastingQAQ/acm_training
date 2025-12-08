#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1000 + 5;

void solve ()
{
    int n;
    cin >> n;

    vector <int> a;
    for (int i = 0; i <= n; i++) {
        a.push_back(i * i);
    }

    int cnt = 0;
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = n - i - j;
            if (k < i || k < j) break;
            if (a[i] + a[j] == a[k]) {
                cnt++;
                ans = i * j * k;
            }
        }
    }

    if (cnt == 0) {
        cout << "No Joyfine";
    }else if (cnt == 1) {
        cout << ans;
    }else {
        cout << "Many " << cnt;
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