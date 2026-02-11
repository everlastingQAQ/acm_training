#include <bits/stdc++.h>
using namespace std;
#define int long long

string maxx (string a, string b) {
    if (a.size() != b.size()) {
        if (a.size() > b.size()) return a;
        else return b;
    }else {
        return max(a, b);
    }
}

void solve ()
{
    string l, r; cin >> l >> r;
    int lsz = l.size(), rsz = r.size();
    string ll = l; reverse(ll.begin(), ll.end());
    int id = 0;
    for (int j = 0; j < ll.size(); j++) {
        if (ll[j] != '0') {
            id = j;
            break;
        }
    }
    ll.erase(0, id);
    string rr = r; reverse(rr.begin(), rr.end());
    id = 0;
    for (int j = 0; j < rr.size(); j++) {
        if (rr[j] != '0') {
            id = j;
            break;
        }
    }
    rr.erase(0, id);

    string ans = maxx(ll, rr);
    if (l.size() < r.size()) {
        ans = maxx(ans, string(rsz - 1, '9'));
    }

    int pos = rsz - 1;
    bool found = false;
    for (int i = pos; i >= 0; i--) {
        if (r[i] >= '1') {
            string t = r;
            t[i]--;
            for (int j = i + 1; j < rsz; j++) {
                t[j] = '9';
            }
            int idx = 0;
            for (int j = 0; j < t.size(); j++) {
                if (t[j] != '0') {
                    idx = j;
                    break;
                }
            }
            t.erase(0, idx);
            if (t.size() < l.size()) continue;
            if (t.size() == l.size()) {
                if (t < l) continue;
            }
            reverse(t.begin(), t.end());
            ans = maxx(t, ans);
        }
    }
    
    // string t = string(rsz, '9');
    // t[t.size() - 1] = r[0] - 1;
    // string tt = t;
    // reverse(tt.begin(), tt.end());
    // if (tt >= l) ans = maxx(t, ans);

    // if (r.size() == 2) {

    // }

    // if (found) {
        
    //     if (t >= l) {
    //         reverse(t.begin(), t.end());
    //         ans = maxx(ans, t);
    //     }
    // }else {
        
    // }

    // pos = lsz - 1;
    // found = false;
    // for (int i = pos; i >= 1; i--) {
    //     if (l[i] >= '1') {
    //         pos = i;
    //         found = true;
    //     }
    // }
    
    // if (found) {
    //     string t = l;
    //     t[pos]--;
    //     for (int i = pos + 1; i < lsz; i++) {
    //         t[i] = '9';
    //     }
    //     reverse(t.begin(), t.end());
    //     ans = max(ans, t);
    // }else {
    //     string t = string(rsz, '9');
    //     t[t.size() - 1] = r[0] - 1;
    //     ans = max(t, ans);
    // }
    
    // if (r[rsz - 2] > '0' && r.size() > 2) {
    //     string t = r;
    //     reverse(t.begin(), t.end());
    //     t[0] = '9';
    //     ans = max(ans, t);
    // }else {
    //     string t = r;
    //     reverse(t.begin(), t.end());
    //     int temp = r[0] - '0';
    //     temp--;
    //     cout << t[t.size() - 1] << '\n';
    //     cout << t << '\n';
    //     t[t.size() - 1] = 'temp';
    //     cout << t << '\n';
    //     ans = max(ans, t);
    // }

    cout << ans << '\n';
}   
    
int32_t main ()
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

/*
  /\_/\
 (= ._.)
 / >  \>
*/