//最长上升子序列
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
int n;
int num[MAX_N + 1];
int dp[MAX_N + 1];

int main(){
	int res = 0;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> num[i];
	for(int i=0; i<n; i++){
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(num[j] < num[i]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}
	cout << res << endl;
	return 0;
}
