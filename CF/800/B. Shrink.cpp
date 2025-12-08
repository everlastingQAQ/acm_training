#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;
int n;

bool cmp (int a1, int b1)
{
    return a1 > b1;
}

void solve ()
{
    cin >> n;
    int N = n;
    if (n % 2 == 1) {
        N += 1;
    }

    vector <int> a(n);

    int j = 1;
    for (int i = 0; i < N / 2; i++) {
        a[i] = j;
        j += 2;
    }

    if (n % 2 == 1) {
        j = n - 1;
    }else {
        j = n;
    }

    for (int i = N / 2; i < n; i++) {
        a[i] = j;
        j -= 2;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    cout << endl;
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