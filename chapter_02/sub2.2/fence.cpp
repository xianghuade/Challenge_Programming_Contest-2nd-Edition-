#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 20000;
//输入
int N, L[MAX_N];

int main(){
	ll ans = 0;
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> L[i];
	//直到计算到木板为1块时为止
	while(N > 1){
		//求出最短的板mii1和次短的板mii2
		int mii1 = 0, mii2 = 1;
		if(L[mii1] > L[mii2])
			swap(mii1, mii2);
		for(int i=2; i<N; i++){
			if(L[i] < L[mii1]){
				mii2 = mii1;
				mii1 = i;
			}
			else if(L[i] < L[mii2]){
				mii2 = i;
			}
		}
		//将两块板合并
		int t = L[mii1] + L[mii2];
		ans += t;
		
		if(mii1 == N - 1)
			swap(mii1, mii2);
		L[mii1] = t;
		L[mii2] = L[N - 1];
		N--;
		/*sort(L, L + N);
		int temp = L[0] + L[1];
		ans += temp;
		int pos = 0;
		for(int i=2; i<N; i++){
			L[pos++] = L[i];	
		}
		L[pos] = temp;
		N--;*/
	}
	cout << ans << endl;
	return 0;
}
