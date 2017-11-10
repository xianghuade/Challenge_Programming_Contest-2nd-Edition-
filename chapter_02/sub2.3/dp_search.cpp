#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_N + 1];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> w[i] >> v[i];
	}
	cin >> W;
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<=W; j++){
			if(j < w[i]){
				dp[i][j] = dp[i + 1][j];
			}
			else{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[0][W] << endl;
	return 0;
}
