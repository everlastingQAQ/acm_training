#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
int n, x;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n >> x;

    vector <int> a(n);
    vector <int> cnt;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            cnt.push_back(i);
        }
    }

    int mx = *max_element(cnt.begin(), cnt.end());
    int mn = *min_element(cnt.begin(), cnt.end());

    //cout << mx << ' ' << mn << endl;

    if (mx - mn < x) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
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