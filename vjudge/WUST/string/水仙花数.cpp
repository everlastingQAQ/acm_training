#include <bits/stdc++.h>
using namespace std;
int m, n;

void solve (int m, int n)
{
    int a, b, c;
    bool is_find = false;
    for (int i = m; i <= n; i++) {
        a = i / 100;
        b = i / 10 - a * 10;
        c = i - a * 100 - b * 10;
        if (a * a * a + b * b * b + c * c * c == i) {
            cout << i << ' ';
            is_find = true;
        }
    }
    if (is_find == false) {
        cout << "no" << endl;
    }else {
        cout << endl;
    }
}


int main ()
{
    while (cin >> m >> n) {
        solve(m, n);
    }
    return 0;
}