//改变dp对象，定义dp[i + 1][j]为前i个物品中挑选出价值总和为j时总重量的最小值，不存在则为INF
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
const int MAX_V = 100;
const int INF = 0x3f3f3f3f;
int W[MAX_N + 1], V[MAX_N + 1];
int dp[MAX_N + 1][MAX_N * MAX_V + 1];
int n, w;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> W[i] >> V[i];
	}
	cin >> w;
	//初始化
	fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
	dp[0][0] = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<=MAX_N * MAX_V; j++){
			if(j < V[i])
				dp[i + 1][j] = dp[i][j];
			else
				dp[i + 1][j] = min(dp[i][j], dp[i][j - V[i]] + W[i]);
		}
	}
	int res = 0;
	for(int i=0; i<=MAX_N * MAX_V; i++){
		if(dp[n][i] <= w)
			res = i;
	}
	cout << res << endl;
	return 0;
}
