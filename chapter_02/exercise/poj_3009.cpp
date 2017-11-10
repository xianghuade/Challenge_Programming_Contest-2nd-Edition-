#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
const int MAX = 1 << 30;
//输入
int row, col;
int data[MAX_N + 1][MAX_N + 1];
int sx, sy;//起点坐标
int gx, gy;//终点坐标
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};//移动方向
int res;
void dfs(int x, int y, int steps){
	if(steps >= 10)//如果超过10步，则返回
		return;
	//往四个方向探索
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		//若是障碍
		if(data[nx][ny] == 1)
			continue;
		//一直走到不是0的地方
		while(!data[nx][ny]){
			nx += dx[i];
			ny += dy[i];
		}
		//未越界
		if(0 <= nx && nx < row && 0 <= ny && ny < col){
			//在障碍物上，去除障碍，后退一步搜索
			if(data[nx][ny] == 1){
				data[nx][ny] = 0;
				dfs(nx - dx[i], ny - dy[i], steps + 1);
				data[nx][ny] = 1;//回溯需要恢复障碍物
			}
			//到达目的地，修改res值
			if(data[nx][ny] == 3){
				if(steps + 1 < res){
					res = steps + 1;
				}
			}
		}
	}
}
int main(){
	while(cin >> col >> row){
		if(row == 0 && col == 0)
			break;
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++){
				cin >> data[i][j];
				if(data[i][j] == 2){
					data[i][j] = 0;//将起点坐标置为0
					sx = i;
					sy = j;
				}
				if(data[i][j] == 3){
					gx = i;
					gy = j;
				}
			}
		res = MAX;
		dfs(sx, sy, 0);
		if(res < MAX)
			cout << res << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}
