#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 105;
const int INF = 10000000;
int n, m;
int sx, sy;
int gx, gy;
int d[MAX_N][MAX_N];
char maze[MAX_N][MAX_N];

typedef pair<int, int> P;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> maze[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(maze[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			if(maze[i][j] == 'G'){
				gx = i;
				gy = j;
			}
			d[i][j] = INF;
		}
	}
	queue<P> que;
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	
	while(que.size() != 0){
		P p = que.front();
		que.pop();
		if(p.first == gx && p.second == gy)
			break;
		for(int i=0; i<4; i++){
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if(0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && d[nx][ny] == INF){
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	cout << d[gx][gy] << endl;
	return 0;
}
