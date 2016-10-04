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
                // 0  1  2  3
const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;
                // 3  2  1  0
const int INF = 987654321;

/*

*/

const int MAX_N = 1000;
const int MAX_M = 1000;

int N, M;
int m[MAX_N + 2][MAX_M + 2];

inline int change_direction(int type){
    return 3 - type;
}

inline bool is_range(int x, int y){
    if(1 <= x && x <= N && 1 <= y && y <= M)
        return true;
    else
        return false;
}

int main(){
    freopen("2344.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            scanf("%d", &m[i][j]);
    vector< pair<int, int> > start;
    start.reserve(2 * N + 2 * M);
    map<pair<int, int> , int> exit;
    int num = 1;
    for(int i = 1; i <= N; i++){
        start.push_back(make_pair(i, 0));
        exit[make_pair(i, 0)] = num++;
    }
    for(int i = 1; i <= M; i++){
        start.push_back(make_pair(N + 1, i));
        exit[make_pair(N + 1, i)] = num++;
    }
    for(int i = N; i >= 1; i--){
        start.push_back(make_pair(i, M + 1));
        exit[make_pair(i, M + 1)] = num++;
    }
    for(int i = M; i >= 1; i--){
        start.push_back(make_pair(0, i));
        exit[make_pair(0, i)] = num++;
    }
    for(int type, i = 0; i < start.size(); i++){
        int x = start[i].first;
        int y = start[i].second;
        // E W S N
        if(y == 0)
            type = 0;
        else if(y == M + 1)
            type = 1;
        else if(x == 0)
            type = 2;
        else if(x == N + 1)
            type = 3;
        x += dx[type];
        y += dy[type];
        while(is_range(x, y)){
            if(m[x][y] == 1)
                type = change_direction(type);
            x += dx[type];
            y += dy[type];
        }
        printf("%d ", exit[make_pair(x, y)]);
    }
}