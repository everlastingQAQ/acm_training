#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
  	string s;
    cin >> s;
    vector <int> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'A']++;
    }
    int n = s.size();

    if (n & 1) {
        int c = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) c++;
        }
        if (c != 1) {
            cout << "NO SOLUTION";
            return;
        }
        char cc;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                cc = (char)(i + 'A');
                continue;
            }
            for (int j = 0; j < cnt[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }
        for (int i = 0; i < cnt[cc - 'A']; i++) {
            cout << cc;
        }
        for (int i = 25; i >= 0; i--) {
            if (cnt[i] & 1) {
                cc = i + 'A';
                continue;
            }
            for (int j = 0; j < cnt[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }
    }else {
        int c = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) c++;
        }
        if (c > 0) {
            cout << "NO SOLUTION";
            return;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < cnt[i] / 2; j++) {
                cout << (char)(i + 'A');
            }
        }
    }
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