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

const int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1}; // E W S N;
const int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 10;
int N;
char m[5][6];
char str[MAX_N + 1];

inline bool is_range(int x, int y){
    if(0 <= x && x < 5 && 0 <= y && y < 5)
        return true;
    else
        return false;
}

int d[5][5][MAX_N + 1];

int solve(int x, int y, int index){
    // base case
    if(index == N - 1) return true;
    
    int& ret = d[x][y][index];
    if(ret != -1) return ret;

    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_range(nx, ny) && m[nx][ny] == str[index + 1] && solve(nx, ny, index + 1)){
            return ret = true;
        }
    }
    return ret = false;
}

int main(){
    freopen("BOGGLE.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        for(int i = 0; i < 5; i++)
            scanf("%s", m[i]);

        int n;
        scanf("%d", &n);
        for(int l = 0; l < n; l++){
            scanf("%s", str);
            memset(d, -1, sizeof(d));
            for(N = 0; str[N] != '\0'; N++);

            bool flag = false;
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    if(m[i][j] == str[0] && solve(i, j, 0)){
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) printf("%s YES\n", str);
            else printf("%s NO\n", str);
        }
    }
}