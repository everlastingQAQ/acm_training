#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 2;
int n;

struct node{
    int sum;
    int a;
};

bool cmp (node n1, node n2)
{
    return n1.sum > n2.sum;
}

void solve ()
{
    cin >> n;

    int a[MAXN];
    int b[MAXN];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    node p[n];

    for (int i = 1; i <= n; i++) {
        p[i].sum = a[i] + b[i];
        p[i].a = i; 
    }

    sort(p + 1, p + n + 1, cmp);

    for (int i = 1; i <= n; i += 2) {
        cout << p[i].a << ' ';
    }

    cout << endl;

    for (int i = 2; i <= n; i += 2) {
        cout << p[i].a << ' ';
    }

    cout << endl;
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