#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    string s;
    cin >> s;
    int sum = 0;
    vector <int> cnt(10, 0);
    for (char c : s) {
    	sum += c - '0';
    	cnt[c - '0']++;
    }

    for (int i = max(1, sum - 100); i <= sum; i++) {
		vector <int> num = cnt;
		vector <int> ans;
		bool ok = true;
		int t = i;

		while (t > 9) {
			ans.push_back(t);
			int sumt = 0;
			string ss = to_string(t);
			for (auto c : ss) {
				if (num[c - '0'] == 0) {
					ok = false;
					break;
				}
				num[c - '0']--;
				sumt += c - '0';			
			}
			if (!ok) break;
			t = sumt;
		}
		if (!ok) continue;

		if (num[t] == 0) continue;
		num[t]--;
		ans.push_back(t);

		string s0;
		int summ = 0;
		for (int j = 9; j >= 0; j--) {
			if (num[j] != 0) {
				for (int k = 0; k < num[j]; k++) {
					s0.push_back(char('0' + j));
				}
				summ += j * num[j];
			}
		}	

		if (summ == i || summ == 0) {
			if (!s0.empty() && s0[0] != 0) cout << s0;
			for (int ss : ans) {
				cout << ss;
			}
			cout << '\n';
			return;
		}
    }
} 

int main ()
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