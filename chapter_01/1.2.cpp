#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;

int main(){
	int n, num[MAX_N];
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> num[i];
	}
	
	int ans = 0;
	//让i < j < k, 这样棍子就不会被重复选中了
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				int len = num[i] + num[j] + num[k];//周长
				int ma = max(num[i], max(num[j], num[k]));//剩余棍子的长度
				int rest = len - ma;//其余两根棍子的长度之和
				if(ma < rest){
					//可以组成三角形，如果可以更新答案则更新
					ans = max(ans, len);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}