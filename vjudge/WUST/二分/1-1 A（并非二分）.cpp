#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1;
int a[MAXN];

int cmp (int a1, int b1)
{
    return a1 < b1;
}

bool check (int x)
{
    
}

void solve ()
{
    int n;
    cin >> n;

    memset(a, 0, sizeof(a));
    int cnt_n = 0;
    int cnt_1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            cnt_n++;
        }else {
            cnt_1++;
        }
    }

    for (int i = 0; i < min(cnt_n , cnt_1) * 2; i++) {
        if (i % 2 == 0) {
            cout << 1 << ' ';
        }else {
            cout << -1 << ' ';
        }
    }

    if (cnt_1 > cnt_n) {
        for (int i = 0; i < n - min(cnt_n , cnt_1) * 2; i++) {
            cout << 1 << ' ';
        }
    }else {
        for (int i = 0; i < n - min(cnt_n , cnt_1) * 2; i++) {
            cout << -1 << ' ';
        }
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