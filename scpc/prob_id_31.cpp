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


const int MAX_N = 10000;
int p[MAX_N + 3];
int q[MAX_N + 3];
int d[MAX_N + 3];

int main(){
    freopen("prob_id_31.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        int N;
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
            scanf("%d", &p[i]);
        for(int i = 1; i <= N; i++)
            scanf("%d", &q[i]);
        // d[i] : 현재 i주까지 일을 끝마쳤을 때의 최대 수수료
        d[1] = max(p[1], q[1]);
        
        for(int i = 2; i <= N; i++){
            d[i] = max(d[i - 1] + p[i], d[i - 2] + q[i]);
        }
        printf("Case #%d\n%d\n", tc, d[N]);
    }
}