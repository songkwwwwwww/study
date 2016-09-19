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
const int MOD = 1000000009;
/*

*/

const int MAX_N = 50000;
const int MAX_K = 100;

int TC; // [1, 15]
int N; // [1, 50000]
int K; // [1, 100]
int L; // [0, N / 2]

bool has_mine[MAX_N + 1];
int d[MAX_N + 1][MAX_K + 1];
int s[MAX_N + 1];


int main(){
    freopen("prob_id_26.txt", "r", stdin);
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d %d %d", &N, &K, &L);
        for(int index, i = 0; i < L; i++){
            scanf("%d", &index);
            has_mine[index] = true;
        }
        s[0] = d[0][0] = 1;
        for(int i = 1; i <= N; i++){
            s[i] = 0;
            if(has_mine[i]) continue;

            for(int j = 1; j <= K && j <= i; j++){
                d[i][j] = (s[i - j] + MOD - d[i - j][j] ) % MOD;
                s[i] = (s[i] + d[i][j]) % MOD;
            }
        }

        printf("Case #%d\n%d\n", tc, s[N]);
        memset(d, 0, sizeof(d));
        memset(has_mine, false, sizeof(has_mine));
    }
}


/*
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
const int MOD = 1000000009;


const int MAX_N = 50000;
const int MAX_K = 100;

int TC; // [1, 15]
int N; // [1, 50000]
int K; // [1, 100]
int L; // [0, N / 2]

bool has_boom[MAX_N / 2 + 1];
int d[MAX_N + 1][MAX_K + 1];

int solve(int cur, int last){
    if(cur >= N) return 1;

    int& ret = d[cur][last];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 1; i <= K; i++){
        if(!has_boom[cur + i] && i != last && cur + i <= N)
            ret += solve(cur + i, i) % MOD;
    }
    return ret;
}

int main(){
    freopen("prob_id_26.txt", "r", stdin);
    scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d %d %d", &N, &K, &L);
        for(int index, i = 0; i < L; i++){
            scanf("%d", &index);
            has_boom[index] = true;
        }
        memset(d, -1, sizeof(d));
        printf("Case #%d\n%d\n", tc, solve(0, 0));
        memset(has_boom, false, sizeof(has_boom));
    }
}
*/