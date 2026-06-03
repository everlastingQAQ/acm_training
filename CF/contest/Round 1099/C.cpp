#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve ()
{
    int n;
    cin >> n;
    set <int> st;
    unordered_map <int, int, custom_hash> mp;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (i == 1) {
            st.insert(t);
            if (t == 1) {
                st.insert(t + 1);
                mp[2]++;
            }
            int cnt = 1;
            while (t != 1) {
                if (t & 1) {
                    t++;
                    st.insert(t);
                    mp[t] += cnt;
                }else {
                    t /= 2;
                    st.insert(t);
                    mp[t] += cnt;
                }
                cnt++;
            } 
        }else {
            unordered_map <int, int, custom_hash> mp1;
            if (t == 1) {
                mp1[1] = true;
                if (st.find(2) != st.end()) {
                    mp[2]++;
                }
                mp1[2] = true;
            }else {
                int cnt = 1;
                mp1[t] = true;
                while (t != 1) {
                    if (t & 1) {
                        t++;
                        if (st.find(t) != st.end()) mp[t] += cnt;
                    }else {
                        t /= 2;
                        if (st.find(t) != st.end()) mp[t] += cnt;
                    }
                    cnt++;
                    mp1[t] = true;
                } 
            }   
            for (auto x : st) {
                if (!mp1[x]) {
                    st.erase(st.find(x));
                }
            }
        }
    }

    int ans = 1e8;
    for (auto x : st) {
        ans = min(ans, mp[x]);
    }
    cout << ans << '\n';
}

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}
