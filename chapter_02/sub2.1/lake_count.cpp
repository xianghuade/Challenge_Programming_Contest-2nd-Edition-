#include <iostream>

using namespace std;

const int MAX_N = 105;
int n, m;
char str[MAX_N][MAX_N];
int res = 0;
//现在的位置(x,y)
void dfs(int x, int y){
	//将现在的位置替换为“.”
	str[x][y] = '.';
	//循环遍历西东的8个方向
	for(int dx=-1; dx<=1; dx++)
		for(int dy=-1; dy<=1; dy++){
			//向x方向移动dx,向y方向移动dy，移动的结果为(nx, ny)
			int nx = x + dx;
			int ny = y + dy;
			//判断(nx, ny)是否在园子内，以及是否有积水
			if(0 <= nx && nx < n && 0 <= ny && ny < m && str[nx][ny] == 'W'){
				dfs(nx, ny);
			}
		}
	return;
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> str[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			//从有W的地方开始dfs
			if(str[i][j] == 'W'){
				dfs(i, j);
				res++;
			}
		}
	cout << res << endl;
	return 0;
}
