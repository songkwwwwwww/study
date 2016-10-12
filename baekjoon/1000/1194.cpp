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
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

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


const int MAX_N = 50;
const int MAX_M = 50;
int N, M;
char m[MAX_N][MAX_M];
bool visited[1 << 6][MAX_N][MAX_M];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

struct point{
    int key, x, y;
    point(){}
    point(int nkey, int nx, int ny):key(nkey), x(nx), y(ny){}
};

int main(){
    freopen("1194.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int s_x, s_y;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %c", &m[i][j]);
            if(m[i][j] == '0'){
                s_x = i;
                s_y = j;
            }
        }
    }
    visited[0][s_x][s_y] = true;
    queue< point > q;
    q.push((point){0, s_x, s_y});
    bool flag = false;
    int ans = 0;
    while(!q.empty()){
        int size = q.size();
        for(int s = 0; s < size; s++){
            int key = q.front().key;
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            if(m[x][y] == '1'){
                flag = true;
                break;
            }

            for(int i = 0; i < 4; i++){
                int nkey = key;
                int nx = x + dx[i];
                int ny = y + dy[i];

                // 다음 이동 장소가 범위를 벗어났거나 벽이면 이동할 수 없다.
                if(!is_range(nx, ny) || m[nx][ny] == '#') 
                    continue;
                
                // 소문자(열쇠가 있는 곳)이면 열쇠를 집는다.
                else if('a' <= m[nx][ny] && m[nx][ny] <= 'z') 
                    nkey |= (1 << (m[nx][ny] - 'a'));

                // 대문자(문이 있는 곳)일 경우에 열쇠가 없다면 갈 수 없다.
                else if('A' <= m[nx][ny] && m[nx][ny] <= 'Z')
                    if( !(nkey & (1 << (m[nx][ny] - 'A'))) )
                        continue;
                
                if(visited[nkey][nx][ny]) continue;

                q.push((point){nkey, nx, ny});
                visited[nkey][nx][ny] = true;
            }
        }
        if(flag) break;
        ans++;
    } // end of while q
    if(!flag) printf("-1\n");
    else printf("%d\n", ans);
}