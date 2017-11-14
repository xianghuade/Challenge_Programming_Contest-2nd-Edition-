#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int res;
int cnt;
int num[10];

int solve(){
	int num1, num2;
	do{
		num1 = 0, num2 = 0;
		//第一个数的首位不能是0或第二个数的首位不能是0
		//当输入为10时，要么第一个数为0，要么第二个数为0
		if(!num[0] || !num[cnt / 2] && cnt > 2)
			continue;
		//第一个整数转化
		for(int i=0; i<cnt / 2; i++)
			num1 = num1 * 10 + num[i];
		//第二个整数转化
		for(int i=cnt / 2; i<cnt; i++)
			num2 = num2 * 10 + num[i];
		//更新最小值
		res = min(res, abs(num1 - num2));
	}while(next_permutation(num, num + cnt));
	return res;
}

int main(){
	char str[100];
	cin >> n;
	getchar();//读取输入n后的回车符
	while(n--){
		cnt = 0;
		res = 0x3f3f3f3f;//结果初始化为一个较大值
		gets(str);
		//将字符数组转化为整型数组
		for(int i=0; i<strlen(str); i++){
			if(str[i] >= '0' && str[i] <= '9'){
				num[cnt++] = str[i] - '0';
			}
		}
		cout << solve() << endl;
	}
	return 0;
}
