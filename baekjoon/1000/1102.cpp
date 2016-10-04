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

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/

const int MAX_N = 16;
int N, P, cnt;


int w[MAX_N][MAX_N];
int d[1<<16];

int solve(int state){
    int& ret = d[state];
    if(ret != -1) return ret;
    if(cnt >= P) return ret = 0;

    ret = INF;
    cnt++;
    for(int i = 0; i < N; i++){
        if(state & (1 << i)){
            for(int j = 0; j < N; j++){
                if(!(state & (1 << j))){
                    ret = min(ret, solve(state | (1 << j)) + w[i][j]);
                }
            }
        }
    }
    cnt--;
    return ret;
}

int main(){
    freopen("1102.txt", "r", stdin);
    scanf("%d", &N);
    int state = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &w[i][j]);
    char c;
    for(int i = 0; i < N; i++){
        scanf(" %c", &c);
        if(c == 'Y'){
            cnt++;
            state |= (1 << i);
        }
    }
    scanf("%d", &P);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(state));
}