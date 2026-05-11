#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e9 + 5;
vector <int> a;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int n;
    cin >> n;
    a.clear();

    bool has_odd = false;
    ll cnt_odd = 0;
    ll cnt_even = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
        if (t % 2 == 0) {
            cnt_even++;
        }else {
            cnt_odd++;
        }
    }

    if (cnt_odd == 0) {
        cout << 0 << endl;
        return;
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            sum += a[i];
        }
    }
    
    sort(a.begin(), a.end(), cmp);

    int cnt;
    if (cnt_odd % 2 == 1) {
        cnt = cnt_odd / 2 + 1;
    }else {
        cnt = cnt_odd / 2;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            sum += a[i];
            count++;
        }
        if (count == cnt) {
            break;
        }
    }

    cout << sum << endl;

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