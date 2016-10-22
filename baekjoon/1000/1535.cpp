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

const int MAX_N = 20;
int N;
int L[MAX_N + 3];
int J[MAX_N + 3];

int d[MAX_N + 3][100 + 1];

int solve(int index, int health){
    // base case
    if(index == N){
        return 0;
    }

    int& ret = d[index][health];
    if(ret != -1) return ret;
    ret = 0;
    // 현재 사람은 무시하고 건너뛴다
    ret = max(ret, solve(index + 1, health));

    // 현재 사람에게 인사를 한다
    if(health - L[index] > 0)
    ret = max(ret, solve(index + 1, health - L[index]) + J[index]);

    return ret;
}


int main(){
    freopen("1535.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &L[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &J[i]);
    
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 100));
    
}