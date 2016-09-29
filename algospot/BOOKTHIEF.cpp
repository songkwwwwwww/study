// 못 푼 상태


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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
문제

책방에 책 도둑들이 들었다. 
책도둑들은 책방의 모든 책들을 크기와 값어치에 따라 N종류로 분류했다.
(한 종류의 책이 여러 권 있을 수 있다.) 
책도둑들이 준비한 자루의 크기가 V일 때, 최대로 가능한 훔칠 수 있는 값어치를 알아보자.

입력

첫 줄에는 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스마다 첫 줄에는 책의 종류 N(1 ≤ N ≤ 100)과 자루의 크기 V(1 ≤ V ≤ 10,000)이 주어진다. 
그 뒤 N개의 줄에는 각각 책 종류별 크기, 값어치, 개수를 나타내는 
세 개의 숫자 vi,ci,ki (1 ≤ vi ≤ V, 1 ≤ ci ≤ 10,000, 1 ≤ ki ≤ 10,000, 0 ≤ i < N, 단 1 ≤ vi* ki ≤ V)가 주어진다.

출력

각 테스트 케이스마다 훔칠 수 있는 최고 값어치를 출력한다.
*/


const int MAX_N = 100;
const int MAX_V = 10000;
int N, V;
int v[MAX_N + 1], c[MAX_N + 1], k[MAX_N + 1];
int d[MAX_N + 1][MAX_V + 1];

// D[N, V]
int solve(int index, int space){
    // base case
    if(index == N) return 0;

    int& ret = d[index][space];
    if(ret != -1) return ret;

    ret = 0;
    
    /*
    for(int i = 0; i <= k[index]; i++){
        priority_queue<int> pq;
        for(int _v = 0; v <= V; v +=)
        if(v[index] * i <= space){
            // x == V mod vi
            int x = space % v[index];
            // f(x) = D[N - 1, x] - x / v_i * c_i
            //int fx = solve(index + 1, x) - x / v[index] * c[index];
            int fv = solve(index + 1, space) - space / v[index] * c[index];
            pq.push(fv);
            if(pq.top() + v[index] * i < V){
                int fx = pq.top(); pq.pop();
                ret = fx + space/v[index] * c[index];
            }
            // D[N, V] = f(x) + V/v_i * c_i
            //ret = max(ret, solve(index + 1, space - v[index] * i) + c[index] * i);
        }
    }
    */
    return ret; 
}


int main(){
    freopen("BOOKTHIEF.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        int _N, _V;
        scanf("%d %d", &_N, &_V);
        memset(d, 0, sizeof(d));
        for(int i = 1; i <= _N; i++){
            scanf("%d %d %d", &v[i], &c[i], &k[i]);
        }
        for (int i = 1; i <= _N; i++) {
            for (int b = 0; b < v[i]; b++) {
                priority_queue<pii> PQ;
                for (int V = b; V <= _V; V += v[i]) {
                    // f(x) = D[N - 1, x] - x / v_i * c_i
                    int fv = d[i - 1][V] - V / v[i] * c[i];            
                    //1. f(V)값을 PQ에 넣는다.
                    PQ.push(make_pair(fv, V));

                    //2. PQ의 top인 x값이 V와 vi*ki를 넘게 차이나면 top을 제거한다
                    while (V - PQ.top().second > v[i] * k[i])
                        PQ.pop();

                    //3. PQ의 top인 f(x)값에 대해 D[N,V]=f(x)+V/vi*ci이다.
                    d[i][V] = PQ.top().first + V / v[i] * c[i];
                }
            }
        }
        printf("%d\n", d[_N][_V]);
        
        //printf("%d\n", solve(0, V));
    }
}