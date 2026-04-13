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

    vector <char> c;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char t;
        cin >> t;
        if (t == 'C') {
            cnt++;
        }else {
            c.push_back(t);
        }
    }

    for (int i = 0; i < n - cnt; i++) {
        cout << c[i] << ' ';
    }

    for (int i = 0; i < cnt; i++) {
        cout << 'A' << ' ';
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