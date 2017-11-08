#include <iostream>

using namespace std;

const int MAX_N = 2010;
int N;
char str[MAX_N];

int main(){
	cin >> N;
	cin >> str;
	int begin = 0, end = N - 1;
	while(begin <= end){
		//将从左起和从右起的字符串比较
		bool left = false;
		for(int i=0; begin + i <= end; i++){
			if(str[begin + i] < str[end - i]){
				left = true;
				break;
			}
			else if(str[begin + i] > str[end - i]){
				left = false;
				break;
			}
		}
		if(left)
			cout << str[begin++];
		else
			cout << str[end--];
	}
	cout << endl;
	return 0;
}
