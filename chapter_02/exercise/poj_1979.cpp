#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
//输入
int w, h;
int sx, sy;
int res;//存储结果
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};//移动方向
char data[MAX_N + 1][MAX_N + 1];

void dfs(int x, int y){
	data[x][y] = '#';//将可达位置变为不可达
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx && nx < h && 0 <= ny && ny < w && data[nx][ny] == '.' ){
			res++;
			dfs(nx, ny);
		}
	}
	return;
}
int main(){
	while(cin >> w >> h){
		if(w == 0 && h == 0)
			break;
		for(int i=0; i<h; i++){
			cin >> data[i];
		}
		bool flag = false;
		res = 0;
		//获取起始位置坐标
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(data[i][j] == '@'){
					sx = i;
					sy = j;
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}
	dfs(sx, sy);
	//包括起始的@符号
	cout << ++res << endl;
	}
	return 0;
}
