#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 25000;
pair<int, int> itv[MAX_N + 1];
int N, T;
//按开始时间从小到大排序，若开始时间相等则按结束时间从大到小排序
bool cmp(const pair <int, int> a , const pair <int, int> b){
	return a.first < b.first || (a.first == b.first && a.second > b.second);
}

int solve(){
	int used_cows = 0;
	int end = 0;
	int index = 0;
	while(end < T){
		int begin = end + 1;
		//寻找一头既能从begin干起，又能一直干到最远的牛
		for(int i=index; i<N; i++){
			if(itv[i].first <= begin){
				//能够覆盖起始点
				if(itv[i].second >= begin){
					end = max(end, itv[i].second);
				}
			}
			else{
				//不能覆盖起始点，说明上一头牛的终点就是最远点，需要换一头牛
				index = i;
				break;
			}
		}
		//没找到这样的牛，该case失败
		if(begin > end){
			return -1;
		}
		else{
			++used_cows;
		}	
	}
	return used_cows;
}
int main(){
	cin >> N >> T;
	for(int i=0; i<N; i++){
		cin >> itv[i].first >> itv[i].second;
	}
	sort(itv, itv + N, cmp);	
	cout << solve() << endl;
	return 0;
}
