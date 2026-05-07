#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
	int n;
    string s;
    cin >> n >> s;
    string tt = "niumo";
    vector <char> v;
    for (int i = 0; i < n; i++) {
        v.push_back(s[i]);
        while (v.size() >= 2) {
            char c1 = v[v.size() - 1];
            char c2 = v[v.size() - 2];
            string x;
            x = x + c2;
            x = x + c1;
            if (x == "mo") {
                for (int j = 0; j < 2; j++) {
                    v.pop_back();
                }
            }else break;
        }   
        while (v.size() >= 3) {
            char c1 = v[v.size() - 1];
            char c2 = v[v.size() - 2];
            char c3 = v[v.size() - 3];
            string x;
            x = x + c3;
            x = x + c2;
            x = x + c1;
            if (x == "niu") {
                for (int j = 0; j < 3; j++) {
                    v.pop_back();
                }
            }else break;
        }
    }

    if (v.size()) cout << "No\n";
    else cout << "Yes\n";
} 

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}