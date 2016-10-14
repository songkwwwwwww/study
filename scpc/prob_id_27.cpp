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



int main(){
    freopen("prob_id_27.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        int K, L, N, M;
        scanf("%d %d %d %d", &K, &L, &N, &M);
        vvb adj(N + 1, vb(N + 1));
        for(int u, v, i = 0; i < M; i++){
            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = true;
        }
        int V = N; // V는 현재 정점의 개수
        vb removed(N + 1);
        while(true){
            int i;
                // 각 정점(로봇)은 두 조건을 충족해야 한다.
                // 1) 각 정점은 K 개 이상의 로봇들과 통신을 해야한다
                //      -> 그렇기 때문에 K개 이하의 차수를 가지는 로봇은 제외되어야 한다.
                // 
                // 2) 어느 한 로봇이 바이러스가 걸렸을 시에도 L개 이상의 로봇이 살아남아야한다.
                //      -> 현재 남은 로봇의 개수가 V 라고 하고
                //         어떤 정점이 바이러스가 걸린다면 해당 정점 
                //         그리고 그 정점과 연결된 모든 정점에 바이러스를 전파한다.
                //         이 때 바이러스에 걸리는 수는 차수 + 1(자기 자신)인데
                //         L개 이상의 로봇이 살아 남아야 하므로 
                //         V - (degree + 1) >= L 을 만족시켜야 한다.
                //         이를 만족시키지 못하면 지운다.         
            for(i = 1; i <= N; i++){
                if(removed[i]) continue;
                // i 번 정점의 degree를 계산
                int degree = 0;
                for(int j = 1; j <= N; j++)
                    degree += adj[i][j];
                
                // 위 조건 1), 2)를 충족하지 못하면 정점을 지운다
                if(degree < K || (V - (degree + 1)) < L){
                    V--;
                    for(int j = 1; j <= N; j++){
                        adj[i][j] = adj[j][i] = false;
                    }
                    removed[i] = true;
                    // 처음부터 다시 계산한다.
                    break;
                }
            }
            // 모든 정점에 대해서 조사를 마쳤으면
            if(i == N + 1) break;
        }

        int ans = 0;
        for(int i = 1; i <= N; i++)
            if(removed[i])
                ans += i;
        printf("Case #%d\n%d\n", tc, ans);
    }
}