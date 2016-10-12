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


const int MAX_N = 100;
const int MAX_M = 100;
int N, M;
char m[MAX_N][MAX_M + 1];
char str[27];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < M);
}

int main(){
    freopen("9328.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        vb keys(26);
        scanf("%d %d", &N, &M);
        vvb visited(N, vb(M));

        for(int i = 0; i < N; i++)
            scanf("%s", m[i]);

        scanf("%s", str);
        if(str[0] != '0')
            for(int i = 0; str[i]; i++){
                keys[str[i] - 'a'] = true;
            }

        queue< pair<int, int> > q;
        // 네 방향에서 시작점을 찾아본다.
        // 왼쪽 | 과 오른쪽 |
        for(int i = 0; i < N; i++){
            if(m[i][0] != '*'){
                visited[i][0] = true;
                q.push(make_pair(i, 0));
            }
            if(m[i][M - 1] != '*'){
                visited[i][M - 1] = true;
                q.push(make_pair(i, M - 1));
            }
        }
        // 위 - 와 아래 _
        for(int j = 1; j < M - 1; j++){
            if(m[0][j] != '*'){
                visited[0][j] = true;
                q.push(make_pair(0, j));
            }
            if(m[N - 1][j] != '*'){
                visited[N - 1][j] = true;
                q.push(make_pair(N - 1, j));
            }
        }
        int ans = 0;
        queue< pair<int, int> > waiting_q[26];
        //printf("q size : %d\n", (int)q.size());
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // 해당 지점이 문인가?
            if('A' <= m[x][y] && m[x][y] <= 'Z'){
                int n = m[x][y] - 'A';
                // 열쇠가 있다면
                if(keys[n])
                    m[x][y] = '.';
                // 없다면 대기큐에 넣는다
                else{
                    waiting_q[n].push(make_pair(x, y));
                    continue;
                }
            }
            // 해당 지점이 열쇠인가?
            else if('a' <= m[x][y] && m[x][y] <= 'z'){
                int n = m[x][y] - 'a';
                keys[n] = true;
                // 가진 열쇠로 열 수 있는 문을 연다
                while(!waiting_q[n].empty()){
                    q.push(waiting_q[n].front());
                    waiting_q[n].pop();
                }
                m[x][y] = '.';
            }
            else if(m[x][y] == '$'){
                ans++;
                m[x][y] = '.';
            }

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(is_range(nx, ny) && !visited[nx][ny] && m[nx][ny] != '*'){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
        printf("%d\n", ans);
    }// end of while
}