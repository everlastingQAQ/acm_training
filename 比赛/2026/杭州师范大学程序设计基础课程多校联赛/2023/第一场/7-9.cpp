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
    int n;
    cin >> n;

    for (int i = 0; i < n * 3; i++) {
        cout << '*';
    }
    for (int i = 0; i < n; i++) {
        cout << ' ';
    }
    for (int i = 0; i < n * 3; i++) {
        cout << '*';
    }
    cout << endl;

    for (int i = 1; i <= n - 2; i++) {
        if (i <= (n - 2) / 2) {
            for (int j = 0; j < i; j++) {
                cout << ' ';
            }
            cout << '*';
            for (int j = 0; j < n * 3 - 2; j++) {
                cout << ' ';
            }
            cout << '*';
            for (int j = 0; j < n - 2 * i; j++) {
                cout << ' ';
            }
            cout << '*';
            for (int j = 0; j < n * 3 - 2; j++) {
                cout << ' ';
            }
            cout << '*';
            cout << endl;
        }else {
            for (int j = 0; j < i; j++) {
                cout << ' ';
            }
            cout << '*';
            for (int j = 0; j < 5 * n + (n - 2 - i + 1) * 2; j++) {
                cout << ' ';
            }
            cout << '*';
            cout << endl;
        }     
    }

    for (int i = 0; i < n - 1; i++) {
        cout << ' ';
    }
    cout << '*';
    for (int i = 0; i < 5 * n; i++) {
        cout << ' ';
    }
    cout << '*';
    cout << endl;

    for (int i = 1; i <= n - 2; i++) {
        if (i <= (n - 2) / 2) {
            for (int j = 0; j < n - 1 - i; j++) {
                cout << ' ';
            }
            cout << '*';
            for (int j = 0; j < 5 * n + 2 * i; j++) {
                cout << ' ';
            }
            cout << '*';
            cout << endl;
        }else {
            for (int j = 0; j < n - 1 - i; j++) {
                cout << ' ';
            }
            cout << '*';
            for (int j = 0; j < n * 3 - 2; j++) {
                cout << ' ';
            }
            cout << '*';
            for (int j = 0; j < 2 * (i - (n - 2) / 2); j++) {
                cout << ' ';
            }
            cout << '*';
            for (int j = 0; j < n * 3 - 2; j++) {
                cout << ' ';
            }
            cout << '*';
            cout << endl;
        } 
            
    }

    for (int i = 0; i < n * 3; i++) {
        cout << '*';
    }
    for (int i = 0; i < n; i++) {
        cout << ' ';
    }
    for (int i = 0; i < n * 3; i++) {
        cout << '*';
    }
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