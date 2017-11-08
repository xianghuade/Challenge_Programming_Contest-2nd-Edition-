#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
//输入
int N, S[MAX_N], T[MAX_N];
//用于对工作排序的pair数组
pair<int, int> itv[MAX_N];
//贪心规则：在可选工作中，每次选择结束时间最早的工作
int main(){
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> S[i];
	for(int i=0; i<N; i++)
		cin >> T[i];
	//对pair进行的是字典序比较
	//为了让结束时间早的工作排在前面，把T存入first，把S存入second
	for(int i=0; i<N; i++){
		itv[i].first = T[i];
		itv[i].second = S[i];
	}
	sort(itv, itv + N);
	//t是最后所选工作的结束时间
	int ans = 0, t = 0;
	for(int i=0; i<N; i++){
		if(t < itv[i].second){
			ans++;
			t = itv[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}
