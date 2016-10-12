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

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 100;
const int MAX_M = 10000000;
const int MAX_C = 100;

int N, M;
int m[MAX_N + 1];
int c[MAX_N + 1];
// d[i] : i 원으로 확보할 수 있는 최대 메모리의 수
int d[MAX_N * MAX_C + 1];
// 1 <= m_1, ... , m_N <= 1000 0000
// 0 <= c_1, ... , c_N <= 100

int main(){
    freopen("7579.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        scanf("%d", &m[i]);
    for(int i = 1; i <= N; i++)
        scanf("%d", &c[i]);
    
    for(int i = 1; i <= N; i++){
        for(int j = MAX_N * MAX_C; j >= c[i]; j--){
            d[j] = max(d[j], d[j - c[i]] + m[i]);
        }
    }
    int ans = INF;
    for(int i = 0; i <= MAX_N * MAX_C; i++){
        if(d[i] >= M){
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
}