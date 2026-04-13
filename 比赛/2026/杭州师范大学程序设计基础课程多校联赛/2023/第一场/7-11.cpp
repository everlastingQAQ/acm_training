#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 10000 + 5;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    int hpa, hpb, x, y, d, cnt;
    cin >> hpa >> hpb >> x >> y >> d >> cnt;

    if (y > hpa) {
        cout << 'N' << endl;
        return;
    }

    int t = -1;
    for (int i = 1; i < cnt; i++) {
        if (d * i >= y) {
            t = i;
            break;
        }
    }

    if (t == -1) {
        int count = ceil(1.0 * hpb / x);
        if (hpa - (count - 1) * y <= 0) {
            cout << 'N' << endl;
            return;
        }else {
            cout << 'Y' << endl;
            return;
        }
    }

    int temp = cnt / t;

    int count = ceil(1.0 * hpa / y);
    if (hpb - (count + temp + 1) * y <= 0) {
        cout << 'Y' << endl;
    }else {
        cout << 'N' << endl;
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