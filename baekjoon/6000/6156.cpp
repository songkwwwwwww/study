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
N (1 <= N <= 100) cows, conveniently numbered 1..N, are participating in a programming contest. As we all know, some cows code better than others. Each cow has a certain constant skill rating that is unique among the competitors.

The contest is conducted in several head-to-head rounds, each between two cows. If cow A has a greater skill level than cow B (1 <= A <= N; 1 <= B <= N; A != B), then cow A will always beat cow B.

Farmer John is trying to rank the cows by skill level. Given a list the results of M (1 <= M <= 4,500) two-cow rounds, determine the number of cows whose ranks can be precisely determined from the results. It is guaranteed that the results of the rounds will not be contradictory.

입력
Line 1: Two space-separated integers: N and M
Lines 2..M+1: Each line contains two space-separated integers that describe the competitors and results 
(the first integer, A, is the winner) of a single round of competition: A and B
출력
Line 1: A single integer representing the number of cows whose ranks can be determined
*/


const int MAX_N = 100;
const int MAX_M = 4500;
int N, M;

int main(){
    freopen("6156.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    vvb adj(N, vb(N));
    for(int u, v, i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        adj[u - 1][v - 1] = true;
    }
    for(int i = 0; i < N; i++) adj[i][i] = true;
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(adj[i][k] && adj[k][j])
                    adj[i][j] = true;                
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        bool flag = true;
        for(int j = 0; j < N && flag; j++){
            flag &= (adj[i][j] || adj[j][i]);
        }
        if(flag)
            ans++;
    }
    printf("%d\n", ans);
}