#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;


const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

// linked[i][j] = 'x' : i번 스위치와 j번 시계가 연결되어 있다.
// linked[i][j] = '.' : i번 스위치와 j번 시계가 연결되어 있지 않다.
 
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

// 모든 시계가 12시를 가리키고 있는지 확인한다.
bool areAligned(const vector<int>& clocks){
    for(int clock = 0; clock < CLOCKS; ++clock){
        if(clocks[clock] != 12) return false;
    }
    return true;
}

// switch번 스위치를 누른다.
void push(vector<int>& clocks, int swtch){
	for(int clock = 0; clock < CLOCKS; ++clock){
		if(linked[swtch][clock] == 'x'){
			clocks[clock] += 3;
			if(clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

// clocks : 현재 시계들의 상태.
// swtch : 이번에 누를 스위치의 번호
// 가 주어질 때, 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수를 반환.
// 만약 불가능하다면 INF 이상의 큰 수를 반환한다.
int solve(vector<int>& clocks, int swtch){
    if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
    // 이 스위치를 0 번 누르는 경우부터 세 번 누르는 경우까지를 모두 시도한다.
    int ret = INF;
    for(int cnt = 0; cnt < 4; cnt++){
        ret = min(ret, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    return ret;
}

/*

*/
int main(){
    freopen("CLOCKSYNC.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        vector<int> clocks(16);
        for(int i = 0; i < 16; i++) cin >> clocks[i]; 
        //scanf("%d", &clocks[i]);
        int result = solve(clocks, 0);
        if(result == INF) printf("-1\n");
        else printf("%d\n", result);
    }
}