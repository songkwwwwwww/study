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
//#include <unordered_map> // c++11

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

typedef pair<int, int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int INF = 987654321;

/*
입력
입력의 첫 줄에 스카이 콩콩의 힘 A와 B, 그리고 동규의 현재위치 N, 주미의 현재 위치 M이 주어진다. 
(단, 2≤A,B≤30 이고  0≤N,M≤100,000)

출력
동규가 주미에게 도달하기 위한 최소한의 이동 횟수를 출력하라.
*/

const int MAX_A = 30;
const int MAX_B = 30;

const int MAX_N = 100000;
const int MAX_M = 100000;


int main(){
    freopen("12761.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int A, B, N, M;
    // 2 ≤ A, B ≤ 30 ,  0 ≤ N, M ≤ 100,000
    scanf("%d %d %d %d", &A, &B, &N, &M);
    qi q;
    q.push(N);
    vb visited(MAX_N + 1);
    vi dx; dx.reserve(6);
    dx.push_back(1); dx.push_back(-1); dx.push_back(A); dx.push_back(-A); dx.push_back(B); dx.push_back(-B);

    int step = 0;
    while(!q.empty()){
        int q_size = q.size();
        bool flag = false;
        for(int i = 0; i < q_size; i++){
            int here = q.front(); q.pop();
            visited[here] = true;
            if(here == M){
                flag = true;
                break;
            }
            
            for(int i = 0; i < 6; i++){
                int there = here + dx[i];
                if(0 <= there && there <= MAX_N && !visited[there]){
                    q.push(there);
                    visited[there] = true;
                }
            }
            int there = here * A;
            if(0 <= there && there <= MAX_N && !visited[there]){
                q.push(there);
                visited[there] = true;
            }
            there = here * B;
            if(0 <= there && there <= MAX_N && !visited[there]){
                q.push(there);
                visited[there] = true;
            }
        }
        if(flag) break;
        step++;
    }
    printf("%d\n", step);
}