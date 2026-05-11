#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 51;
int a[MAXN];

int cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    int n;
    cin >> n;

    int cnt_0 = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] == 0) {
            cnt_0++;
        }
    }

    sum += cnt_0;

    cout << sum << endl;

}

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}