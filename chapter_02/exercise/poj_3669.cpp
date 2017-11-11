#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 400;//300时会错误，矩阵的最大行列数
const int MAX_M = 50000;//最大的数据数
const int INF = 100000000;
//输入
int n;
int data[MAX_N + 1][MAX_N + 1];
int dis[MAX_N + 1][MAX_N + 1];//存储到每个位置的距离
int X[MAX_M + 1], Y[MAX_M + 1], T[MAX_M + 1];
//四个方向的探索矩阵
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
typedef pair<int, int> P;

int bfs(){
	//最开始就结束
	if(data[0][0] == 0){
		return -1;
	}
	queue<P> que;
	que.push(P(0, 0));
	dis[0][0] = 0;
	while(que.size()){
		P p = que.front();
		que.pop();
		//找到安全的位置
		if(data[p.first][p.second] == INF){
			return dis[p.first][p.second];
		}
		//四个方向进行探索
		for(int i=0; i<4; i++){
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			//未越界并未被访问过
			if(0 <= nx && nx <= MAX_N && 0 <= ny && ny <= MAX_N && dis[nx][ny] == INF && (dis[p.first][p.second] + 1 < data[nx][ny])){
				que.push(P(nx, ny));
				dis[nx][ny] = dis[p.first][p.second] + 1;
			}
		}
	}
	return -1;
}

int main(){
	int x, y, t;
	//初始化工作
	for(int i=0; i<=MAX_N; i++){
		fill(data[i], data[i] + MAX_N, INF);
		fill(dis[i], dis[i] + MAX_N, INF);
	}
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d%d%d", &X[i], &Y[i], &T[i]);
	}
	for(int i=0; i<n; i++){
		data[X[i]][Y[i]] = min(data[X[i]][Y[i]], T[i]);
		for(int j=0; j<4; j++){
			int nx = X[i] + dx[j];
			int ny = Y[i] + dy[j];
			if(0 <= nx && nx <= MAX_N && 0 <= ny && ny <= MAX_N){
				data[nx][ny] = min(data[nx][ny], T[i]);
			}
		}
	}
	printf("%d\n", bfs());
	return 0;
}
