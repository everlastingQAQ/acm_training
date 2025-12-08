#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
const double eps = 1e-5;

void solve ()
{
    int n;
    cin >> n;

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
            for (int j = 0; j < n * 3 - 2 * (i + 1); j++) {
                cout << ' ';
            }
            cout << '*';
            cout << endl;
        }else {
            for (int j = 0; j < i; j++) {
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
    cout << endl;

    for (int i = 1; i <= n - 2; i++) {
        if (i <= (n - 2) / 2) {
            for (int j = 0; j < n - 1 - i; j++) {
                cout << ' ';
            }
            cout << '*';
            cout << endl;
        }else {
            for (int j = 0; j < n - 1 - i; j++) {
                cout << ' ';
            }
            cout << '*';
            for (int j = 0; j < n * 3 - 2 * (n - i); j++) {
                cout << ' ';
            }
            cout << '*';
            cout << endl;
        } 
            
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