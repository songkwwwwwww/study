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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 1000;
int N;
vi a, d;
int solve(int cur){
    int& ret = d[cur + 1];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = cur + 1; next < N; next++){
        if(cur == -1 || a[cur] < a[next])
            ret = max(ret, solve(next) + 1);
    }
    return ret;
}

int main(){
    freopen("11568.txt", "r", stdin);
    scanf("%d", &N);
    a = vi(N);
    d = vi(N + 1, -1);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("%d\n", solve(-1) - 1);
}

/*
#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

int N; // 1 <= N <= 1000
int a[1001];
int d[1001];

int main(){
    freopen("11568.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
    int max_value = 1;
    for(int i = 1; i <= N; i++){
        d[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[j] < a[i] && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
                max_value = MAX(max_value, d[i]);
            }
        }
    }
    printf("%d\n", max_value);
}
*/