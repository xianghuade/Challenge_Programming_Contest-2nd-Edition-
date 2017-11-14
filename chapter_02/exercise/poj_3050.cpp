#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_N = 5;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int num[MAX_N + 1][MAX_N + 1];
//set容器中的元素值是唯一的
set<int> st;

void dfs(int x, int y, int times, int sum){
	if(times == 6){
		st.insert(sum);
		return;
	}
	for(int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx && nx < MAX_N && 0 <= ny && ny < MAX_N){
			times++;
			dfs(nx, ny, times, (int)(sum * 10 + num[nx][ny]));
			times--;
		}
	}
	return;
}

int main(){
	for(int i=0; i<MAX_N; i++)
		for(int j=0; j<MAX_N; j++)
			cin >> num[i][j];
	for(int i=0; i<MAX_N; i++){
		for(int j=0; j<MAX_N; j++){
			dfs(i, j, 1, num[i][j]);
		}
	}
	cout << st.size() << endl;
	return 0;
}
