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

const int dx[4] = {-1, 0, 1, 0}; // N E S W;
const int dy[4] = {0, 1, 0, -1}; // N E S W;

const char d_char[4] = {'N', 'E', 'S', 'W'};
const int INF = 987654321;

/*

*/

const int MAX_N = 50;
const int MAX_M = 50;
int N, M;
char m[MAX_N][MAX_M];

bool visited[MAX_N][MAX_M][MAX_N][MAX_M];

void change_lexicographical_order(int& x1, int& y1, int& x2, int& y2){
    if(pii(x1, y1) > pii(x2, y2)){
        swap(x1, x2);
        swap(y1, y2);
    }
}

inline int get_hash_val(int x1, int y1, int x2, int y2){
    return x1 * 1000000 + y1 * 10000 + x2 * 100 + y2;
}

int main(){
    freopen("11451.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &N, &M);
        int p = 0, px[2], py[2];
        int prev[MAX_N][MAX_M][MAX_N][MAX_M];
        char prev_dir[MAX_N][MAX_M][MAX_N][MAX_M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                scanf(" %c", &m[i][j]);
                if(m[i][j] == 'P'){
                    m[i][j] = '.';
                    px[p] = i;
                    py[p] = j;
                    p++;
                }
            }
        }

        change_lexicographical_order(px[0], py[0], px[1], py[1]);
        int start = get_hash_val(px[0], py[0], px[1], py[1]);

        qi q;
        q.push(start);
        visited[px[0]][py[0]][px[1]][py[1]] = 0;
        bool flag = false;
        int finish = -1;

        while(!q.empty()){
            int here = q.front(); q.pop();
            int x1 = here / 1000000;
            int y1 = here % 1000000 / 10000;
            int x2 = here % 10000 / 100;
            int y2 = here % 100;

            if(x1 == x2 && y1 == y2){
                flag = true;
                finish = here;
                break;
            }

            for(int i = 0; i < 4; i++){
                int nx1 = (x1 + dx[i] + N) % N;
                int ny1 = (y1 + dy[i] + M) % M;
                int nx2 = (x2 + dx[i] + N) % N;
                int ny2 = (y2 + dy[i] + M) % M;

                if(m[nx1][ny1] == 'G' || m[nx2][ny2] == 'G') continue;

                if(m[nx1][ny1] == 'X'){
                    nx1 = x1;
                    ny1 = y1;
                }
                if(m[nx2][ny2] == 'X'){
                    nx2 = x2;
                    ny2 = y2;
                }
                change_lexicographical_order(nx1, ny1, nx2, ny2);
                if(visited[nx1][ny1][nx2][ny2]) continue;

                q.push(get_hash_val(nx1, ny1, nx2, ny2));
                visited[nx1][ny1][nx2][ny2] = true;
                prev[nx1][ny1][nx2][ny2] = here;
                prev_dir[nx1][ny1][nx2][ny2] = d_char[i];
            }
        }
        if(flag){
            vector<char> history;

            for(int cur = finish; cur != start;){
                int x1 = cur / 1000000;
                int y1 = cur % 1000000 / 10000;
                int x2 = cur % 10000 / 100;
                int y2 = cur % 100;

                history.push_back(prev_dir[x1][y1][x2][y2]);
                cur = prev[x1][y1][x2][y2];
            }
            int history_size = history.size();
            printf("%d ", history_size); 
            for(int i = history_size - 1; i >= 0; i--){
                printf("%c", history[i]);
            }
            printf("\n");
        }
        else{
            printf("IMPOSSIBLE\n");
        }
        memset(visited, 0, sizeof(visited));
    }
}