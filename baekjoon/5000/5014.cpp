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

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*
문제
강호는 코딩 교육을 하는 스타트업 스타트링크에 지원했다. 
오늘은 강호의 면접날이다. 
하지만, 늦잠을 잔 강호는 스타트링크가 있는 건물에 늦게 도착하고 말았다.

스타트링크는 총 F층으로 이루어진 고층 건물에 사무실이 있고, 스타트링크가 있는 곳의 위치는 G층이다. 
강호가 지금 있는 곳은 S층이고, 이제 엘리베이터를 타고 G층으로 이동하려고 한다.

보통 엘리베이터에는 어떤 층으로 이동할 수 있는 버튼이 있지만, 강호가 탄 엘리베이터는 버튼이 2개밖에 없다. 
U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼이다. 
(만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다)

강호가 G층에 도착하려면, 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오. 
만약, 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력한다.

입력
첫째 줄에 F, S, G, U, D가 주어진다. 
(1 ≤ S, G ≤ F ≤ 100,0000, 0 ≤ U, D ≤ 100,0000) 
건물은 1층부터 시작하고, 가장 높은 층은 F층이다.

출력
첫째 줄에 강호가 S층에서 G층으로 가기 위해 눌러야 하는 버튼의 수의 최소값을 출력한다. 
만약, 엘리베이터로 이동할 수 없을 때는 "use the stairs"를 출력한다.
*/

int F, S, G, U, D;

inline bool is_safe(int level){
    if(1 <= level && level <= 1000000)
        return true;
    else
        return false;
}

int dfs(int start, int end){
    queue<int> q;
    vector<int> dist(F + 1, -1);
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();
        if(here == end) return dist[end] - dist[start];
        // up
        int there = here + U;
        if(is_safe(there) && dist[there] == -1){
            q.push(there);
            dist[there] = dist[here] + 1;
        }
        // down
        there = here - D;
        if(is_safe(there) && dist[there] == -1){
            q.push(there);
            dist[there] = dist[here] + 1;
        }
    }
    return -1;
}

int main(){
    freopen("5014.txt", "r", stdin);
    //                      10   1  10   2   1
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    int ans = dfs(S, G);
    if(ans != -1) printf("%d\n", ans);
    else printf("use the stairs\n");
}