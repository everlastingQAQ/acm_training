#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
int w, n;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> w >> n;
    vector <int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), cmp);

    int l = 0, r = n - 1;

    int cnt = 0;
    while (l <= r) {
        int temp = a[l] + a[r];
        if (temp > w) {
            cnt++;
            l++;
        }else {
            cnt++;
            l++;
            r--;
        }
    }

    cout << cnt << endl;

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