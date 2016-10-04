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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MAX_N = 1000;
const int MAX_M = 1000;
int N, M;
int len[MAX_N];
int d[MAX_N][MAX_M];

/*
    적어야 할 이름이 word_index번째 이름이고
    현재 col번 열에 있을 때
    현재 행부터 발생하는 공백의 합의 최소 값 반환
*/
int solve(int word_index, int col){
    // base case
    if(word_index == N) return 0;
    if(col >= M) return solve(word_index + 1, len[word_index] + 1) + (col == M ? 1 : 0);
    // col < M
    int& ret = d[word_index][col];
    if(ret != -1) return ret;

    ret = solve(word_index + 1, len[word_index] + 1) + (M - col + 1) * (M - col + 1);
    if(col + len[word_index] <= M) ret = min(ret, solve(word_index + 1, col + len[word_index] + 1));
    return ret;
}

int main(){
    freopen("2281.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &len[i]);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 0));
    //printf("%d\n", solve(1, len[0] + 1));
}