#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
int N, R, X[MAX_N];

int main(){
	int ans = 0, pos = 0;
	cin >> N >> R;
	for(int i=0; i<N; i++){
		cin >> X[i];
	}
	sort(X, X + N);
	while(pos < N){
		//s是没有被覆盖的最左的点的位置
		int s = X[pos];
		//一直向右前进直到距s的距离大于R的点
		while(pos < N && X[pos] <= s + R)
			pos++;
		//p是新加上标记的点的位置
		int p = X[pos - 1];
		//一直向右前进直到距p的距离大于R的点
		while(pos < N && X[pos] <= p + R)
			pos++;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
