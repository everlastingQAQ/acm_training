#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    ll ans = 0;
    string t;
    for(char ch : s){
        if(ch=='4')
            ans++;
        else
            t += ch;
    }
    int n = t.length();
    if(n==0)
        return cout << ans << endl, void();
    t = ' ' + t;

    vector<int> pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 2; i <= n;i++){
        pre[i] = pre[i - 1];
        int val = t[i - 1] - '0';
        if(val&1)
            pre[i]++;
    }

    for (int i = n - 1; i >= 1;i--){
        suf[i] = suf[i + 1];
        suf[i] += t[i + 1] == '2';
    }

    int minn = 1e9 + 7;
    for (int i = 1; i <= n;i++){
        // cout << suf[i] << ' ' << pre[i] << endl;
        minn = min(minn, suf[i] + pre[i]);
    }
    cout << ans + minn << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
}