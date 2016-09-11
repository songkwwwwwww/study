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

const int MAX_N = 100;
const int MAX_M = 100;

int N;
int a[1000];
int d[1000];
int solve(int index){
    if(index >= N-1) return 0;
    
    int& ret = d[index];
    if(ret != -1) return ret;
    ret = INF; 
    
    for(int i = 1; i <= a[index]; i++){
        ret = min(ret, solve(index + i) + 1);
    }
    return ret;
}

int main(){
    freopen("11060.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    memset(d, -1, sizeof(d));
    int result = solve(0);
    if(result == INF) printf("-1\n");
    else printf("%d\n", result);
}