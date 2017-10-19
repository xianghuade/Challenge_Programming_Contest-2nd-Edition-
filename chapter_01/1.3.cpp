#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10e6;
int L, n, dis[MAX_N];

int main(){
	cin >> L >> n;
	for(int i=0; i<n; i++){
		cin >> dis[i];
	}
	int minT = 0, maxT = 0;
	//计算最短时间
	for(int i=0; i<n; i++){
		minT = max(minT, min(dis[i], L-dis[i]));
	}
	//计算最长时间
	for(int i=0; i<n; i++){
		maxT = max(maxT, max(dis[i], L-dis[i]));
	}
	cout << minT << " " << maxT << endl;
	return 0;
}