//枚举1~n的所有排列，直到有一种排列使得最后的结果为sum就结束
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int sum;
int digit[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void solve(){
	sort(digit, digit + 10);
	do{
		int temp[10];
		int tempn = n;
		//不能改变digit[]中的值，用temp[]代替
		for(int i=0; i<tempn; i++){
			temp[i] = digit[i];
		}
		//模拟加的过程，共几次加循环，每次循环加几次
		for(int i=0; i<tempn-1; i++){
			int tempm = tempn - i - 1;
			for(int j=0; j<tempm; j++){
				temp[j] += temp[j + 1];	
			}
		}
		//满足条件退出
		if(temp[0] == sum)
			break;
	}while(next_permutation(digit, digit + 10));
	for(int i=0; i<n; i++){
		cout << digit[i];
		if(i == n - 1)
			cout << endl;
		else
			cout << ' ';
	}
}
int main(){
	while(cin >> n >> sum){
		solve();
	}
	return 0;
}

