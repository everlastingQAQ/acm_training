#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1;
int n, t;

bool cmp (int a1, int b1)
{
    return a1 < b1;
}

void solve ()
{
    cin >> n;
    map <string, pair<int, int>> m;
    
    int a, b;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> s;
        m[s] = make_pair(a, b);
    }

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        for (auto &entry : m) {
            if (entry.second.first == a && entry.second.second == b) {
                cout << entry.first << endl;
                break;
            }
        }
    }
    return;
}

int main ()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _ = 1;
	//cin >> _;

    while (_--) {
        solve();
    }

    return 0;
}