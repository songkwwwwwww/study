#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <stack>
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

#include <map>
#include <utility> // std::pair

#include <functional> // greater, less
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
첫 줄에 도시의 수 N이 주어진다. N은 200이하이다. 
둘째 줄에 여행 계획에 속한 도시들의 수 M이 주어진다. 
M은 1000이하이다. 
다음 N * N 행렬을 통해 임의의 두 도시가 연결되었는지에 관한 정보가 주어진다. 
1이면 연결된 것이고 0이면 연결이 되지 않은 것이다. 
A와 B가 연결되었으면 B와 A도 연결되어 있다. 
마지막 줄에는 여행 계획이 주어진다.

출력
첫 줄에 가능하면 YES 불가능하면 NO를 출력한다.
*/

int N, M;
int p[200];
int itinerary[2000];


// recursive-find
int Find(int x){
	if(x == p[x]){ // x == parent[x]
		return x;
	}
	else{
		return p[x] = Find(p[x]);
	}
}

int Union(int x, int y){
	x = Find(x);
	y = Find(y);
	p[y] = x;
}

int main(){
    freopen("1976.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) p[i] = i;

    int n;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &n);
            if(n == 1)
                Union(i, j);
        }
    }

    for(int i = 0; i < M; i++){
        scanf("%d", &n);
        itinerary[i] = n - 1;
    }
    
    bool flag = false;
    for(int i = 1; i < M; i++){
        if(Find(itinerary[i - 1]) != Find(itinerary[i])){
            flag = true;
            break;
        }
    }

    if(!flag) printf("YES\n");
    else printf("NO\n");
}