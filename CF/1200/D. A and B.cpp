#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 5;
int a[MAXN];
int vis[MAXN];

void solve ()
{
    int n;
    string s;
    cin >> n >> s;

    char c = s[n / 2];

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            count++;
        }
    }
    
    if (count <= 2) {
        cout << 0 << endl;
        return;
    }

    int cnt = 0;
    bool l = true;
    int p = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        if (i - 1 >= 0 && s[i] != c && s[i - 1] == c) {
            swap(s[i], s[i - 1]);
            cnt++;
            l = false;
        }else if (i - 1 >= 0 && s[i] != c && s[i - 1] != c) {
            if (l == false) {
                cnt += p;
                p = 0;
                l = true;
            }
            p++;
            i--;
        }else {
            continue;
        }
    }

    l = true;
    p = 0;
    for (int i = n / 2 + 1; i < n; i++) {
        if (i + 1 < n && s[i] != c && s[i + 1] == c) {
            swap(s[i], s[i + 1]);
            cnt++;
            l = false;
        }else if (i + 1 < n && s[i] != c && s[i + 1] != c) {
            if (l == false) {
                cnt += p;
                p = 0;
                l = true;
            }
            p++;
            i++;
        }else {
            continue;
        }
    }

    cout << cnt << endl;
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