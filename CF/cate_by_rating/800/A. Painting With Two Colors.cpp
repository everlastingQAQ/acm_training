#include <bits/stdc++.h>
using namespace std;

void solve ()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (n % 2 == 1) {
        if (a % 2 == 1 && b % 2 == 1) {
            cout << "YES" << endl;
        }else if (a % 2 == 0 && b % 2 == 1 && b > a) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }else {
        if (a % 2 == 0 && b % 2 == 0) {
            cout << "YES" << endl;
        }else if (a % 2 == 1 && b % 2 == 0 && b > a) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
}

int main ()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}