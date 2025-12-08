#include <bits/stdc++.h>
int main(){
	std::string s;
	std::cin >> s;
	int x,y = 0;

	std::map<std::pair<int,int>,int> cnt;
	for(int i = 0;i < s.size();i++){
		if(s[i] == 'U'){
			y++;
		}else if(s[i] == 'D'){
			y--;
		}else if(s[i] == 'L'){
			x--;
		}else if(s[i] == 'R'){
			y++;
		}
		if(cnt[{x,y}] == 0){
			cnt[{x,y}]++;
		}else{
			std::cout << "BUG\n";
			return 0;
		}
	}
	std::cout << "OK\n";
	// for(auto i:cnt){
	// 		cout << i.first.first << ' ' << i.first.second << '\n';
	// 	}
}