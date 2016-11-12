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

const int dx[2] = {0, 1}; // E S;
const int dy[2] = {1, 0}; // E S;

const int INF = 987654321;

/*

*/


const int MAX_N = 50;
int N;
char m[MAX_N][MAX_N + 1];

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

int get_max(){
    int ret = 0;

    // 행을 검사
    for(int i = 0; i < N; i++){
        int cnt = 1;
        for(int j = 1; j < N; j++){
            if(m[i][j - 1] == m[i][j]){
                cnt++;
                ret = max(ret, cnt);
            }
            else{
                cnt = 1;
            }
        }
    }

    // 열을 검사
    for(int j = 0; j < N; j++){
        int cnt = 1;
        for(int i = 1; i < N; i++){
            if(m[i - 1][j] == m[i][j]){
                cnt++;
                ret = max(ret, cnt);
            }
            else{
                cnt = 1;
            }
        }
    }


    return ret;
}

int main(){
    freopen("3085.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s", m[i]);
    int ans = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){

            for(int d = 0; d < 2; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(is_range(nx, ny)){
                    swap(m[x][y], m[nx][ny]); 
                    int temp = get_max();
                    if(ans < temp)
                        ans = temp;
                    swap(m[x][y], m[nx][ny]); 
                }
            }
        }
    }
    printf("%d\n", ans);
}