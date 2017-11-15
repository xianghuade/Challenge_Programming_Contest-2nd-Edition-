#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 110; 

int n, m;

struct node{
	char str[MAX_N + 1];
	int times;
};

struct node data[MAX_N + 1];

int cmp(const struct node &a, const struct node &b){
	return a.times < b.times;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> data[i].str;
	}
	for(int i=0; i<m; i++){
		data[i].times = 0;
		int count_a = 0, count_c = 0, count_g = 0, count_t = 0;
		for(int j=n-1; j>=0; j--){
			switch(data[i].str[j]){
				case 'A': count_a++; break;
				case 'C': count_c++; data[i].times += count_a; break;
				case 'G': count_g++; data[i].times += count_a + count_c; break;
				case 'T': count_t++; data[i].times += count_a + count_c + count_g; break;
			}
		}
	}
	sort(data, data + m, cmp);
	for(int i=0; i<m; i++){
		cout << data[i].str << endl;
	}
	return 0;
}
