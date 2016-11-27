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


const int MAX_N = 1024;
const int MAX_M = 100000;
int N, M;
int m[MAX_N + 3][MAX_N + 3];
int p_s[MAX_N + 3][MAX_N + 3];

int main(){
    freopen("11660.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &m[i][j]);
            p_s[i][j] = p_s[i][j - 1] + p_s[i - 1][j]
                - p_s[i - 1][j - 1] + m[i][j];
        }
    }
    int x1, y1, x2, y2, ans;    
    for(int i = 1; i <= M; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        ans = p_s[x2][y2] - p_s[x1 - 1][y2] - p_s[x2][y1 - 1] + p_s[x1 - 1][y1 - 1];
        printf("%d\n", ans);
    }
}