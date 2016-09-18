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

const int dh[6] = {0, 0, 0, 0, 1, -1}; // E W S N F B;
const int dx[6] = {0, 0, 1, -1, 0, 0}; // E W S N F B;
const int dy[6] = {1, -1, 0, 0, 0, 0}; // E W S N F B;

const int INF = 987654321;

/*


입력
 

입력은 여러 개의 테스트 케이스로 이루어지며, 각 테스트 케이스는 세 개의 정수 L, R, C로 시작한다. 
L(1 ≤ L ≤ 30)은 상범 빌딩의 층 수이다. R(1 ≤ R ≤ 30)과 C(1 ≤ C ≤ 30)는 상범 빌딩의 한 층의 행과 열의 개수를 나타낸다.

그 다음 각 줄이 C개의 문자로 이루어진 R개의 행이 L번 주어진다. 각 문자는 상범 빌딩의 한 칸을 나타낸다. 
금으로 막혀있어 지나갈 수 없는 칸은 '#'으로 표현되고, 비어있는 칸은 '.'으로 표현된다. 
당신의 시작 지점은 'S'로 표현되고, 탈출할 수 있는 출구는 'E'로 표현된다. 
각 층 사이에는 빈 줄이 있으며, 입력의 끝은 L, R, C가 모두 0으로 표현된다.




출력


각 빌딩에 대해 한 줄씩 답을 출력한다. 만약 당신이 탈출할 수 있다면 다음과 같이 출력한다.

Escpaed in x minute(s).

여기서 x는 상범 빌딩을 탈출하는 데에 필요한 최단 시간이다.

만일 탈출이 불가능하다면, 다음과 같이 출력한다.

Trapped!
*/

const int MAX_L = 30;
const int MAX_R = 30;
const int MAX_C = 30;

char m[MAX_L][MAX_R][MAX_C];
int L, R, C;

inline bool is_range(int l, int r, int c){
    if(0 <= l && l < L && 0 <= r && r < R && 0 <= c && c < C)
        return true;
    else
        return false;
}

int main(){
    freopen("6593.txt", "r", stdin);
    while(scanf("%d %d %d", &L, &R, &C) && L != 0 && R !=0 && C != 0){
        int S, E;
        for(int i = 0; i < L; i++)
            for(int j = 0; j < R; j++)
                for(int k = 0; k < C; k++){
                    scanf(" %c", &m[i][j][k]);
                    if(m[i][j][k] == 'S'){
                        m[i][j][k] = '.';
                        S = i * R * C + j * C + k;
                    }
                    else if(m[i][j][k] == 'E'){
                        m[i][j][k] = '.';
                        E = i * R * C + j * C + k;                        
                    }
                }
        
        qi q;
        q.push(S);
        vb visited(L * R * C);
        visited[S] = true;
        int step = 0;
        bool flag = false;
        while(!q.empty()){
            int n = q.size();

            for(int i = 0; i < n; i++){
                int here = q.front(); q.pop();
                int l = here / ( R * C);
                int x = here % (R * C) / C;
                int y = here % (R * C) % C;
                if(here == E){
                    flag = true;
                    break;
                }
                for(int d = 0; d < 6; d++){
                    int nl = l + dh[d];
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    int there = nl * (R * C) + nx * C + ny;
                    if(is_range(nl, nx, ny) && !visited[there] && m[nl][nx][ny] != '#'){
                        q.push(there);
                        visited[there] = true;
                    }
                }
            }
            if(flag) break;
            step++;
        }
        if(flag) printf("Escaped in %d minute(s).\n", step);
        else printf("Trapped!\n");
        
    } // end of while
}



/*
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                printf("%s\n", m[i][j]);
            }
            printf("\n\n\n");
        }
        
        printf("==========\n");
*/