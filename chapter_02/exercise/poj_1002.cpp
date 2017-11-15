#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int n;
char str[128];
map<int, int> mp;
map<int, int>::iterator start, end; 
//英文字符/数字映射
const int num[] = {
	2, 2, 2, 3, 3, 3,
	4, 4, 4, 5, 5, 5,
	6, 6, 6, 7, 0, 7,
	7, 8, 8, 8, 9, 9,
	9, 0
};

int main(){
	//标识变量
	bool flag = false;
	int hash;
	cin >> n;
	for(int i=0; i<n; i++){
		hash = 0;
		cin >> str;
		//计算字符串对应的整数值，作为map的关键字
		for(int j=0; str[j]; j++){
			if(isdigit(str[j])){
				hash = hash * 10 + str[j] - '0';	
			}
			else if(isalpha(str[j])){
				hash = hash * 10 + num[str[j] - 'A'];
			}
		}
		//相同的关键字个数加一
		mp[hash]++;
	}
	for(start = mp.begin(), end = mp.end(); start != end; start++){
		if(start->second > 1){
			flag = true;
			//格式化输出
			printf("%03d-%04d %d\n", start->first / 10000, start->first % 10000, start->second);
		}
	}
	if(!flag)
		printf("No duplicates.\n");
	return 0;
}
