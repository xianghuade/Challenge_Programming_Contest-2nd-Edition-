#include <iostream>
#include <algorithm>

using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6];
int A;

int main(){
	int ans = 0;
	for(int i=0; i<6; i++){
		cin >> C[i];
	}
	cin >> A;
	//优先使用面值大的硬币
	for(int i=5; i>=0; i--){
		int temp = min(A / V[i], C[i]);//使用硬币i的枚数
		ans += temp;
		A -= temp * V[i];
	}
	cout << ans << endl;
	return 0;
}
