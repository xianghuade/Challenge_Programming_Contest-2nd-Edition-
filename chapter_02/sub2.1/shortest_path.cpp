#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 105;
const int INF = 10000000;
int n, m;
int sx, sy;//起点坐标
int gx, gy;//终点坐标
int d[MAX_N][MAX_N];//到各个位置的最短距离的数组
char maze[MAX_N][MAX_N];//表示迷宫的字符串的数组

typedef pair<int, int> P;//使用pair表示状态时，使用typedef会更加方便一些
//4个方向移动的向量
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> maze[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			//寻找起始点坐标
			if(maze[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			//寻找终止点坐标
			if(maze[i][j] == 'G'){
				gx = i;
				gy = j;
			}
			//将所有的位置都初始化为INF
			d[i][j] = INF;
		}
	}
	queue<P> que;
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	
	while(que.size() != 0){
		P p = que.front();
		que.pop();
		//如果取出的状态已经是重点，则结束搜索
		if(p.first == gx && p.second == gy)
			break;
		for(int i=0; i<4; i++){
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			//判断是否可以移动以及是否已经访问
			if(0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && d[nx][ny] == INF){
				//可以移动则加入队列，并将到该位置的距离确定为到p的距离+1
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	cout << d[gx][gy] << endl;
	return 0;
}
