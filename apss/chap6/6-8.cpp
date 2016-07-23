#include <iostream>
#include <vector>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS + 1] = {
// 01234 56789 01234 5
	"xxx.............",	// SWITCH	0
	"...x...x.x.x....",	//		1
	"....x.....x...xx",	//		2
	"x...xxxx........",	//		3
	"......xxx.x.x...",	//		4

	"x.x...........xx",	//		5
	"...x..........xx",	//		6
	"....xx.x......xx",	//		7
	".xxxxx..........",	//		8
	"...xxx...x...x.."	//		9
};
bool areAligned(const vector<int>& clocks){
	for(auto it; it != clocks.end(); it++){
			
	}
}


void push(vector<int>& clocks, int swtch){
	for(int clock = 0; clock < CLOCKS; ++clock){
		if(linked[swtch][clock] == 'x'){
			clocks[clock] += 3;
			if(clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

int main(){
	int C;

	cin >> C;
	std::vector* v = new vector()
	for(int i = 0; i < C; i++){
		cin >> 
	}
}
