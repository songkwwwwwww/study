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

const int MAX_N = 50;
const int MAX_M = 50;

int N, M;
char m[MAX_N][MAX_M + 1];

inline bool is_range(int x, int y){
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    else
        return false;
}

int main(){
    freopen("2589.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%s", m[i]);
    //for(int i = 0; i < N; i++)
    //    printf("%s\n", m[i]);
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(m[i][j] == 'L'){
                vvb visited(N, vb(M));
                visited[i][j] = true;
                queue< pair<int, int> > q;
                q.push(make_pair(i, j));
                int count = 0;
                while(!q.empty()){
                    int size = q.size();
                    count++;                    

                    for(int k = 0; k < size; k++){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(int d = 0; d < 4; d++){
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            if(is_range(nx, ny) && m[nx][ny] == 'L' && !visited[nx][ny]){
                                visited[nx][ny] = true;
                                q.push(make_pair(nx, ny));
                            }       
                        }
                    }
                }
                ans = max(ans, count-1);                
            }
        }
    }
    printf("%d\n", ans);
}