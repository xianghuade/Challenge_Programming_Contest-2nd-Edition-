#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
//输入
int n, W;
int w[MAX_N], v[MAX_N];
//记忆化数组
int dp[MAX_N + 1][MAX_N + 1];

int rec(int i, int j){
	if(dp[i][j] >= 0)
		//已经计算过的话直接使用之前的结果
		return dp[i][j];
	int res;
	if(i == n)
		res = 0;
	else if(j < w[i])
		res = rec(i + 1, j);
	else{
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	//将结果记录在数组中
	return dp[i][j] = res;
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> w[i] >> v[i];
	}
	cin >> W;
	//用-1表示尚未计算过，初始化整个数组
	memset(dp, -1, sizeof(dp));
	cout << rec(0, W) << endl;
	return 0;
}
