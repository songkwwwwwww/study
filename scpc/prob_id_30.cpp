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


const int MAX_K = 5000;
int N, M, K;

int x_1[MAX_K], y_1[MAX_K];
int x_2[MAX_K], y_2[MAX_K];

int d[MAX_K];

int dfs(int here){
    // base case
    //if(here == K ) return 0;

    int& ret = d[here];
    if(ret != -1) return ret;

    ret = 1;
    for(int there = 0; there < K; there++){
        if(here == there) continue;
        if(x_1[here] <= x_1[there] &&  x_2[there] <= x_2[here] 
            && y_1[here] <= y_1[there] && y_2[there] <= y_2[here]){
            
            ret = max(ret, dfs(there) + 1);
        }
    }

    return ret;
}

int main(){
    freopen("prob_id_30.txt", "r", stdin);
    setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 0; i < K; i++)
            scanf("%d %d %d %d", &x_1[i], &y_1[i], &x_2[i], &y_2[i]);
        memset(d, -1, sizeof(d));
        int ans = 0;
        for(int i = 0; i < K; i++)
            ans = max(ans, dfs(i));

        printf("Case #%d\n%d\n", tc, ans);
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


const int MAX_K = 5000;
struct rectangle{
    int x1, y1, x2, y2;
} rectangles[MAX_K];

bool cmp(const rectangle& lhs, const rectangle& rhs){
    return lhs.x1 < rhs.x1;
}

int N, M, K;
//int x_1[MAX_K], y_1[MAX_K];
//int x_2[MAX_K], y_2[MAX_K];
int q[MAX_K];
int depth[MAX_K];

int main(){
    freopen("prob_id_30.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 0; i < K; i++)
            scanf("%d %d %d %d", &rectangles[i].x1, &rectangles[i].y1, &rectangles[i].x2, &rectangles[i].y2);

        //sort(rectangles, rectangles + K, cmp);
        vvi adj; adj.resize(K);
        vi in_degree; in_degree.resize(K);


        for(int i = 0; i < K; i++){
            adj[i].reserve(K/50);
            for(int j = 0; j < K; j++){
                //if(i == j) continue;
                //if(x_1[i] <= x_1[j] &&  x_2[j] <= x_2[i] && y_1[i] <= y_1[j] && y_2[j] <= y_2[i]){
                if(rectangles[i].x1 <= rectangles[j].x1 &&
                    rectangles[j].x2 <= rectangles[i].x2 && 
                    rectangles[i].y1 <= rectangles[j].y1 && 
                    rectangles[j].y2 <= rectangles[i].y2){
                    
                    adj[i].push_back(j);
                    in_degree[j]++;
                }
            }
        }

        int head = 0, tail = 0;
        //vi depth; depth.resize(K);
        for(int i = 0; i < K; i++){
            if(in_degree[i] == 0){
                q[tail++] = i;
                depth[i] = 1;
            }
        }
        int ans = 1;
        while(head < tail){
            int here = q[head++];
            ans = max(ans, depth[here]);

            for(int i = 0; i < adj[here].size(); i++){
                int there = adj[here][i];      
 
                in_degree[there]--;
                if(in_degree[there] == 0){
                    q[tail++] = there;
                    depth[there] = depth[here] + 1;
                }
            }
        }
        printf("Case #%d\n%d\n", tc, ans);
    }
}

*/