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
int m[MAX_N][MAX_M];

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
} 

int main(){
    freopen("7576.txt", "r", stdin);
    scanf("%d %d", &M, &N);
    queue< pair<int, int> > q;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            scanf("%d", &m[i][j]);
            if(m[i][j] == 1)
                q.push(make_pair(i, j));
        }
    int count = 0;
    while(!q.empty()){
        count++;
        int n = q.size();
        for(int i = 0; i < n; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int j = 0; j < 4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(is_range(nx, ny) && m[nx][ny] == 0){
                    q.push(make_pair(nx, ny));
                    m[nx][ny] = 1; 
                }
            }
        }
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(m[i][j] == 0){
                printf("-1\n");
                return 0;
            }

    printf("%d\n", count - 1);
}