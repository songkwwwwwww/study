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

*/


const int MAX_M = 700;
const int MAX_N = 1000000;


int main(){
    freopen("10836.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int M, N;
    scanf("%d %d", &M, &N);
    vvi m(M, vi(M, 1));
    vi line(2* M - 1);
    int zero_count, one_count, two_count;
    for(int i = 0; i < N; i++){
        int p = 0;
        scanf("%d %d %d", &zero_count, &one_count, &two_count);
        p = p + zero_count;
        for(int j = 0; j < one_count; j++){
            line[p++] += 1;
        }
        for(int j = 0; j < two_count; j++){
            line[p++] += 2;                
        }
    }
    int p = 0;
    for(int i = M - 1; i >= 0; i--){
        m[i][0] += line[p++];
    }
    for(int j = 1; j < M; j++){
        m[0][j] += line[p++];
    }
    for(int i = 1; i < M; i++){
        for(int j = 1; j < M; j++){
            m[i][j] = max( m[i-1][j-1], max(m[i][j-1], m[i-1][j]) );
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            printf("%d%c", m[i][j], j == M-1 ? '\n' : ' ');
        }
    }
}