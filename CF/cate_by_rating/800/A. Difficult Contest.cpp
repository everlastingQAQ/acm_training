#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 10;
int a[27];

void solve ()
{
    string s;
    cin >> s;
    memset(a, 0, sizeof(a));

    for (char c : s) {
        a[c - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (i == 5 || i == 13 || i == 19) {
            continue;
        }else if (a[i] > 0) {
            char c = i + 'A';
            for (int j = 0; j < a[i]; j++) {
                cout << c;
            }
        }
    }

    for (int i = 0; i < a[19]; i++) {
        cout << 'T';
    }

    for (int i = 0; i < a[5]; i++) {
        cout << 'F';
    }

    for (int i = 0; i < a[13]; i++) {
        cout << 'N';
    }

    cout << endl;   
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}

//a b c d e f g h i j k l m n o p q r s t u v w x y z