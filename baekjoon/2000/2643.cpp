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


const int MAX_N = 100;
int N;

struct point{
    int x, y;
};

inline bool is_range(int x, int y){
    return (0 <= x && x < N && 0 <= y && y < N);
}

point p[MAX_N + 3];
int d[MAX_N + 3];
bool visited[MAX_N + 3];

// 
int solve(int index){
    int& ret = d[index];
    if(ret != -1) return ret;
    
    ret = 1;
    visited[index] = true;

    for(int i = 0; i < N; i++){
        if(!visited[i] && ( (p[i].x <= p[index].x && p[i].y <= p[index].y) || (p[i].x <= p[index].y && p[i].y <= p[index].x) ) ){

            ret = max(ret, 1 + solve(i));
        }
    }
    visited[index] = false;
    return ret;
}
int main(){
    freopen("2643.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    memset(d, -1, sizeof(d));
    int ans = -INF;
    for(int i = 0; i < N; i++)
        ans = max(ans, solve(i));
    printf("%d\n", ans);
}