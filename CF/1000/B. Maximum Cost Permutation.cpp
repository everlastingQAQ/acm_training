#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
const double eps = 1e-5;
int n;

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n;
    vector <int> a;
    vector <int> zero;

    int cnt = 0;
    int cnt_no = 0;
    int cnt_0 = 0;
    int p = 0;
    int q = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
        if (a[i] == 0 || a[i] != i) {
            zero.push_back(i);
            cnt++;
            if (t == 0 && p == 0) {
                cnt_0++;
                p = i;
                q = cnt;
            }
        }
    }

    bool is_erase = false;
    if (cnt_0 == 1 && zero[q] == p) {
        is_erase = true;
        zero.erase(zero.begin() + q);
    }

    if (is_erase == false) {
        sort(zero.begin(), zero.begin() + cnt, cmp);
    }else {
        sort(zero.begin(), zero.begin() + cnt - 1, cmp);
    }

    // cout << cnt << endl;
    // cout << zero[0] << ' ' << zero[cnt - 1] << endl;

    if (cnt > 1 && cnt_0 > 1) {
        cout << zero[zero.begin()] - zero[cnt - 1] + 1 << endl;
    }else {
        cout << 0 << endl;
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