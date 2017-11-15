//中国剩余定理
#include <iostream>
#include <algorithm>

using namespace std;
//最小公倍数23 * 28 * 33
const int LIMIT = 21252;

int r1, r2, r3;

void solve(){
	int i;
	for(i=1, r1 = 28 * 33; ; i++){
		if(r1 * i % 23 == 1)
			break;
	}
	r1 *= i;
	for(i=1, r2 = 23 * 33; ; i++){
		if(r2 * i % 28 == 1)
			break;
	}
	r2 *= i;
	for(i=1, r3 = 23 * 28; ; i++){
		if(r3 * i % 33 == 1)
			break;
	}
	r3 *= i;
	return;
}

int main(){
	int phy, emo, intel, date;
	int times = 0;
	solve();
	while(cin >> phy >> emo >> intel >> date){
		if(phy == -1 && emo == -1 && intel == -1 && date == -1)
			break;
		times++;
		int res = (r1 * phy + r2 * emo + intel * r3 - date + LIMIT) % LIMIT;
		if(res == 0)
			res = LIMIT;
		printf("Case %d: the next triple peak occurs in %d days.\n", times, res);
	}
	return 0;
}
