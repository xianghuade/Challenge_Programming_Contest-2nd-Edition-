//dp[i + 1][j]表示用前i种数加和得到j时第i种数最多能剩多少个，不能加和得到的情况下为-1
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int n;
int a[MAX + 1], m[MAX + 1];
int k;
int dp[MAX + 1];

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i] >> m[i];
	cin >> k;
	memset(dp, -1, sizeof(dp[0]));
	dp[0] = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<=k; j++){
			if(dp[j] >= 0){
				dp[j] = m[i];
			}
			else if(j < a[i] || dp[j - a[i]] <= 0){
				dp[j] = -1;
			}
			else{
				dp[j] = dp[j - a[i]] - 1;
			}
		}
	}
	if(dp[k] >= 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
