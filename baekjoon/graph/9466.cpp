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
입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
각 테스트 케이스의 첫 줄에는 학생의 수가 정수 n (2 ≤ n ≤ 100,000)으로 주어진다. 
각 테스트 케이스의 둘째 줄에는 선택된 학생들의 번호가 주어진다. 
(모든 학생들은 1부터 n까지 번호가 부여된다.)

출력
각 테스트 케이스마다 한 줄에 출력하고, 
각 줄에는 프로젝트 팀에 속하지 못한 학생들의 수를 나타내면 된다.
*/

int TC;
int n;
int S[100000];
bool visited[100000];
bool finished[100000];
int cnt;

int dfs(int start){
    visited[start] = true;
    int next = S[start];
    // 다음 정점이 방문된 적 없다면 방문한다.
    if(!visited[next]){
        dfs(next);
    }
    // 방문된 적이 있다면, 방문 작업이 끝났는지 finished 배열을 통해 확인한다.
    else{
        // 아직 방문 작업이 끝나지 않은 상태라면, 사이클이 만들어진다
        if(!finished[next]){
            for(int temp = next; temp != start; temp = S[temp]) cnt++;
            cnt++;
        }
    }
    finished[start] = true;
}

int main(){
    freopen("9466.txt", "r", stdin);
    scanf("%d", &TC);
    while(TC--){
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &S[i]);
            S[i]--;
        }
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i])
                dfs(i);
        }
        printf("%d\n", n - cnt);
    }
}