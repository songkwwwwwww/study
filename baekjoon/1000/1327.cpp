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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
첫째 줄에 순열의 크기 N과 K가 주어진다. 
N은 2보다 크거나 같고, 8보다 작거나 같다. 
둘째 줄에 순열에 들어가는 수가 주어진다.

출력
첫째 줄에 정답을 출력한다. 
만약 오름차순으로 만들 수 없으면 -1을 출력한다.
*/
int N, K;

int bfs(const vector<int>& perm){
    vector<int> sorted = perm;
    sort(sorted.begin(), sorted.end());

    queue<vector<int> > q;
    map<vector<int>, int> dist;

    q.push(perm);
    dist[perm] = 0;
int count = 0;
    while(!q.empty()){
        vector<int> here = q.front(); q.pop();
        if(here == sorted) return dist[here];
        int cost = dist[here];

        for(int i = 0; i < N - K  + 1; i++){
            reverse(here.begin() + i, here.begin() + i + K);
            if(dist.count(here) == 0){
                dist[here] = cost + 1;
                q.push(here);
            }
            reverse(here.begin() + i, here.begin() + i + K);
        }
    }
    return -1;
}

int main(){
    freopen("1327.txt", "r", stdin);
    scanf("%d %d", &N, &K);
    vector<int> v(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);
        
    printf("%d\n", bfs(v));
}