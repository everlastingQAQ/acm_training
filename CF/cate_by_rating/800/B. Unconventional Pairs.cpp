#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;

bool cmp (int a, int b)
{
    return a > b;
}

int main ()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int a[MAXN];
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        sort(a, a + n, cmp);
        int temp = a[0] - a[1];
        for (int j = 2; j < n - 1; j += 2) {
            if (a[j] - a[j + 1] > temp) {
                temp = a[j] - a[j + 1];
            }
        }
        cout << temp << endl;
    }

    return 0;
}