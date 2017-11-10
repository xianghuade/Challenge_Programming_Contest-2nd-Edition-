#include <iostream>

using namespace std;

const int MAX_N = 1000;
int n, m;
char stra[MAX_N + 1], strb[MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1];

int main(){
	cin >> n >> m;
	cin >> stra >> strb;
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(stra[i] == strb[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else{
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
