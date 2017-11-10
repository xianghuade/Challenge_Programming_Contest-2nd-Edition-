#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_W = 100000;
const int MAX_N = 100;
int n, W;
int w[MAX_N], v[MAX_N];
int zero_dp[MAX_W + 1], full_dp[MAX_W + 1];
//0/1背包解决方法
void solve1(){
	for(int i=0; i<n; i++){
		for(int j=W; j>=w[i]; j--){
			zero_dp[j] = max(zero_dp[j], zero_dp[j - w[i]] + v[i]);
		}
	}
	cout << zero_dp[W] << endl;
}
//完全背包解决方法
void solve2(){
	for(int i=0; i<n; i++){
		for(int j=w[i]; j<=W; j++){
			full_dp[j] = max(full_dp[j], full_dp[j - w[i]] + v[i]);
		}
	}
	cout << full_dp[W] << endl;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> w[i] >> v[i];
	cin >> W;
	solve1();
	solve2();
	return 0;
}
