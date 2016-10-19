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


const int MAX_N = 1000;
int N;
int a[MAX_N + 3];
int d[MAX_N + 3];


int solve(int index){
    // base case
    if(index < 0) return 0;

    int& ret = d[index];
    if(ret != -1) return ret;
    ret = 0;

    int min_val = a[index];
    int max_val = a[index];
    for(int k = index ; k >= 0; k--){
        // 같은 조 : [k, index]
        min_val = min(min_val, a[k]);
        max_val = max(max_val, a[k]);
        ret = max(ret, solve(k - 1) + max_val - min_val); 
    }

    return ret;
}

int main(){
    freopen("2229.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(N - 1));
}