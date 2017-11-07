#include <iostream>

using namespace std;
const int MAX_N = 30;
int n, k, num[MAX_N];
//已经从前i项得到和sum，然后对于i项之后的进行分支
bool dfs(int i, int sum){
	//如果前n项都计算过了，则返回sum是否与k相等
	if(i == n)
		return sum == k;
	//不加上num[i]的情况
	if(dfs(i + 1, sum))
		return true;
	//加上num[i]的情况
	if(dfs(i + 1, sum + num[i]))
		return true;
	//无论是否加上num[i]都不能凑成k就返回false
	return false;
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> num[i];
	cin >> k;	
	if(dfs(0, 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
