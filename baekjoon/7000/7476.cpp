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
입력
두 수열의 정보는 각각 두 줄에 걸쳐서 주어지며, 
첫째 줄에는 수열의 길이 M이 주어진다. (1 ≤ M ≤ 500) 
다음 줄에는 M개의 정수 Ai (-231 ≤ Ai < 231)가 주어진다.

출력
첫째 줄에 최대 공통 증가 부분 수열의 길이를 출력하고, 둘째 줄에 그 부분 수열을 출력한다. 답이 여러가지인 경우에는 아무거나 출력한다.
*/


const int MAX_N = 500;
const int MAX_M = 500;
int N, M;
vi S, A;
vvi d;
/*
    S[index_S]
    A[index_A]
    에서의 최대 공통 증가 부분 수열의 길이를 리턴.
*/
int solve(int index_S, int index_A){
    if(index_S == N || index_A == M) return 0;

    int& ret = d[index_S][index_A];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = index_S + 1; i <= N - 1; i++){
        for(int j = index_A + 1; j <= M - 1; j++){
            if(S[index_S] == A[index_A] && S[index_S] < S[i] && A[index_A] < A[j]){
                if(ret < solve(i, j) + 1){
                    ret = solve(i, j) + 1;
                }
                //ret = max(ret, solve(i, j) + 1);
            }
            else{
                ret = max(ret, solve(i, j));
            }
        }
    }
    return ret;
}

int main(){
    freopen("7476.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    S.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &S[i]);
    scanf("%d", &M);
    A.resize(M);
    for(int i = 0; i < M; i++)
        scanf("%d", &A[i]);
    d = vvi(N, vi(M, -1));
    int result = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            result = max(result, solve(i, j));
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    printf("LCIS : %d\n", result);
}